#include<time.h>
#include<stdio.h>

int main(void){
	struct tm tm;
	time_t t;

	time(&t);
	printf("Current Time(sec) : %d\n", (int)t);

	tm.tm_year = 122;
	tm.tm_mon = 9;
	tm.tm_mday=19;
	tm.tm_hour = 14;
	tm.tm_min=22;
	tm.tm_sec=0;

	t=mktime(&tm);
	printf("2022/10/19 14:22:00 Time(sec) : %d\n", (int)t);

	return 0;
}
