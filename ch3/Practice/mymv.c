#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
	char src[255],dest[255];
	char p_path[255], n_path[255];
	strcpy(src,argv[1]);
	strcpy(dest,argv[2]);

	int rfd, wfd,n;
	char buf[10];

	rfd=open(src,O_RDONLY);
	if(rfd==-1){
		perror("Open");
		exit(1);
	}

	chdir(dest);

	wfd = open(src,O_CREAT | O_WRONLY | O_TRUNC , 0644);
	if(wfd==-1){
		perror("Open");
		exit(1);
	}

	while((n=read(rfd,buf,6))>0)
		if(write(wfd,buf,n)!=n)
			perror("write");

	if(n==-1)
		perror("Read");

	close(rfd);
	close(wfd);

	chdir("../");

	unlink(src);

	return 0;
}
