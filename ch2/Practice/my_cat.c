#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int rfd, n,line;
	int end_offset;
	char buf[BUFSIZ];

	rfd = open(argv[1], O_RDONLY);

	if(rfd==-1){
		perror("open:arg file");
		exit(1);
	}
	
	line=1;

	if((n=read(rfd,buf,1))<=0)
		return 0;
	end_offset = lseek(rfd,0,SEEK_END);
	lseek(rfd,0,SEEK_SET);

	printf("%d ",line);
	do{
		while(1){
			n=read(rfd,buf,1);
			printf("%c",buf[0]);
			if(buf[0]=='\n')
				break;
		}
		if(lseek(rfd,0,SEEK_CUR)!=end_offset)
			printf("%d ",++line);
		else 
			break;
	}while(1);


	close(rfd);

	return 0;
}
