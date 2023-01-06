#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	pid_t pid;
	char *argv[2];
	argv[0]="who";
	argv[1]=NULL;

	switch(pid=fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			if(execv("/usr/bin/who",argv)==-1){
					perror("execv");
					exit(1);
			}
			exit(0);
			break;
		default:
			printf("parent process\n");
			break;
	}

	return 0;
}

