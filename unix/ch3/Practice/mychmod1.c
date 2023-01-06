#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
	char file_name[255]; 
	char option[255];

	strcpy(file_name,argv[argc-1]);
	strcpy(option, argv[1]);

	if(access(file_name,F_OK)){
			printf("file not exist:%s\n",file_name);
			exit(1);
	}

	

	return 0;
}
