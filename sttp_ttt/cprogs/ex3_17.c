/*
 * ex3_17.c
*/ 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void main(void){
	int fd;
	int n;
	char buffer[100];
	
	mode_t fd_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if( (fd = open("myfile", O_WRONLY |O_CREAT, fd_mode) ) == -1)
		perror("cound not open myfile");
	else {	
		if(dup2(fd, STDOUT_FILENO) == -1)
			perror("could not redirect STDOUT");
		n = read(0, buffer, 100);
		write(1, buffer, n);		
		close(fd);
	}
}