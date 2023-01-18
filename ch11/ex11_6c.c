#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define SOCKET_NAME "hbsocket"

int main(void){
	int sd, len;
	char buf[256];
	struct sockaddr_un ser;

	//creat socket
	if((sd=socket(AF_UNIX, SOCK_STREAM, 0))==-1){
		perror("socket");
		exit(1);
	}

	//memory setting
	memset((char *)&ser, '\0', sizeof(ser));
	ser.sun_family=AF_UNIX;
	strcpy(ser.sun_path, SOCKET_NAME);
	len=sizeof(ser.sun_family)+strlen(ser.sun_path);

	//connect to server
	if(connect(sd, (struct sockaddr *)&ser, len)<0){
		perror("bind");
		exit(1);
	}

	//send msg to server
	strcpy(buf, "Unix Domain Socket Test Message");
	if(send(sd, buf, sizeof(buf),0)==-1){
		perror("send");
		exit(1);
	}
	close(sd);

	return 0;
}
