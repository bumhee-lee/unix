#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){

	pid_t pid;

	switch(pid=fork()){
		case-1:
			perror("fork");
			exit(1);
			break;
		case 0:
			system("who");
			exit(0);
			break;
		default:
			system("date");
			break;
	}

	return 0;
}

