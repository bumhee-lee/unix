#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char *argv[]){
	
	if(!access(argv[1],F_OK)){
		printf("file already exist\n");
		exit(1);
	}
	char path[100];

	getcwd(path,100);
	strcat(path,"/");
	strcat(path,argv[1]);
	mkdir(argv[1],0755);
	chdir(path);

	printf("current directory : %s\n", getcwd(NULL,100));

	return 0;
}
