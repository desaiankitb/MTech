#include<stdio.h>
#include<strings.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

void handle(int signo)
{
	int cPid=-1;	
	int stat;
	while(cPid=waitpid(-1,&stat,WNOHANG)>0)
	{	
		printf("Process %d is terminated \n",cPid);
	}
return;
}

int main()
{
	int pfd[2];
	int n=0,pid[2],cPid;
	int status;

	signal(SIGCHLD,handle);
	if(pipe(pfd)!=0)
	{
		printf("Error\n");
		return -1;
	}
	else
	{
		pid[0]=fork();	
		if(pid[0]>0)
		{
			printf("Parent Process %d says hello to child\n",getpid());	
			pid[1]=fork();
			if(pid[1]>0)
			{
			}
			else if(pid[1]==0)
			{
				printf("Child Process %d will run 'sort' command\n",getpid());
				close(pfd[1]);
				dup2(pfd[0],0);
				close(pfd[0]);
				execl("/bin/sort","sort",(char *)NULL);
			}
			else
			{
				printf("Error : In calling fork() 2\n");
				return -1;
			}
		}
		else if(pid[0]==0)
		{
			printf("Child Process %d will run 'ls' command\n",getpid());
			close(pfd[0]);
			dup2(pfd[1],1);
			close(pfd[1]);
			execl("/bin/ls","ls","-l",(char *)NULL);
			
		}
		else
		{
			printf("Error : In calling fork() 1\n");
			return -1;
		}
		
	}				
		
return 0;
}
