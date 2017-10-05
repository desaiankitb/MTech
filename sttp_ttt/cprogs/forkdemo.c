#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int pid;
	
	if( (pid = fork()) == -1){
		perror("Fork:");
		exit(-1);
	} 
	if(pid == 0) {
		printf("I am child, pid = %d, parent = %d\n", 
				getpid(), getppid());
	} else {
		printf("I am parent, pid = %d, parent = %d\n", 
		                getpid(), getppid());
	}
	return 0;
}
