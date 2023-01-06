#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	int shmid, i; //share memory id, index
	char *shmaddr, *shmaddr2; //share memory 1,2

	//get share memory
	shmid = shmget(IPC_PRIVATE, 20, IPC_CREAT|0644);
	if(shmid==-1){
		perror("shmget");
		exit(1);
	}

	switch(fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			//connect shmid memory
			shmaddr=(char *)shmat(shmid, (char *)NULL, 0);
			printf("Child Process =====\n");
			for(i=0;i<10;i++)
				shmaddr[i]='a'+i;
			//release shmaddr
			shmdt((char *)shmaddr);
			exit(0);
			break;
		default:
			//wait child process end
			wait(0);
			//connect shmid memory
			shmaddr2=(char *)shmat(shmid, (char *)NULL, 0);
			printf("Parent Process ====\n");
			for(i=0;i<10;i++)
				printf("%c ",shmaddr2[i]);
			printf("\n");
			sleep(5);
			//release shmaddr2
			shmdt((char *)shmaddr2);
			//delete shmid
			shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL);
			break;
	}
	return 0;
}
