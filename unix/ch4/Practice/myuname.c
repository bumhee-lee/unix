#include<stdio.h>
#include<stdlib.h>
#include<sys/utsname.h>

int main(int argc, char *argv[]){
	int n;
	extern char *optarg;
	extern int optind;
	struct utsname uts;


	if(uname(&uts)==-1){
		perror("uname");
		exit(1);
	}

	while((n=getopt(argc,argv,"asnrvm"))!=-1){
		switch(n){
			case 'a':
				printf("%s %s %s %s %s\n", uts.sysname, uts.nodename, uts.release, uts.version, uts.machine);
				break;
			case 's':
				printf("%s\n", uts.sysname);
				break;
			case 'n':
				printf("%s\n", uts.nodename);
				break;
			case 'r':
				printf("%s\n", uts.release);
				break;
			case 'v':
				printf("%s\n", uts.version);
				break;
			case 'm':
				printf("%s\n", uts.machine);
				break;
		}
	}

	return 0;
}
