#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	DIR *dp;
	struct dirent *dent;
	int count=0;

	if((dp=opendir(argv[1]))==NULL){
		perror("opendir");
		exit(1);
	}

	while((dent=readdir(dp))){
		count++;
	}
	
	if(count<=2){
		rmdir(argv[1]);
	}

	return 0;
}
