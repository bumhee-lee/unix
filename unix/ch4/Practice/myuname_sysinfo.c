#include<stdio.h>
#include<sys/systeminfo.h>
#include<stdlib.h>
#include<sys/utsname.h>

int main(int argc, char *argv[]){
	int n;
	extern char *optarg;
	extern int optind;
	struct utsname uts;
	char buf[6][257];

	for(int i=1;i<=6;i++){
		if(sysinfo(i,buf[i],257)==-1){
			perror("sysinfo");
			exit(1);
		}
	}

	while((n=getopt(argc,argv,"asnrvm"))!=-1){
		switch(n){
			case 'a':
				printf("%s %s %s %s %s\n", buf[1],buf[2], buf[3],buf[4],buf[5]);
				break;
			case 's':
				printf("%s\n", buf[1]);
				break;
			case 'n':
				printf("%s\n", buf[2]);
				break;
			case 'r':
				printf("%s\n", buf[3]);
				break;
			case 'v':
				printf("%s\n",buf[4]);
				break;
			case 'm':
				printf("%s\n",buf[5]);
				break;
		}
	}

	return 0;
}
