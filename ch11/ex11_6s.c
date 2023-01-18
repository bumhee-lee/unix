#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define SOCKET_NAME "hbsocket"

int main(void){
	char buf[256];
	struct sockaddr_un ser, cli;
	int sd, nsd, len, clen;

	//creat socket
	if((sd=socket(AF_UNIX, SOCK_STREAM, 0))==-1){
		perror("socket");
		exit(1);
	}

	//memory set 0
	memset((char *)&ser, 0, sizeof(struct sockaddr_un));
	ser.sun_family = AF_UNIX;
	strcpy(ser.sun_path,SOCKET_NAME);
	len=sizeof(ser.sun_family)+strlen(ser.sun_path);

	//assign name to socket
	if(bind(sd,(struct sockaddr *)&ser, len)){
		perror("bind");
		exit(1);
	}

	//waiting client (max:5)
	if(listen(sd, 5)<0){
		perror("listen");
		exit(1);
	}

	//wait and accept client's connection
	printf("Wating...\n");
	if((nsd=accept(sd, (struct sockaddr *)&cli, &clen))==-1){
		perror("accept");
		exit(1);
	}

	//receive client's message
	if(recv(nsd,buf,sizeof(buf),0)==-1){
		perror("recv");
		exit(1);
	}

	printf("received message: %s\n", buf);
	close(nsd);
	close(sd);

	return 0;
}
