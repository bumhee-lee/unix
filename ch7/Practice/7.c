#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<signal.h>

void handler(int signo){
	printf("timer invoked!\n");
}

int main(void){
	struct itimerval it;

	sigset(SIGPROF, handler);

	it.it_interval.tv_sec=1;
	it.it_interval.tv_usec=0;
	it.it_value.tv_sec=1;
	it.it_value.tv_usec=0;


	setitimer(ITIMER_PROF,&it, (struct itimerval *)NULL);

	while(1){
		getitimer(ITIMER_PROF, &it);
	}

	return 0;
}
