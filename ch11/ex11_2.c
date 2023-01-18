#include<netdb.h>
#include<stdio.h>

int main(void){
	struct servent *port;	//port info structure
	int n;			//counter

	setservent(0);		//set offset 0

	for(n=0;n<5;n++){
		port=getservent();	//get port info and print
		printf("Name=%s, Port=%d\n", port->s_name, port->s_port);
	}

	endservent(); //close port info database

	return 0;
}
