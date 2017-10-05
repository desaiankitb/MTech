#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>
#include<time.h>

#define MAXLINE 1024

void handle_intr()
{
	printf("handled signal\n");
}

 int main(int argc, char **argv)
 {
      int      i, maxi, maxfd, listenfd, connfd, sockfd;
      int      nready, client[FD_SETSIZE];
      ssize_t n;
      fd_set rset, allset;
      char     buf[MAXLINE];
      socklen_t clilen;
      struct sockaddr_in cliaddr, servaddr;


	sigset_t newmask,oldmask,zeromask;
	int intr_flag=0,errno;

	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGINT);
     
	 
      listenfd = socket(AF_INET, SOCK_STREAM, 0);
      bzero(&servaddr, sizeof(servaddr));
      
      servaddr.sin_family = AF_INET;
      servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
      servaddr.sin_port = htons(9500);
      
      bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
      listen(listenfd, 5);
      maxfd = listenfd;
      maxi = -1;
      for (i = 0; i < FD_SETSIZE;i++)
	client[i] = -1;
      FD_ZERO(&allset);
      FD_SET(listenfd, &allset);

	sigprocmask(SIG_BLOCK,&newmask,&oldmask);

     for ( ; ; ) {
		
          rset = allset;           /* structure assignment */
	if(intr_flag)
		handle_intr();
          if (nready = pselect(maxfd + 1, &rset, NULL, NULL, NULL,&zeromask) < 0 )
		{
			if(errno == EINTR)
				if(intr_flag)
					handle_intr();
		} 
          if (FD_ISSET(listenfd, &rset)) {         /* new client connection */
               clilen = sizeof(cliaddr);
               connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
               for (i = 0; i < FD_SETSIZE; i++)
                   if (client[i] < 0) {
                       client[i] = connfd; /* save descriptor */
                       break;
                   }
               if (i == FD_SETSIZE)
                   printf("too many clients\n");
               FD_SET(connfd, &allset);        /* add new descriptor to set */
               if (connfd > maxfd)
                   maxfd = connfd; /* for select */
               if (i > maxi)
                   maxi = i;          /* max index in client[] array */
               if (--nready <= 0)
                   continue;          /* no more readable descriptors */
        }
        for (i = 0; i <= maxi; i++) {         /* check all clients for data */
             if ( (sockfd = client[i]) < 0)
                  continue;
             if (FD_ISSET(sockfd, &rset)) {
                  if ( (n = read(sockfd, buf, MAXLINE)) == 0) {
                          /* connection closed by client */
                      close(sockfd);
                      FD_CLR(sockfd, &allset);
                      client[i] = -1;
                  } else{
			write(1,buf,n);
                      write(sockfd, buf, n);
			sleep(1);
                      write(sockfd, buf, n);
			
		}
                  if (--nready <= 0)
                      break;         /* no more readable descriptors */
             }
        }
   }
 }
