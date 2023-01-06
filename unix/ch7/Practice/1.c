#include<signal.h>
#include<stdio.h>

int main(void){
	sigset_t set;
	sigfillset(&set);
	if(sigismember(&set, SIGBUS)){
		printf("SIGBUS checked!\n");

	}

	return 0;
}
