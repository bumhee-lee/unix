#include<unistd.h>
#include<sys/errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	extern int errno;
	char filename[255];
	char *mode ;
	struct stat buf;
	char mode1[4], mode2[4], op;
	char c;
	int i=0,j=0,k=0;
	int flag=0;
	int mod=0;
	char modec[10]="---------\0";

	if(argc!=3){
		printf("usage: mychmod 'mode' 'filename'\n");
		exit(1);
	}

	strcpy(filename, argv[2]);
	mode = (char *)malloc(sizeof(char)*strlen(argv[1])+1);
	strcpy(mode, argv[1]);

	/** file mode print **/
	if(access(filename, F_OK)==-1&&errno==ENOENT){
		printf("%s:file not exist\n",filename);
		exit(1);
	}

	stat(filename, &buf);

	if(buf.st_mode & S_IRUSR)
		modec[0]='r';
	if(buf.st_mode & S_IWUSR)
		modec[1]='w';
	if(buf.st_mode & S_IXUSR)
		modec[2]='x';
	if(buf.st_mode &S_IRGRP)
		modec[3]='r';
	if(buf.st_mode & S_IWGRP)
		modec[4]='w';
	if(buf.st_mode & S_IXGRP)
		modec[5]='x';
	if(buf.st_mode & S_IROTH)
		modec[6]='r';
	if(buf.st_mode & S_IWOTH)
		modec[7]='w';
	if(buf.st_mode & S_IXOTH)
		modec[8]='x';

	printf("prior mode: %o %s\n", (unsigned int)buf.st_mode,modec);
	/** file mode change **/
	do{
		c = mode[i];
		if(c=='+'&&flag==0){
			flag=1;
			op=c;
		}
		else if(c=='-'&&flag==0){
			flag=1;
			op=c;
		}
		else if(flag==0&&(c=='u'||c=='g'||c=='o')){
			mode1[j++]=c;
		}
		else if(flag==1&&(c=='r'||c=='w'||c=='x')){
			mode2[k++]=c;
		}
		else{
			printf("%c\n",c);
			printf("%d\n",i);
			printf("wrong input!\n");
			exit(1);
		}
		i++;
	}while(mode[i]!='\0');

	mode1[j]='\0';
	mode2[k]='\0';

	i=j=k=0;

	for(i=0;i<strlen(mode1);i++){

			if(mode1[i]=='u'){
				for(j=0;j<strlen(mode2);j++){
					if(mode2[j]=='r'){
						mod|=S_IRUSR;
					}
					else if(mode2[j]=='w'){
						mod|=S_IWUSR;
					}
					else if(mode2[j]=='x'){
						mod|=S_IXUSR;
					}
				}
				j=0;
			}
			else if(mode1[i]=='g'){
				for(j=0;j<strlen(mode2);j++){
					if(mode2[j]=='r'){
						mod|=S_IRGRP;
					}
					else if(mode2[j]=='w'){
						mod|=S_IWGRP;
					}
					else if(mode2[j]=='x'){
						mod|=S_IXGRP;
					}
				}
				j=0;
			}
			else if(mode1[i]=='o'){
				for(j=0;j<strlen(mode2);j++){
					if(mode2[j]=='r'){
						mod|=S_IROTH;
					}
					else if(mode2[j]=='w'){
						mod|=S_IWOTH;
					}
					else if(mode2[j]=='x'){
						mod|=S_IXOTH;
					}
				}
				j=0;
			}
		if(op=='+'){
			buf.st_mode|=mod;
			chmod(filename,buf.st_mode);
		}
		else{
			buf.st_mode &=~(mod);
			chmod(filename,buf.st_mode);
		}
	}
	stat(filename, &buf);
	for(int i=0;i<9;i++){
		modec[i]='-';
	}
	if(buf.st_mode & S_IRUSR)
		modec[0]='r';
	if(buf.st_mode & S_IWUSR)
		modec[1]='w';
	if(buf.st_mode & S_IXUSR)
		modec[2]='x';
	if(buf.st_mode &S_IRGRP)
		modec[3]='r';
	if(buf.st_mode & S_IWGRP)
		modec[4]='w';
	if(buf.st_mode & S_IXGRP)
		modec[5]='x';
	if(buf.st_mode & S_IROTH)
		modec[6]='r';
	if(buf.st_mode & S_IWOTH)
		modec[7]='w';
	if(buf.st_mode & S_IXOTH)
		modec[8]='x';
	printf("current mode: %o %s\n", buf.st_mode,modec);

	return 0;
}
