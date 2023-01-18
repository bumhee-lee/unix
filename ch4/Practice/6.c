#include<shadow.h>
#include<time.h>

int main(int argc, char *argv[]){
	struct spwd *spw;
	unsigned long long t;
	time_t t1,t2;
	
	spw=getspnam(argv[1]);	//choice user

	t=spw->sp_lstchg; //find modified time
	
	t=t;		//day->day-1
	t*=86400;	//day->second
	t1=(time_t)t;	//scailing
		
	time(&t2);	//current time
	t2=t2%86400;	//current today time
	t1=t1+t2;	//passwd change time
	printf("Time: %s",ctime(&t1));//output

	return 0;
}
