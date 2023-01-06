#include<sys/types.h>
#include<sys/times.h>
#include<limits.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void){
	int i;
	time_t t;
	struct tms mytms;
	clock_t t1, t2;

	if((t1=times(&mytms))==-1){
		perror("times 1");
		exit(1);
	}

	for(i=0;i<999999;i++)
		time(&t);

	if((t2 = times(&mytms))==-1){
		perror("times 2");
		exit(1);
	}
	printf("clk_tck : %d\n", CLK_TCK);
	printf("Real time : %.lf sec\n", (double)(t2-t1) / CLK_TCK);
	printf("User time : %.lf sec\n", (double)mytms.tms_utime/CLK_TCK);
	printf("System time : %.lf sec\n", (double)mytms.tms_stime /CLK_TCK);

	return 0;
}
