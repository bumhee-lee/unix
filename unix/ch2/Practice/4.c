#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char buf[1];
	int n;

	if((fp=fopen(argv[1],"r"))==NULL){
		perror("fopen");
		exit(1);
	}

	while((n=fread(buf,sizeof(char),1,fp))>0){
		if(ftell(fp)%2==1)
			fwrite(buf,sizeof(char),1,stdout);
	}

	fclose(fp);

	return 0;
}


