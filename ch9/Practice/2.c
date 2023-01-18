#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[]){
	int fd[2], status,n,i;
	char buf[256];
	char c;
	pid_t pid;

	if(pipe(fd)==-1){
		perror("pipe");
		exit(1);
	}
	i=0;
	switch(pid=fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			close(fd[1]);
			while((n=read(fd[0],&c,1))>0){
				buf[i]=c;
				i++;
			}
			buf[i]='\0';
			write(1,buf,strlen(buf));
			execlp("more","more",buf,(char *)NULL);
			close(fd[0]);
			break;
		default:
			close(fd[0]);
			write(fd[1], argv[1], strlen(argv[1]));
			close(fd[1]);
			wait(NULL);
			break;

	}

	return 0;
}
