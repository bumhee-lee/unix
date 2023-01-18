#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

void handler(int dummy){
	;
}
char *itoa(int a);
int mypow(int a, int b);

int main(int argc, char **argv){
	pid_t u1_pid, u2_pid;
	key_t key;
	int shmid;
	void *shmaddr;
	char buf[1024];
	sigset_t mask;

	sigfillset(&mask);
	sigdelset(&mask, SIGUSR1);
	sigdelset(&mask, SIGINT);
	sigset(SIGUSR1, handler);

	if(argc==1){	
		key=ftok("shmfile",2);
		shmid=shmget(key,1024, IPC_CREAT|0666);	//get shmid
		shmaddr=shmat(shmid, NULL, 0);
		
		printf("U1:wating signal from user2...\n");
		sigsuspend(&mask);		//waiting signal
		strcpy(buf,shmaddr);		//get user2's pid
		buf[strlen(buf)]='\0';		//remove '\n',add '\0'
		u2_pid=(pid_t)atoi(buf);	//get int pid
		printf("U1:get user2's pid:%d\n",u2_pid);

		if(u2_pid!=0){			//proper pid
			printf("U1:send ack signal to user2(%d)\n",u2_pid);
			kill(u2_pid,SIGUSR1);	//send ack signal
		}
		else{				//wrong pid
			printf("U1:wrong pid: %s\n",buf);	//print buf(pid)
			exit(1);
		}
		
		while(1){
			printf("U1:wating signal from user2...\n");
			sigsuspend(&mask);	//wating SIGUSR1 signal
			strcpy(buf, shmaddr);	//msg store to buf
			printf("U1:rcvd msg from u2: %s",buf); //print msg
			printf("U1:user1: ");	//insert msg
			fgets(buf,1024,stdin);	//insert msg
			if(strcmp(buf,"q\n")==0)//check end msg
			{
				printf("U1:dialogue end.\n");
				break;		//end
			}
			strcpy(shmaddr,buf);	//msg store to shmaddr
			printf("U1:send msg signal to user2\n");
			kill(u2_pid,SIGUSR1);	//send signal to pid
		}
	}
	else if(argc==2){			//pid info
		key=ftok("shmfile",2);
		shmid=shmget(key,1024, 0);	//get shmid
		shmaddr=shmat(shmid, NULL, 0);
	
		u2_pid=getpid();			//get pid
		printf("U2:user2's pid: %d\n", (int)u2_pid);
		printf("U2:user2's pid(str):%s\n",itoa((int)u2_pid));
		strcpy(shmaddr,itoa((int)u2_pid));//store pid to shmaddr
		u1_pid=(pid_t)atoi(argv[1]);
		printf("U2:send u2_pid to user1(%d)\n",u1_pid);
		kill(u1_pid,SIGUSR1);
		printf("U2:wating signal from user1...\n");
		sigsuspend(&mask);		//wating ack signal

		while(1){
			printf("U2:user2: ");	//send msg
			fgets(buf,1024,stdin);		//send msg
			if(strcmp(buf,"q\n")==0){	//check end msg
				printf("U2:dialogue end.\n");
				break;
			}
			else{				
				strcpy(shmaddr,buf);	//send msg
				kill(u1_pid,SIGUSR1);
			}
			printf("U2:wating signal from user1...\n");
			sigsuspend(&mask);		//wating signal
			strcpy(buf,shmaddr);		//rcv msg
			printf("U2:rcvd msg: %s",buf);	//print rcv msg
		}

		shmctl(shmid,IPC_RMID, (struct shmid_ds *)NULL);//rm shm ipc

	}
	
	shmdt(shmaddr);
	return 0;

}

char * itoa(int a){
	static char buf[10];
	int n=0;
	int m=1;
	int j;
	int i=0;
	int k;
	while(m<=a){
		n++;
		m*=10;
	}
	m=m/10;
	j=n;
	for(i=0;i<j;i++){
		k=(a/m)+48;
		buf[i]=k;
		a=a-m*(k-48);
		m=m/10;
	}
	buf[i]='\0';
	return buf;
}

int mypow(int a, int b){
	int i=0;
	int result=1;
	for(;i<b;i++){
		result*=a;
	}
	return result;
}
