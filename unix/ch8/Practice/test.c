#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(void){
	
	struct stat statbuf;
	stat("mmap.dat", &statbuf);

	printf("%d\n", statbuf.st_size);

	return 0;
}
