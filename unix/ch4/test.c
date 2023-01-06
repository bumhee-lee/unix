#include<stdio.h>
#include<unistd.h>

int main(void){
	printf("%s %s\n", getlogin(), cuserid(NULL));

	return 0;
}
