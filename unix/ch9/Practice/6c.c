#include<types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int pd, fd, n;	//pipe, msg file, ch counter
	char buf[256];	//msg buf

	//arg check
	if(argc!=2){
		printf("Usage: ./6c filename\n");
		exit(1);
	}

	//msg file open
	if((fd=open(argv[1], O_RDONLY))==-1){
		perror("open");
		exit(1);
	}

	//pipe open
	if((pd=open("./HAN-FIFO", O_WRONLY))==-1){
		perror("open");
		exit(1);
	}

	//read msg and save to buffer
	n=read(fd, buf,256);
	if(n<0){
		perror("read");
		exit(1);
	}

	//send msg to fifo
	write(pd,buf,n);

	close(pd);
	close(fd);

	return 0;
}
