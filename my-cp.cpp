#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;
int main (int argc,char **argv)
{
	if (argc < 3)
	   return 1;
	int fd_SrcFile = open(argv[1],O_RDONLY);
	if (fd_SrcFile==-1)
	   return 2;
	int fdOstFile=open(argv[2],O_CREAT | O_WRONLY,S_IRUSR);
	if (fdOstFile==-1)
           return 3;
	char buffer[2];
	ssize_t charcount;
	while ((charcount=read(fd_SrcFile,buffer,sizeof(buffer)))!=-1)
	{
	  write (fdOstFile,buffer,charcount);
	}
	return 0;
}
