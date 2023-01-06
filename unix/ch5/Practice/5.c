#include<stdlib.h>
#include<stdio.h>

int main(void){
	setenv("HBENV","hbooks",0);
	
	char *val;

	val=getenv("HBENV");

	if(val==NULL)
		printf("HBENV not defined\n");
	else
		printf("HBENV = %s\n", val);

	return 0;
}
