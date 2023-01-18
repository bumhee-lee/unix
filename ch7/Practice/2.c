#include<signal.h>
#include<stdio.h>

int main(void){
	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set,SIGQUIT);
	sigaddset(&set, SIGILL);
	sigaddset(&set, SIGTRAP);

	if(sigismember(&set, SIGPOLL)){
		printf("SIGOLL is checked!\n");
	}
	else{
		printf("SIGOLL isn't checked!\n");
	}

	printf("%x %x %x %x\n", set.__sigbits[3], set.__sigbits[2], set.__sigbits[1], set.__sigbits[0]);

	printf("SIGOLL is %d\n",(int)SIGPOLL);

	return 0;
}
