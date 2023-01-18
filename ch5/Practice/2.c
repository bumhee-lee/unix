#include<unistd.h>
#include<stdio.h>

int main(void){
	printf("PGID(1121):%d\n", (int)getpgid(1121));

	return 0;
}
