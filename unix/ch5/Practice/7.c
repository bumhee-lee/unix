#include<stdlib.h>
#include<stdio.h>


int main(int argc, char *argv[]){

	char *env = argv[1];
	char *val = argv[2];

	setenv(env, val,0);
	
	val = getenv(env);

	printf("%s = %s\n", env,val);

	return 0;
}

