#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
	int fd[2],n,i;
	char buf[256],c;
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
			close(fd[0]);
			strcpy(buf, "hello im your son\n");
			write(fd[1], buf, strlen(buf));
			close(fd[1]);
			break;
		default:
			close(fd[1]);
			i=0;
			while((n=read(fd[0],&c,1))>0){
				buf[i]=c;
				i++;
			}
			buf[i]='\0';
			printf("message from son: %s\n", buf);
			close(fd[0]);
			break;
	}
	return 0;
}

