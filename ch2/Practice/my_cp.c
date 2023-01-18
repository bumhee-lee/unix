
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	int rfd,wfd,n;
	char buf[BUFSIZ];
	if((rfd=open(argv[1],O_RDONLY))==-1){
		perror("open(source)");
		exit(1);
	}

	if((wfd=open(argv[2],O_CREAT | O_WRONLY | O_TRUNC,0644))==-1){
		perror("open(destination)");
		exit(1);
	}

	while((n=read(rfd,buf,BUFSIZ))>0)
		if(write(wfd,buf,n)!=n) perror("write");

	if(n==-1)	perror("Read");

	close(rfd);
	close(wfd);

	return 0;
}

