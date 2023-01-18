#include<sys/types.h>
#include<utmpx.h>
#include<stdio.h>

int main(void){
	struct utmpx *utx;
	
	utmpxname("/var/adm/wtmpx");

	while((utx=getutxent())!=NULL){
		printf("%s %s %s\n", utx->ut_user, utx->ut_line, utx->ut_host);
		
	}

	return 0;
}
