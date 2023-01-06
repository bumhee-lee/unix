#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>

void handler(int signo){
	psignal(signo, "Received signal:");
	sleep(1);
}

int main(int argc, char* argv[]){
	int fd,n,loc;
	pid_t pid;
	pid_t ppid;
	caddr_t addr;
	struct stat statbuf;
	char buf[100];

	if(argc!=2){
		fprintf(stderr,"Usage : %s filename\n", argv[0]);
		exit(1);
	}

	if(stat(argv[1], &statbuf)==-1){
		perror("stat");
		exit(1);
	}

	if((fd=open(argv[1], O_RDWR))==-1){
		perror("open");
		exit(1);
	}
	truncate(argv[1], 100);


	switch(pid=fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:

	addr=mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);
	if(addr==MAP_FAILED){
		perror("mmap");
		exit(1);
	}
			strcpy(addr,"hi i'm your son!");
			msync(addr, statbuf.st_size, MS_SYNC);
			munmap(addr,statbuf.st_size);
			ppid=getppid();
			printf("1. child process : ppid:%d\n", ppid);
			sleep(2);
			kill(ppid,SIGUSR1);
			printf("2. child process end\n");
			break;
		default:
			printf("1. parent process start\n");
			if(sigset(SIGUSR1, handler)==SIG_ERR){
				perror("sigset");
				exit(1);
			}
			sigpause(SIGUSR1);
			fd=open(argv[1], O_RDONLY);
			n=read(fd,buf,100);
			if(n==-1){
				perror("read");
				exit(1);
			}
			buf[n]='\0';
			printf("message from son: %s",buf);
			close(fd);
			break;
	}

	close(fd);
	return 0;
}

			
