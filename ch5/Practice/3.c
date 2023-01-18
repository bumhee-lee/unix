#include<stdio.h>
#include<sys/types.h>
#include<sys/times.h>
#include<unistd.h>
#include<stdlib.h>


int main(void){
	struct tms mytms;
	clock_t t1 ,t2;

	if((t1=times(&mytms))==-1){
		perror("times");
		exit(1);
	}
	sleep(5);

	if((t2=times(&mytms))==-1){
		perror("times");
		exit(1);
	}

	printf("real time : %.lf sec\n", (double)(t2-t1) /CLK_TCK);
	return 0;
}
