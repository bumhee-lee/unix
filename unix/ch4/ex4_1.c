#include<sys/utsname.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	struct utsname uts;
	
	if(uname(&uts)==-1){
		perror("unmae");
		exit(1);
	}

	printf("OSname : %s\n", uts.sysname);
	printf("NodeName: %s\n", uts.nodename);
	printf("Release : %s\n", uts.release);
	printf("version : %s\n", uts.version);
	printf("Machine : %s\n",uts.machine);

	return 0;
}
