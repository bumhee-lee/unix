#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){
	in_addr_t addr;		//binary type
	struct hostent *hp;	//host info struct
	struct in_addr in;	//binary type
	
	//transform string type to binary type
	if((addr=inet_addr("218.237.65.4"))==(in_addr_t)-1){
		printf("Error: inet_addr(218.237.65.4\n");
		exit(1);
	}
	
	//get host info by addr
	hp=gethostbyaddr((char *)&addr, 4, AF_INET);
	if(hp==NULL){
		(void)printf("Host information not found\n");
		exit(2);
	}

	printf("Name=%s\n", hp->h_name);
	
	//hp->a_addr_list -> in.s_addr copy
	(void)memcpy(&in.s_addr, *hp->h_addr_list, sizeof(in.s_addr));
	//struct -> string transform
	printf("IP=%s\n",inet_ntoa(in));

	return 0;
}

