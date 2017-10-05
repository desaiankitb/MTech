#include<stdio.h>
main()
{
int fd[2];
int n;
char buf[30];
pipe(fd) ;
if(fork()==0)
{
	
	printf("\nread from pipe:");
	close(fd[1]);
	while(n=read(fd[0],buf,1)>0)
	{
		write(1,buf,n);
	}
	close(fd[0]);
	
}
else
{
	printf("read from stdin");
	close(fd[0]);
	while(n=read(0,buf,1)>0)
	{
		write(fd[1],buf,n);
	}
	printf("\ncontent of buf is:\n",buf);
}
}

