#include<stdio.h>
#include<strings.h>
#include<unistd.h>

int main()
{
	int pid=-1,cPid=-1;
	int status;

	pid=fork();		
	if(pid>0)
	{
		printf("Parent Process %d \n",getpid());
		cPid=waitpid(pid,&status,0);			
	}
	else if(pid==0)
	{
		printf("Child Process %d now running 'ls' command\n",getpid());
		execl("/bin/ls","ls","-l",(char *)NULL);
	}
	else
	{
		printf("Error : In calling fork()");
		return -1;
	}				
		
return 0;
}
