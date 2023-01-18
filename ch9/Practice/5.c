#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
	int fd1[2], fd2[2], i,n,status;
	char buf[256],c;
	pid_t pid;

	if(pipe(fd1)==-1){
		perror("pipe");
		exit(1);
	}
	if(pipe(fd2)==-1){
		perror("pipe");
		exit(1);
	}

	switch(pid=fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			close(fd1[1]);
			close(fd2[0]);
			write(fd2[1], "hello father\n", 14);
			read(fd1[0],buf,256);
			write(1,buf,strlen(buf));
			close(fd1[0]);
			close(fd2[1]);
			break;
		default:
			close(fd1[0]);
			close(fd2[1]);
			read(fd2[0],buf,256);
			write(1, buf, strlen(buf));
			write(fd1[1], "hello son\n",11);
			close(fd1[1]);
			close(fd2[0]);
			waitpid(pid,&status,0);
			break;
	}
	return 0;
}

