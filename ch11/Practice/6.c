#include<netdb.h>
#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<inttypes.h>

int main(void){
	struct servent *sent;
	
	sent = getservbyport(htons(21), "tcp");

	printf("port name:%s\n", sent->s_name);

	return 0;
}
