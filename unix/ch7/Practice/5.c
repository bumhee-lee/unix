#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, (sigset_t *)NULL);


	while(1){
		printf("Hanbit books\n");
		sleep(1);
	}

	return 0;
}
