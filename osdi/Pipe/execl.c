#include<stdio.h>
#include<strings.h>
#include<unistd.h>

int main()
{
	int id;

	id=fork();		
	if(id>0)
	{
		printf("In Parent Process\n");
	}
	else
	{
		printf("In Child Process now running 'ls' command\n");
		execl("/bin/ls","ls","-l",(char *)NULL);
	}
	return 0;
}
