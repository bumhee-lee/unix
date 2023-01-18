#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){
	extern char *optarg;
	extern int optind;
	int n;
	time_t t;
	struct tm *tm;
	char *wday[7]={"sunday","monday", "thuesday", "wednesday", "thursday", "friday", "saturday"};
	time(&t);
	tm=localtime(&t);
	//printf("pre codedone\n");

	while((n=getopt(argc,argv,"aymdwh"))!=-1){
		switch(n){
			case 'a':
				printf("%dy %dm %dd %s %dh %dm %ds\n",tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, wday[tm->tm_wday],tm->tm_hour,tm->tm_min, tm->tm_sec);
				break;
			case 'y':
				printf("%dy\n",tm->tm_year+1900);
				break;
			case 'm':
				printf("%dm\n",tm->tm_mon+1);
				break;
			case 'd':
				printf("%dd\n",tm->tm_mday);
				break;
			case 'w':
				printf("%s\n", wday[tm->tm_wday]);
				break;
			case 'h':
				printf("%dh %dm %ds\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
				break;
		}
		//printf("while in\n");
	}

	return 0;
}

