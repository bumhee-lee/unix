#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){
	int fd,n;

	fd=open("tmp.bbb",O_CREAT | O_WRONLY | O_TRUNC,0644);
	if(fd==-1){
		perror("Create tmp.bbb");
		exit(1);
	}

	n=dup2(fd,1);
	printf("%d\n",n);
	printf("DUP2 : Standard Output Redirection\n");
	close(fd);

	return 0;
}
