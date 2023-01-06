#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int main(void){

	pid_t pid1,pid2;

	switch(pid1=fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			pid2=fork();
			if(pid2==0){
				printf("child child process's pid:%d\n", getpid());
				printf("child child process's ppid:%d\n",getppid());
			}
			else{
				printf("child process's pid: %d\n", pid2);
				printf("child process's ppid:%d\n", getppid());
			}
			exit(0);
			break;
		default:
			printf("child process pid:%d\n", pid1);
			printf("parent pid : %d\n", getpid());
			break;
	}
	return 0;
}
