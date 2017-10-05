/*
	fifo2.c
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>


#define   FIFO1 "/tmp/fifo.1"
#define   FIFO2 "/tmp/fifo.2"

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP |S_IROTH)

#define MAXLINE 4096

typedef struct fifopair {
	int rd;
	int wr;
} fifo_pair_t;

client(int rd, int wr){
	printf("client called with %d %d\n", rd, wr);
}
server(int rd, int wr){
	printf("server called with %d %d\n", rd, wr);
}
int mkfifos(){
  if ((mkfifo (FIFO1, FILE_MODE) < 0) && errno != EEXIST)
  {
      perror ("Can't create Fifo1: ");
  }
  if ((mkfifo (FIFO2, FILE_MODE) < 0) && errno != EEXIST)
  {
      perror ("Can't create Fifo2: ");
      unlink (FIFO1);
  }
   printf("FIFOs made\n"); 
}
/*------------- open fifos -----------------------*/
int open_fifos(char *fifo1, char * fifo2, fifo_pair_t *f){
/* first for reading from, second for writing to */

      if ((f->wr = open (fifo2, O_RDWR))==-1) {
      	perror ("Can't open fifo to write");
	return 0;
      }

      if((f->rd = open(fifo1, O_RDWR))==-1) {
      	perror ("Can't open fifo to read");
	return 0;
      }
	return 1;
}
int main ()
{
  pid_t childpid;
  fifo_pair_t f;
  
  mkfifos();

  if ((childpid = fork ()) == 0) /* CHILD */
  {
      open_fifos(FIFO2, FIFO1, &f); 
       printf("\n Child calling server\n"); 
      server(f.rd, f.wr);
      exit (0);
  }  /* end CHILD */
  
    printf("Chlld Forked\n"); 
  
      open_fifos(FIFO2, FIFO1, &f); 
   printf(" \n About to call client\n"); 

  client(f.wr, f.rd);

  waitpid (childpid, NULL, 0);
}

