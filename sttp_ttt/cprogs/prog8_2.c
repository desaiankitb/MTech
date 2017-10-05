#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <sys/sem.h> 
#include <semaphore.h>


int main(int argc, char *argv[])
{
  char buffer[MAX_CANON];
  char *c;
  int i,n;
  pid_t childpid;
  struct sem_t my_lock;
  
  if ((argc !=2) || ((n = atoi(argv[1])) <= 0)) {
  	fprintf(stderr, "Usage: %s number_of_processes\n", argv[0]);
  	exit(1);
  }
  if (sem_init(&my_lock, 1 ,1) == -1) {
  	printf("Could not initialize mylock semaphore");
  	exit(1);
  }
  for (i=1; i< n; ++i)
    if (childpid = fork())
       break;

  sprintf(buffer, "i:%d process ID :%ld parent ID : %ld child ID : %ld\n",
  		   i, (long) getpid(), (long) getppid(), (long) childpid);
  c = buffer;
  
  /* entry section */
  if (sem_wait(&my_lock) == -1) {
     fprintf(stderr, "Semaphore Invalid");
     exit(1);
  }
  
  while(*c !='\0') {
  	fputc(*c, stderr);
  	c++;
  }
  fputc('\n', stderr);
  
  if (sem_post(&my_lock) == -1) {
     fprintf(stderr, "Semaphore done");
     exit(1);
  }
  exit(0);       
}
  
  