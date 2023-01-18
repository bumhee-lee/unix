#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>


#define SOCKET_NAME "hbsocket"
int main(void){
	int sd, len;
	char buf[256];
	struct sockaddr_un ser;
	if((sd=socket(AF_UNIX, SOCK_STREAM ,0))==-1){
		perror("socket");
		exit(1);
	}

	memset((char *)&ser, '\0', sizeof(ser));
	ser.sun_family = AF_UNIX;
	strcpy(ser.sun_path, SOCKET_NAME);
	len=sizeof(ser.sun_family)+strlen(ser.sun_path);

	if(connect(sd, (struct sockaddr *)&ser, len)<0){
		perror("bind");
		exit(1);
	}

	printf("input file name: ");
	scanf("%s",buf);

	if(send(sd, buf, sizeof(buf),0)==-1){
		perror("send");
		exit(1);
	}
	close(sd);

	return 0;
}