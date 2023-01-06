#include<sys/msg.h>
#include<stdlib.h>
#include<stdio.h>

int main(void){

	msgctl(0, IPC_RMID, (struct msqid_ds *)NULL);
	return 0;
}
