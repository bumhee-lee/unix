#include<errno.h>
#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;

};

int initsem(key_t semkey){
	union semun semunarg;
	int status=0, semid;

	semid = semget(semkey, 1, IPC_CREAT| IPC_EXCL | 0600);
	if(semid==-1){
		if(errno==EEXIST)
			semid=semget(semkey, 1,0);
	}
	else{
		semunarg.val=1;
		status=semctl(semid,0,SETVAL,semunarg);
	}
	if(semid==-1||status==-1){
		perror("inisem");
		return -1;
	}

	return semid;
}

int semlock(int semid){
	struct sembuf buf;
	buf.sem_num=0;
	buf.sem_op=-1;
	buf.sem_flg=SEM_UNDO;
	if(semop(semid, &buf,1)==-1){
		perror("semlock filed");
		exit(1);
	}

	return 0;
}

int semunlock(int semid){
	struct sembuf buf;
	buf.sem_num=0;
	buf.sem_op=1;
	buf.sem_flg=SEM_UNDO;
	if(semop(semid, &buf, 1)==-1){
		perror("semunlock failed\n");
		exit(1);
	}
	return 0;
}

void semhandle(int c){
	int shmid,i;
	char *shmaddr, buf[1024];
	key_t key;
	int semid;
	key=ftok("shmfile",1);
	shmid=shmget(key,1024,0);
	shmaddr=shmat(shmid, NULL,0);
	pid_t pid = getpid();
	if((semid=initsem(1))<0)
		exit(1);

	semlock(semid);
	printf("Lock : Process %d\n", (int)pid);
	printf("**Lock mode: Critical section\n");
	if(c==1){
		for(i=0;i<10;i++){
			strcat(shmaddr,"HANBIT\n");
			sleep(1);
		}
		fprintf(stderr,shmaddr);
	}
	else if(c==2){
		for(i=0;i<10;i++){
			strcat(shmaddr,"BOOK\n");
			sleep(1);
		}
		fprintf(stderr,shmaddr);
	}
	sleep(1);

	printf("Unlock : Process %d\n", (int)pid);
	semunlock(semid);
	shmdt(shmaddr);
	exit(0);
}

int main(void){
	int a;
	key_t key;
	int shmid;
	key=ftok("shmfile",1);
	shmid=shmget(key,1024,IPC_CREAT|0666);

	for(a=0;a<2;a++){
		if(fork()==0){
			semhandle(a+1);
		}
		sleep(1);
	}
		
	shmctl(shmid, IPC_RMID, 0);
	return 0;
}
