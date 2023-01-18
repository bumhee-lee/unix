#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int n,fd;
	char buf[1];

	if((fd=open(argv[1],O_RDONLY))==-1){
		perror("open");
		exit(1);
	}

	while((n=read(fd,buf,1))>0){
		if(lseek(fd,0,SEEK_CUR)%2==1)
			printf("%c",buf[0]);
	}

	close(fd);

	return 0;
}
