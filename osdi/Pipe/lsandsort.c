#include<stdio.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int main()
{
	int pfd[2];
	int pid[2];

	pipe(pfd);
	pid[0]=fork();	
	if(pid[0]>0)
	{
		printf("In Parent Process\n");	
		pid[1]=fork();
		if(pid[1]>0)
		{
		}
		else
		{
			printf("In Child Process : running 'sort' command\n");
			close(pfd[1]);
			dup2(pfd[0],0);
			close(pfd[0]);
			execl("/bin/sort","sort",(char *)NULL);
		}
	}
	else
	{
		printf("In Child Process: running 'ls' command\n");
		close(pfd[0]);
		dup2(pfd[1],1);
		close(pfd[1]);
		execl("/bin/ls","ls","-l",(char *)NULL);
	}	
return 0;
}
