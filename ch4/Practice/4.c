#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<grp.h>
#include<pwd.h>

int main(int argc, char *argv[])
{
	uid_t uid;
	gid_t gid;
	struct stat buf;

	if(argc!=2){
		printf("two argument needed!\n");
		exit(1);
	}

	stat(argv[1],&buf);

	uid=buf.st_uid;
	gid=buf.st_gid;

	struct group *gr;
	struct passwd *pw;

	gr=getgrgid(gid);
	pw=getpwuid(uid);

	printf("owner name: %s\n",pw->pw_name);
	printf("group name: %s\n", gr->gr_name);

	return 0;

}	

