#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

int main(void){
	int pd,fd,n; //pipe, storing file, character counter;
	char filename[256], buf[256];	//filename, msgbuffer

	printf("Server ====================\n");

	//creat pipe
	if(mkfifo("./HAN-FIFO", 0666)==-1){
		perror("mkfifo");
		exit(1);
	}

	//pipe open
	if((pd=open("HAN-FIFO", O_RDONLY))==-1){
		perror("open");
		exit(1);
	}

	//msg read and print
	n=read(pd,buf,256);
	if(n<0){
		perror("read");
		exit(1);
	}
	write(1,buf,n);

	//msg store in file
	printf("insert filename : ");
	scanf("%s", filename);

	if((fd=open(filename, O_CREAT|O_WRONLY|O_TRUNC))==-1){
			perror("open");
			exit(1);
	}

	write(fd,buf,n);

	close(pd);
	close(fd);

	return 0;
}

