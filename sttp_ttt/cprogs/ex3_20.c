/*
 * ex3_20.c
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void main(void){
	int fd[2];
	pid_t childpid;
	pipe(fd);
	if( (childpid = fork()) == 0){
		/* CHILD */
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execl("/usr/bin/ls", "ls", "-l", NULL);
		perror("execution of ls failed");	
	} else {
		/* PARENT */
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execl("/usr/bin/sort", "sort", "-n", "+4", NULL);
		perror("execution of sort failed");
	}
	exit(0);
}