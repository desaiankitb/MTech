#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
main(int argc,int *argv[])
{
        int fp,i;
	ssize_t n;
	char buf[100];


for(i=1;i<argc;i++)
	{
		printf("file=%d",i);
        	fp=open(argv[i],O_RDONLY,S_IRUSR);
        	if(fp==-1)
        	{
                	printf("file not exsist");
        	}
        	else
        	{ 
			do
			{
                		n=read(fp,buf,2);
			
				write(1,buf,n);
			}
		while(n!=0);

        	}	
		printf("\n");	
	}
 }
