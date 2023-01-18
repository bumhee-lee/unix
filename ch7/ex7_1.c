#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<stdio.h>

int main(void){
	printf("Before SIGCONT Signal to parent.\n");

	kill(getppid(), SIGCONT);

	printf("Before SIGQUIT signal to me.\n");

	kill(getpid(), SIGQUIT);

	printf("After SIGQUIT Signal.\n");

	return 0;
}
