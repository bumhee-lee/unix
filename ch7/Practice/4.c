#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void handler(int signo){
	psignal(signo,"signal:");
	sleep(2);
	printf("after handler\n");
}


int main(void){
	struct sigaction act;

	act.sa_flags=SA_RESETHAND;
	act.sa_handler=handler;

	if(sigaction(SIGQUIT, &act, (struct sigaction *)NULL)<0){
		perror("sigaction");
		exit(1);
	}

	fprintf(stderr,"insert SIGQUIT:");
	pause();
	printf("after handler\n");

	return 0;
}





