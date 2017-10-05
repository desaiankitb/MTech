#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int i;
   pid_t childpid;
   int n, temp;
   
   if (argc != 2) {
	fprintf(stderr, "Usage : %s processes\n", argv[0]);
        exit(1);
   }

   n = atoi(argv[1]);

   childpid = 0;
   
   for (i = 1; i< n; ++i)
       if (childpid = fork())
            break;
   if (childpid == -1) {
	perror("The fork Failed");
        exit(1);
   }
/*   wait(); */
   fprintf(stderr, "\ni:%d  process ID:%ld   parent ID:%ld   child ID:%ld\n",
		    i, (long)getpid(), (long)getppid(), (long)childpid); 
		    
   sleep(5);		    
   exit(0);
}
