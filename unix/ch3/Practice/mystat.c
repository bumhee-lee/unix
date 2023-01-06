#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>


int main(int argc, char *argv[]){

	struct stat buf, lbuf;
	int kind;
	char f_type[20];
	stat(argv[1], &buf);
	lstat(argv[1], &lbuf);
	char mode[10]="---------\0";
	
	kind=buf.st_mode & S_IFMT;

	if(lbuf.st_mode & S_IFLNK)
		kind=S_IFLNK;
	switch(kind){
		case S_IFIFO:
		strcpy(f_type,"FIFO");
			break;
		case S_IFDIR:
			strcpy(f_type,"Directory");
			break;
		case S_IFREG:
			strcpy(f_type,"Regular file");
			break;
		case S_IFLNK:
			strcpy(f_type, "symbolic link file");
			break;
		case S_IFCHR || S_IFBLK:
			strcpy(f_type,"special file");
			break;
		default:
			strcpy(f_type, "unknown");
			break;
	}

	if(buf.st_mode & S_IRUSR)
		mode[0]='r';
	if(buf.st_mode & S_IWUSR)
		mode[1]='w';
	if(buf.st_mode & S_IXUSR)
		mode[2]='x';
	if(buf.st_mode &S_IRGRP)
		mode[3]='r';
	if(buf.st_mode & S_IWGRP)
		mode[4]='w';
	if(buf.st_mode & S_IXGRP)
		mode[5]='x';
	if(buf.st_mode & S_IROTH)
		mode[6]='r';
	if(buf.st_mode & S_IWOTH)
		mode[7]='w';
	if(buf.st_mode & S_IXOTH)
		mode[8]='x';

	printf("file name: %s\n",argv[1]);
	printf("inode: %d\n",buf.st_ino);
	printf("file type : %s\n",f_type);
	printf("file mode : %s\n",mode);
	printf("UID : %d\n",buf.st_uid);
	printf("file access time : %d\n",buf.st_atime);

	return 0;
}
