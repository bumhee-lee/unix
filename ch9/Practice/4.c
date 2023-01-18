#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
	int fd[2], n, i,count=0;
	char buf[2560], c;
	pid_t pid;

	if(pipe(fd)==-1){
		perror("pipe");
		exit(1);
	}

	switch(pid=fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			close(fd[1]);
			while((n=read(fd[0],&c, 1))>0){
				if(c=='\n')
				count++;
			}
			printf("%d\n",count);
			close(fd[0]);
			break;
		default:
			close(fd[0]);
			for(i=0;i<100;i++){
				write(fd[1], "test line\n", 11);
			}
			close(fd[1]);
			break;
	}
	return 0;
}
