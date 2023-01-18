#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(void){

	key_t key;
	char *shmaddr,buf[1024];
	int shmid,i;

	key=ftok("shmfile",1);
	shmid=shmget(key,1024,0);
	shmaddr=shmat(shmid,  NULL, 0);
	
	for(i=0;i<10;i++){
		strcpy(buf,"BOOK");
		strcat(shmaddr,buf);
		fprintf(stderr,"shmbuf:%s\n",shmaddr);
		sleep(1);
	}
	
	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
