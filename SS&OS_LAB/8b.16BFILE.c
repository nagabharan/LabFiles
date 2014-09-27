#include<stdio.h>
#include<fcntl.h>
main()
{
	char buf1[]="abcdefghijklmnop";
	char buf2[]="ABCDEFGHIJKLMNOP";
	int fd = open("K1",O_RDWR|O_CREAT|O_EXCL,0755);
	write(fd,buf1,16);
	lseek(fd,32,SEEK_CUR);
	write(fd,buf2,16);
	close(fd);
	system("vi K1");
}
