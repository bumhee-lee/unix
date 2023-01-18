#include<unistd.h>
#include<stdio.h>

int main(void){
	printf("PID :%d\n", (int)getpid());
	printf("PGRP: %d\n", (int)getpgrp());
	printf("PGID: %d\n", (int)getpgid(0));
	printf("PGID(2287) : %d\n", (int)getpgid(2489));

	return 0;
}
