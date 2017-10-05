/*
	fifo3.c
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define   FIFO1 "/tmp/fifo.1"
#define   FIFO2 "/tmp/fifo.2"

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP |S_IROTH)

#define MAXLINE 4096

typedef struct fifopair {
	int rd;
	int wr;
} fifo_pair_t;


void
client (int readfd, int writefd)
{
  size_t len;
  ssize_t n;
  char buff[MAXLINE];
  
  

  printf("\n Please input the name of the file to be sent\n");
  fgets (buff, MAXLINE, stdin); 
  
  len = strlen (buff);
  if (buff[len-1] == '\n')
    buff[len-1] = '\0';
  write (writefd, buff, len);
  while ((n = read (readfd, buff, MAXLINE)) > 0)
    write (1, buff, n);
}

void
server (int readfd, int writefd)
{
  int fd;
  ssize_t n;
  char buff[MAXLINE];
  /* printf("Server started\n"); */
  /* printf("Server reading from readfd\n"); */

  while ((n = read (readfd, buff, MAXLINE)) == 0);
       /*printf ("end of file while reading pathname"); */
  buff[n] = '\0';


/* strcpy(buff, "test.txt"); */ /* temporary test file name */

  if ((fd = open (buff, O_RDONLY)) < 0)
    {
      snprintf (buff + n, sizeof (buff) - n, ": can't open %s\n",
		strerror (errno));
      n = strlen (buff);
      write (writefd, buff, n);
    }
  else
    {
/* printf("data fd = %d\n", fd); */	    
      while ((n = read (fd, buff, MAXLINE)) > 0)
	{
	  write (writefd, buff, n);
	}
      close (fd);

    }
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

