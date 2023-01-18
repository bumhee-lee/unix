#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/mman.h>

int main(int argc, char *argv[]){
	struct stat statbuf;
	int fd;
	caddr_t addr;

	if(argc!=2){
		fprintf(stderr,"Usage : %s fliename",argv[0]);
		exit(1);
	}

	if(stat(argv[1],&statbuf)==-1){
		perror("stat");
		exit(1);
	}

	if((fd=open(argv[1], O_RDWR))==-1){
		perror("open");
		exit(1);
	}

	addr=mmap(NULL,statbuf.st_size, PROT_READ,MAP_PRIVATE,fd,(off_t)0);
	if(addr==MAP_FAILED){
		perror("mmap");
		exit(1);
	}
	close(fd);

	addr[0]='x';

	return 0;
}
