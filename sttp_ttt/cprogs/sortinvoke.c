/*
 * 	sortinvoke.c
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static sortinvoke(){
	int pfdout[2], pfdin[2], fd, nread;
	char buff[512];
	
	if(pipe(pfdout) == -1 || pipe(pfdin) == -1){
		perror("pipe");
		exit(-1);	
	}
	switch(fork()){
		case -1: perror("fork"); exit(-1);
		case 0: if(close(0) == -1) perror("close");
			if(dup(pfdout[0]) != 0){
				perror("dup"); 
				exit(-2);
			}
			if(close(1) == -1) perror("close");
			if(dup(pfdin[1]) != 1){
				perror("dup2"); 
				exit(-3);
			}	
			if(close(pfdout[0]) == -1 ||
			   close(pfdout[1]) == -1 ||
			   close(pfdin[0]) == -1 
			   || close(pfdin[1]) == -1)
				perror("close"); 
			execlp("sort", "sort",  NULL);
			perror("execlp"); 
			exit(-4);
		default: break;	
	}
	if(close(pfdout[0]) == -1 || close(pfdin[1]) == -1)
	       perror("close");
	if((fd = open("sortdata.txt",0)) == -1)
		perror("open");
	while((nread = read(fd, buff, sizeof(buff))) != 0){
		if(nread == 1) perror("read");
		if(write(pfdout[1], buff, nread) == -1)
			perror("write");
	}	
	if(close(fd) == -1 || close(pfdout[1]) == -1)
			perror("close");
	while((nread = read(pfdin[0], buff, sizeof(buff))) != 0){
		if(nread == -1) perror("read");
		if(write(1, buff, nread) == -1)
			perror("write");
	
	}
	if(close(pfdin[0]) == -1) perror("close");
}


int main(){
	sortinvoke(); 
	exit(0);
}


