#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<signal.h>

int main(int argc, char **argv){
	key_t key;
	int shmid;
	void *shmaddr;
	char buf[1024];

	key=ftok("shmfile",1);
	shmid=shmget(key,1024,0);

	shmaddr=shmat(shmid, NULL, 0);
	
	while(1){
		fprintf(stderr,"insert: ");
		fgets(buf,1024,stdin);
		if(strcmp(buf,"q\n")==0)
			break;
		else{
			strcpy(shmaddr,buf);
			kill(atoi(argv[1]), SIGUSR1);
			sleep(1);
		}
	}

	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}

