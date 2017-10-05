#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t childpid;
	int status;

	
	if((childpid = fork()) == -1){
		perror("Error: fork()");
		exit(1);
	}
	if(childpid == 0){ /* child code */
		sleep(5);
		if(execl("/usr/bin/ls", "ls", "-l", NULL) < 0){
			perror("Execution of ls failed");
			exit(1);
		}
	} else  {          /* parent code */
		alarm(2);
		if(childpid != wait(&status))
			perror("A signal occurred before child exited");
		else printf("Child exited\n");
	}
		fflush(stdout);
		fflush(stderr);
		exit(0);
}
