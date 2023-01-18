#include<stdlib.h>
#include<stdio.h>

int main(void){
	setenv("HBENV","hbooks",0);
	setenv("MYENV" ,"bumhee",0);
	char *val;

	val=getenv("MYENV");

	if(val==NULL)
		printf("MYENV not defined\n");
	else
		printf("MYENV = %s\n", val);

	unsetenv("MYENV");

	val=getenv("MYENV");

	if(val==NULL)
		printf("MYENV is removed\n");


	return 0;
}
