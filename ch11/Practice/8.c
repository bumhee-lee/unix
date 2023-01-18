#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<netdb.h>
#include<string.h>

int main(void){
	struct hostent *hp;
	struct in_addr in;
	in_addr_t addr;

	while((hp=gethostent())!=NULL){
		if(strcmp(hp->h_name,"solaris")==0){
			printf("name=%s\n" ,hp->h_name);
			(void)memcpy(&in.s_addr, *hp->h_addr_list, sizeof(in.s_addr));

			printf("ip=%s\n", inet_ntoa(in));
		}
	}

	return 0;
}
					
	
