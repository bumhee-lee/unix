#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

int main(void){
	DIR *dp;
	struct dirent *dent;
	char cur_dir[255];
	struct stat buf;
	int kind;

	getcwd(cur_dir,255);
	if((dp=opendir(cur_dir))==NULL){
		perror("opendir");
		exit(1);
	}

	while((dent = readdir(dp))){
		stat(dent->d_name,&buf);
		printf("%s: ", dent->d_name);
		
		kind=buf.st_mode & S_IFMT;

		if(kind==S_IFDIR)
			printf("This is directory\n");
		else
			printf("Ths is file\n");
	}

	return 0;
}
		
