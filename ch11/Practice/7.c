#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdio.h>
#include<inttypes.h>

int main(void){
	struct servent *port;

	port = getservbyname("ftp","tcp");

	printf("port:%d\n", ntohs(port->s_port));

	return 0;
}
