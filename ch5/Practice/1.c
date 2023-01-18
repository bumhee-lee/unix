#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	pid_t pid = (pid_t)atoi(argv[1]);

	printf("pgid of %d = %d\n", (int)pid, (int)getpgid(pid));
	printf("sid of %d = %d\n", (int)pid, (int)getsid(pid));

	return 0;
}
