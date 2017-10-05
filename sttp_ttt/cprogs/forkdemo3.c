#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int pid;

	printf("1. Start \n");	
	if( (pid = fork()) == -1){
		perror("Fork:");
		exit(-1);
	}
	if(pid == 0) {
		printf("I am child, pid = %d, parent = %d\n", 
				getpid(), getppid());
	} else {
		printf("I am parent, pid = %d\n", getpid());
	}
	printf("2. End\n");
	return 0;
}
