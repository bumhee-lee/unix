#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
	int option=0, tmp;
	char file_name[255];

	strcpy(file_name,argv[2]);

	if(access(file_name,F_OK)){
		printf("file not exist : %s\n",file_name);
		exit(1);
	}

	option=atoi(argv[1]);
	tmp=0;
	tmp+=option/100*64;
	tmp+=(option%100)/10*8;
	tmp+=(option%10);
	option=tmp;

	if(chmod(file_name,option)){
		perror("chmod");
		exit(1);
	}

	return 0;
}
