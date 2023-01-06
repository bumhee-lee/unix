#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){
	int fd;

	fd=open("unix.txt", O_CREAT | O_EXCL, 0644);
	if(fd==-1){
		perror("excl");
		exit(1);
	}
	close(fd);

	return 0;
}
