#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>   /* for sleep()  */               
               
/*
       void  *  mmap(void  *start,  size_t length, int prot , int
              flags, int fd, off_t offset);
              
       int munmap(void *start, size_t length);
*/ 

int main(){
	char *p;
	int fd;
	int i;
	
	fd = open("buffer", O_RDWR); 
	if(fd == -1){
		perror("Error in open"); exit(1);
	}
	p = (char *)mmap(0, 4096, PROT_WRITE, MAP_SHARED, fd, 0);
	if((int)p == -1){
		perror("Error in mmap"); exit(2);
	}
	for(i = 0; i<1000; i++){
		sprintf(p,"%d", i);
		printf("%s\n", p);
		sleep(1);
	}
}
             