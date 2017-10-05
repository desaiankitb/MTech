/*
	modified version of client_server_fifo2.c
	tracing printf's added.
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

int main ()
{
  int readfd, writefd;

  pid_t childpid;

  if ((mkfifo (FIFO1, FILE_MODE) < 0) && errno != EEXIST)
  {
      perror ("Can't create Fifo1: ");
  }
  if ((mkfifo (FIFO2, FILE_MODE) < 0) && errno != EEXIST)
  {
      perror ("Can't create Fifo2: ");
      unlink (FIFO1);
  }
  /* printf("FIFOs made\n"); */
  if ((childpid = fork ()) == 0) /* CHILD */
  {

      if ((writefd = open (FIFO1, O_WRONLY))==-1) {
      	perror ("Can't opem Fifo1: ");
      }

      if((readfd = open(FIFO2, O_RDONLY))==-1) {
      	perror ("Can't opem Fifo1: ");
      }

      /* printf("\n Child calling server\n"); */
      server(readfd, writefd);
    
      exit (0);
  }  /* end CHILD */
  
   /* printf("Chlld Forked\n"); */
  if ((readfd = open(FIFO1, O_RDONLY))==-1) {
     perror("Open Readfd");
     exit(-1);
  }
  /* printf("\n readfd opened\n"); */
  if ((writefd = open(FIFO2, O_WRONLY))==-1) { 
     perror("Open Readfd");
     exit(-1);
  }
  /* printf("\n writefd opened\n"); */
  /* printf(" \n About to call client\n"); */

  client(readfd, writefd);

  waitpid (childpid, NULL, 0);

  unlink (FIFO1);
  unlink (FIFO2);
  exit (0);
}

