#include<stdlib.h>
#include<stdio.h>

int main(void){
	FILE *fp;
	int a;

	fp=popen("wc -l", "w");
	if(fp==NULL){
		perror("popen");
		exit(1);
	}

	for(a=0;a<100;a++){
		fprintf(fp, "test line\n");
	}

	pclose(fp);

	return 0;
}
