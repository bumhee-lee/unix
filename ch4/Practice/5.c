#include<grp.h>
#include<stdlib.h>
#include<string.h>
#include<pwd.h>

int main(int argc, char *argv[]){
	struct group *grp;
	int n,m, major;
	struct passwd *pw;
	
	while((pw=getpwent())!=NULL){
		if(strcmp(argv[1], pw->pw_name)==0){
			major=pw->pw_gid;
		}
	}
	
	while((grp=getgrent())!=NULL){
		m=0;
		if(grp->gr_gid==major)
			printf("major group: %s ,secondary group: ",grp->gr_name);
		while(grp->gr_mem[m]!=NULL){
			if(strcmp(argv[1],grp->gr_mem[m++])==0){
				printf("%s ",grp->gr_name);
				break;
			}
		}
	}
	printf("\n");

	return 0;
}
