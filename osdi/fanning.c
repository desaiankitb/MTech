#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	int i=11,j=0;
	int retval;
	retval = fork();
	
if(retval>0)
{
	for(i=0;i<atoi(argv[1]);i++) 
 	{
    		if(retval==0)
      		{	
        		
      		}
		else
		{
			printf("i=%d, retval = %d, parent %d and  my child is %d \n",i,retval,getpid(),retval);
			sleep(1);
			retval = fork();
		}
	}
}
return 0;	
}
