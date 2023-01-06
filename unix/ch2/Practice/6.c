#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(void){
	int fd,n;
	char buf[BUFSIZ];
	double avg;
	char sno[8];
	char uni[3];
	char c[3];
	char nw[3];
	

	fd=open("data.dat",O_RDONLY, S_IRUSR);
	if(fd==-1){
		perror("open");
		exit(1);
	}
	read(fd,buf,19);
	for(int i=0;i<2;i++){
		read(fd,buf,7);
		buf[7]='\0';
		strcpy(sno,buf);

		read(fd,buf,1);

		read(fd,buf,2);
		buf[2]='\0';
		strcpy(uni,buf);

		read(fd,buf,1);

		read(fd,buf,2);
		buf[2]='\0';
		strcpy(c,buf);

		read(fd,buf,1);

		read(fd,buf,2);
		buf[2]='\0';
		strcpy(nw,buf);
	
		printf("sno:%s\tavg:%lf\n",sno,(double)(atoi(uni)+atoi(c)+atoi(nw))/3.0);
		if(SEEK_END==lseek(fd,0,SEEK_CUR))
			break;
		else
			read(fd,buf,1);
	}
	
	close(fd);

	return 0;
}

