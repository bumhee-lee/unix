#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char *fname;
	char fntmp[BUFSIZ];
	char template[32];

	fname=tmpnam(NULL);
	printf("1. TMP file name(tmpnam) : %s\n",fname);

	tmpnam(fntmp);
	printf("2. TMP file name(tmpnam) : %s\n",fntmp);

	fname = tempnam("/tmp","hanbit");
	printf("3. TMP file name(tempnam) : %s\n",fname);

	strcpy(template, "/tmp/hanbitXXXXXX");
	fname = mktemp(template);
	printf("4. TMP file name(mktemp) : %s\n", fname);

	return 0;
}

