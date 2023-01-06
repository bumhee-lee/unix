#include<shadow.h>

int main(void){
	struct spwd *spw;
	int n;

	for(n=0;n<3;n++){
		spw = getspent();
		printf("LogintName : %s, Passwd: %s\n", spw->sp_namp, spw->sp_pwdp);
	}
	return 0;
}
