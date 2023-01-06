#include<stdio.h>
#include<signal.h>
#include<siginfo.h>
#include<stdlib.h>
#include<unistd.h>


void handler(int signo)
{
	psignal(signo, "Received Signal: ");
	sleep(5);
	printf("In signal handler, after sleep\n");
}
int main(void)
{
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_flags=SA_NODEFER;
	act.sa_handler=handler;


	sigaction(SIGINT, &act, (struct sigaction *)NULL);

	fprintf(stderr, "INput SIGINT:");
	pause();
	fprintf(stderr, "after signal handler\n");

	return 0;
}

