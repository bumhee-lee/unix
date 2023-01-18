#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>

void handler(int signo){
	printf("Conversation end.\n");
	exit(0);
}

int main(void){
	int rpd, wpd n, i;	//read pipe, write pipe, ch counter, in
	char c,buf[256];	//ch buffer, msg buffer
	i=0;

	printf("Server ==============\n");

	//signal setting
	if(sigset(SIGINT,handler)==SIG_ERR){
		perror("sigset");
		exit(1);
	}

	//creat read pipe
	if(mkfifo("./FIFO1", 0666)==-1){
		perror("mkfifo");
		exit(1);
	}

	//creat write pipe
	if(mkfifo("./FIFO2", 0666)==-1){
		perror("mkfifo");
		exit(1);
	}

	//open read pipe
	if((rpd=open("FIFO1", O_RDONLY))==-1){
		perror("open");
		exit(1);
	}

	while(1){
		//send msg
		write(1,"To client: ",11);
		while(1){
			read(0,&c,1);
			if(c!='\\')
				buf[i++]=c;
			else
				break;
		}
		write(wpd,buf,i);

		//receive msg
		write(1, "From client: ",13);
		n=read(rpd, buf, 256);
		write(1, buf, n);
		write(1, "\n",1);
	}
	close(rpd);
	close(wpd);
	return 0;
}
