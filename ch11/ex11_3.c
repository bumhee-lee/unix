#include<netdb.h>
#include<stdio.h>

int main(void){
	struct servent *port;		//port info struct
	int n;				//counter

	setservent(0);			//set offset 0


	/* get port info 
	 * servent is network struct
	 * so transform byte order*/
	for(n=0;n<5;n++){
		port = getservent();
		printf("Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));
	}

	endservent();	//close port info database

	return 0;
}
