#include<stdio.h>
#include<strings.h>

int main()
{
	int pfd[2];
	char buff[20];
	int n=0,pid=-1;
	pipe(pfd);
	pid=fork();		
	if(pid>0)
	{
		printf("In Parent Process\n");			
		write(pfd[1],"Hello",sizeof("Hello"));
	}
	else
	{
		n=read(pfd[0],buff,sizeof(buff));
		buff[n]='\0';
		printf("In Child Process : received the message : %s\n",buff);
	}
	return 0;
}
