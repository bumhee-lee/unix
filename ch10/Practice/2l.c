#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<signal.h>

void handler(int dummy){
	;
}

int main(void){
	key_t key;
	int shmid;
	void *shmaddr;
	char buf[1024];
	sigset_t mask;

	key=ftok("shmfile",1);
	shmid=shmget(key,1024,IPC_CREAT|0666);

	sigfillset(&mask);
	sigdelset(&mask,SIGUSR1);
	sigset(SIGUSR1, handler);


	printf("Listener start =====\n");

	shmaddr=shmat(shmid, NULL, 0);

	while(1){
		sigsuspend(&mask);
		strcpy(buf, shmaddr);
		if(strcmp(buf,"q\n")==0)
			break;
		else
			fprintf(stderr,"Msg: %s",buf);
	}

	shmdt(shmaddr);
	return 0;
}
