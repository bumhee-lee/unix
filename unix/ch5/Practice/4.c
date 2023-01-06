#include<sys/times.h>
#include<limits.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>

int main(void){
	struct tms mytms;
	clock_t t1, t2;

	int sum=0;

	if((t1=times(&mytms))==-1){
		perror("times");
		exit(1);
	}

	for(int i=0;i<100000;i++){
		sum+=i;
	}

	if((t2=times(&mytms))==-1){
		perror("times");
		exit(1);
	}

	printf("time : %.3lf\n", (double)(t2-t1)/CLK_TCK);
	printf("sum : %d\n", sum);

	return 0;
}
