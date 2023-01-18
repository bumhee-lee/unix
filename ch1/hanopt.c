#include<stdio.h>
int main(int argc, char *argv[]){
	int n;
	extern char *optarg;
	while((n=getopt(argc,argv,"ahu:"))!=-1){
		switch(n){
			case 'a':
				printf("Welcome to Unix System Programming World!!\n");
				break;
			case 'h':
				printf("you can use -a, -h, -u\n");
				break;
			case 'u':
				printf("Nice to meet %s\n",optarg);
				break;
		}
	}
	return 0;
}
