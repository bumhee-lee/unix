#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){
	char *s_no="201611015";
	char *name="leebumhee";
	char *tmp_file;

	tmp_file=tmpnam(tmp_file);

	FILE *fp;
	fp=fopen(tmp_file,"w");
	if(fp==NULL){
		perror("fopen");
		exit(1);
	}

	fwrite(s_no, sizeof(char), strlen(s_no),fp);
	fwrite(name, sizeof(char), strlen(name),fp);

	fclose(fp);

	return 0;
}
