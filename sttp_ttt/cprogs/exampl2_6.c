#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int i;
   pid_t childpid;
   int n;
   
   if (argc != 2) {
	fprintf(stderr, "Usage : %s <no_processes>\n", argv[0]);
        exit(1);
   }
   fprintf(stderr, "Start: my PID = %ld\n", getpid());
   n = atoi(argv[1]);

   childpid = 0;
   
   for (i = 1; i< n; ++i)
       if ((childpid = fork()) <= 0)
       		break;
   fprintf(stderr, "\ni:%d  process ID:%ld   parent ID:%ld   child ID:%ld\n",
		    i, (long)getpid(), (long)getppid(), (long)childpid); 
		    
/*   sleep(3); */		    
   exit(0);
}
