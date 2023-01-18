#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

void handler(int signo){
	printf("Conversation end.\n");
	exit(0);
}

int main(void){
	int rpd, wpd, n, i;	//write pipe, read pipe, counter , index
	char c, buf[256];	//ch buf, msg buf
	i=0;

	printf("Client ======================\n");

	//signal setting
	if(sigset(SIGINT, handler)==SIG_ERR){
		perror("sigset");
		exit(1);
	}

	//open write pipe
	if((rpd=open("FIFO1", O_WRONLY))==-1){
		perror("open");
		exit(1);
	}

	//open read pipe
	if((wpd=open("FIFO2",O_RDONLY))==-1){
		perror("open");
		exit(1);
	}

	while(1){
		//receive msg
		write(1, "From server: ",13);
		n=read(wpd,buf, 256);
		write(1, buf, n);
		write(1, "\n",1);

		//send msg
		write(1, "To server: ",11);
		while(read(0, &c, 1)>0){
			if(c!='\\')
				buf[i++]=c;
			else
				break;
		}
		write(rpd,buf,i);
	}

	close(rpd);
	close(wpd);

	return 0;
}
