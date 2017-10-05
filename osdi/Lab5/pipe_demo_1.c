#include<stdio.h>

int main()
{
	int pfd[2];

	if(pipe(pfd)!=0)
	{
		printf("Error\n");
	return -1;
	}
	else
	{
		printf("Pipe read end desc is %d\n",pfd[0]);
		printf("Pipe write end desc is %d\n",pfd[1]);
	}
return 0;
}
