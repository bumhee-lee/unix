#include<stdio.h>
#include<netdb.h>

int main(void){
	struct servent *port;	//port info struct

	//get port info by name and type
	port=getservbyname("telnet","tcp");
	printf("Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));

	//get port info by port number
	port=getservbyport(htons(21),"tcp");
	printf("Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));

	return 0;
}
