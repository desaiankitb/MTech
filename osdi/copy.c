#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	int fdr[10],i,index,fdw;
	char buf;
	if(argc <= 1)
	{
		write ( 1 , "Pass arguments" , 15 );
		_exit(0);
	}
	for(index = 1; index <= argc-1; index++)
	{
		fdr[index] = open( argv[index]  , O_RDONLY );
	}
	fdw = open( argv[argc] , O_WRONLY | O_APPEND);
	index=1;
	while(index <= argc-1)
	{
		if( fdr[index] > 0 )
		{
			while( (i = read ( fdr[index] , &buf , 1 )) > 0 )
			{	
				write ( fdw , &buf , 1 );
			}
		}
			
		else
			write ( 1 , "ERR\n" , 5);		
		index++;
	}
	
	for(index = 1; index < argc; index++)
		close(fdr[i]);
	return 0;
}
