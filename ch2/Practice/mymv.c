#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	FILE *rfp, *wfp;
	int n;
	char buf[100];

	if((rfp=fopen(argv[1],"r"))==NULL){
		perror("fopen");
		exit(1);
	}

	if((wfp=fopen(argv[2],"w"))==NULL){
		perror("fopen");
		exit(1);
	}

	while((n=fread(buf,sizeof(char),100,rfp))>0){
		fwrite(buf,sizeof(char),n,wfp);
	}

	unlink(argv[1]);

	fclose(wfp);
	fclose(rfp);

	return 0;
}
