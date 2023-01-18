#include<sys/mman.h>
#include<string.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	struct stat statbuf;
	int fd;
	size_t length;
	caddr_t addr;

	if(argc!=2){
		fprintf(stderr, "Usage : %s filename\n", argv[0]);
		exit(1);
	}

	if(stat(argv[1], &statbuf)==-1){
		perror("stat");
		exit(1);
	}

	if((fd=open(argv[1], O_RDWR))==-1){
		perror("open");
		exit(1);
	}

	addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);
	if(addr==MAP_FAILED){
		perror("mmap");
		exit(1);
	}

	close(fd);

	printf("%s",addr);
	
	for(int i=0;i<strlen(addr);i++){
		printf("%c %d\n", addr[i],i);
	}
	addr[8]='\0';
	truncate("mmap.dat",7);

	msync(addr, statbuf.st_size, MS_SYNC);

	return 0;
}

