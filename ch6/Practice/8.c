#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	int status;

	switch(pid=fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			if(execl("/usr/bin/who","who",(char *)NULL)==-1){
					perror("execl");
					exit(1);
			}
			exit(0);
			break;
		default:
			waitpid(pid, &status, WCONTINUED);
			printf("parent process\n");
			break;
	}

	return 0;
}

