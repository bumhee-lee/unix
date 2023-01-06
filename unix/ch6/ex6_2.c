#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	pid_t pid;

	switch(pid=fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("child process - my pid:%d, my parent's pid:%d", (int)getpid(),(int)getppid());
			break;
		default:
			printf("parent process - my pid:%d, my parent's pid:%d, ""my child's pid:%d\n", (int)getpid(), (int)getppid(), (int)pid);
			break;
	}

	printf("END of fork\n");
	return 0;
}

