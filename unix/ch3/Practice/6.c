#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
	DIR *dp;
	struct dirent *dent;
	char file_name[255];

	if(argc==1){
		getcwd(file_name,255);
		if((dp=opendir(file_name))==NULL){
			perror("opendir");
			exit(1);
		}
	}
	else{
		if((dp=opendir(argv[1]))==NULL){
			perror("opendir");
			exit(1);
		}
	}

	while((dent = readdir(dp))){
		if((strcmp(dent->d_name,".")==0)||(strcmp(dent->d_name,"..")==0))
		{
			continue;
		}
		else
		{
			printf("%s\t",dent->d_name);
		}
	}

	printf("\n");
	return 0;
}
