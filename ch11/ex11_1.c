#include<netdb.h>
#include<stdio.h>

int main(void){
	struct hostent *hent;	//host info struct

	sethostent(0);		//set offset 0

	while((hent=gethostent())!=NULL)
		printf("Name=%s\n", hent->h_name);	//get hostname and print

	endhostent();		//close host file

	return 0;
}
