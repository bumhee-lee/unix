#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
	int maxlen_loginname = sysconf(_SC_LOGNAME_MAX);
	
	printf("maxlen:%u\n", maxlen_loginname);
	printf("inserted:%d\n", strlen(argv[1]));

	return 0;
}
