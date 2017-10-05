#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd[2];
	int  pid;
	pipe(fd);
	if((pid=fork())==0)
	{
		close(fd[1]);
		close(0);
	        dup(fd[0]);
		execl("/usr/bin/wc","wc","-c",NULL);
		close(fd[0]);
		
	}
	else
	{
		close(fd[0]);
		close(1);
		dup(fd[1]);
		execl("/bin/ls","ls",NULL);
		close(fd[1]);
	}
return 0;
}
