#include<sys/types.h>
#include<signal.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char **argv){
	key_t key;
	char buf[1024];
	void *shmaddr;
	int shmid;

	key=ftok("shmfile",1);
	shmid=shmget(key, 1024,0);

	shmaddr=shmat(shmid,NULL,0);
	strcpy(shmaddr, "Hello im talker\n");

	kill(atoi(argv[1]),SIGUSR1);
	sleep(2);
	strcpy(buf,shmaddr);

	printf("listener said: %s\n", buf);
	system("ipcs -mo");
	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}
