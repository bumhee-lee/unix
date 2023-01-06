#include<sys/types.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){
	int fd, pagesize, length;
	caddr_t addr;

	pagesize = sysconf(_SC_PAGESIZE);
	length=pagesize;

	if((fd=open("a.txt", O_RDWR|O_CREAT|O_TRUNC, 0666))==-1){
		perror("open");
		exit(1);
	}

	if(truncate("a.txt", (off_t)length)==-1){
		perror("ftruncate");
		exit(1);
	}

	addr=mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED,fd, (off_t)0);
	if(addr==MAP_FAILED){
		perror("mmap");
		exit(1);
	}

	close(fd);

	strcpy(addr, "Unix System Programming");

	return 0;
}
