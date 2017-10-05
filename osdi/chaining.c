#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
 	int i=11,j=0;
	 int retval,flag=0;
	retval = fork();
	if(retval==0)
	{
		for(i=0;i<atoi(argv[1]);i++) 
 		{
    			if(retval>0)
      		{
			}
    			else
      		{
			printf("child id: %d and  my parent is %d\n",getpid(),getppid());
			sleep(1);
			retval = fork();
			}		
		}
	}
return 0;	
}
