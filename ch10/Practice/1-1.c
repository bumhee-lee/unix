#include<sys/msg.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct mymsgbuf{
	long mtype;
	char mtext[80];
};

int main(void){
	key_t key;
	int msgid;
	struct mymsgbuf mesg1, mesg2, mesg3;

	key=ftok("keyfile",1);
	msgid=msgget(key, IPC_CREAT|0644);
	if(msgid==-1){
		perror("msgget");
		exit(1);
	}

	mesg1.mtype=1;
	strcpy(mesg1.mtext, "Hanbit Message 1");
	mesg2.mtype=3;
	strcpy(mesg2.mtext, "Hanbit Message 3-1");
	mesg3.mtype=3;
	strcpy(mesg3.mtext, "Hanbit Message 3-2");

	if(msgsnd(msgid, (void *)&mesg1, 80, IPC_NOWAIT)==-1){
		perror("msgsnd");
		exit(1);
	}
	
	if(msgsnd(msgid, (void *)&mesg2, 80, IPC_NOWAIT)==-1){
		perror("msgsnd");
		exit(1);
	}

	if(msgsnd(msgid, (void *)&mesg3, 80, IPC_NOWAIT)==-1){
		perror("msgsnd");
		exit(1);
	}

	return 0;
}
