#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

void handler(int signo){
	printf("Wake up\n");
}

int main(void){
	sigset_t set;
	sigfillset(&set);
	sigdelset(&set, SIGINT);
	//sigdelset(&set, SIGALRM);
	sigset(SIGALRM, handler);
	sigprocmask(SIG_BLOCK, &set, (sigset_t *)NULL);
	

	while(1){
		alarm(1);
		sleep(1);
	}

	return 0;
}
