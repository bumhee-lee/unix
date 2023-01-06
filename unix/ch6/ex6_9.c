#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	int status;
	pid_t pid;

	if((pid=fork())<0){
		perror("fork");
		exit(1);
	}

	if(pid==0){
		printf("--> child process\n");
		sleep(3);
		exit(3);
	}

	printf("--> parent process\n");

	while(waitpid(pid, &status,WUNTRACED)==0){
		printf("parent still wait...\n");
		sleep(1);
	}

	printf("child exit status : %d\n", status>>8);

	return 0;
}
