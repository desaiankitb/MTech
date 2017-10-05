#include<stdio.h>
#include<strings.h>

int main()
{
	int pfd[2];
	char buff[50];
	int n=0,pid=-1;

	if(pipe(pfd)!=0)
	{
		printf("Error\n");
		return -1;
	}
	else
	{
		pid=fork();		
		if(pid>0)
		{
			printf("Parent Process %d says hello to child\n",getpid());			
			write(pfd[1],"Hello World!",12);
		}
		else if(pid==0)
		{
			n=read(pfd[0],buff,sizeof(buff));
			buff[n]='\0';
			printf("Child Process %d has got the message : %s\n",getpid(),buff);
		}
		else
		{
			printf("Error : In calling fork()");
			return -1;
		}
		
	}				
		
return 0;
}
