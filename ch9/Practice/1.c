#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	FILE *fp ,*fp1;
	int a;
	char buf[BUFSIZ];

	fp=popen("more -n" ,"w");
	if(fp==NULL){
		fprintf(stderr,"popen failed\n");
		exit(1);
	}
	
	fp1=fopen(argv[1],"r");
	if(fp1==NULL){
		fprintf(stderr,"fopen failed\n");
		exit(1);
	}

	while(fgets(buf,BUFSIZ, fp1)!=NULL){
		fputs(buf,fp);
	}
	fclose(fp1);

	

	pclose(fp);

	return 0;
}
