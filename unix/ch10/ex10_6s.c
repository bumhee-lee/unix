#include<sys/types.h>
#include<sys/mman.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

//handler do nothing
void handler(int dummy){
	;
}

int main(void){
	key_t key; //shm key
	int shmid;
	void *shmaddr;
	char buf[1024]; //equal with shmaddr
	sigset_t mask;

	//creat key
	key=ftok("shmfile",1);
	//creat shmid
	shmid = shmget(key,1024,IPC_CREAT|0666);

	//sig mask setting 
	sigfillset(&mask);
	sigdelset(&mask, SIGUSR1);
	sigset(SIGUSR1, handler);

	//wait signal
	printf("Listener wait for Talker\n");
	sigsuspend(&mask);

	//get shm and strcpy to buf and writing
	("Listener Start ====\n");
	shmaddr=shmat(shmid, NULL, 0);
	strcpy(buf, shmaddr);
	printf("Listener received: %s\n",buf);

	strcpy(shmaddr, "Have a nice day\n");
	sleep(3);
	shmdt(shmaddr);

	return 0;
}


