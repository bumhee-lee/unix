#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


void handler(int signo){
	printf("signal number:%d\n", signo);
	sleep(2);
	printf("In signal handler, after sleep\n");
}

int main(void){
	if(sigset(SIGINT, handler)==SIG_ERR){
		perror("sigset");
		exit(1);
	}

	fprintf(stderr,"enter SIGINT:");
	pause();
	printf("after handler\n");


	return 0;
}
