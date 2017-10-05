#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<sys/select.h>
#include<sys/time.h>
#include<math.h>
#include<signal.h>
#define MAX 100

void sig_pipe(int signo)
{
	printf("SIGPIPE handled...\n");
}

int main()
{
	int sd,n,flag=1;
	struct sockaddr_in servaddr;
	char data[MAX];
	char out[]="exit";
	fd_set rset;
	int maxfd1=0;

	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(9701);

	sd = socket(AF_INET,SOCK_STREAM,0);

	connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	signal(SIGPIPE,sig_pipe);
	printf("Connection is established\n");
	
	bzero(data,sizeof(data));
	FD_ZERO(&rset);

		
	for(;;)
	{
		FD_SET( fileno(stdin) ,&rset);
			
		FD_SET( sd , &rset );
		
		maxfd1 =  (fileno(stdin) + sd) + 1;
		
		select(maxfd1 , &rset, NULL, NULL, NULL);
		
		if(FD_ISSET(fileno(stdin),&rset))
		{
			n = read(0,data,MAX);
			data[n] = '\0';
			write(sd,data,sizeof(data));
			//sleep(1);
			//write(sd,data,sizeof(data));
			bzero(data,sizeof(data));
		}
		if(FD_ISSET(sd,&rset))
		{
			n = read(sd,data,MAX);
			data[n] = '\0';
			write(1,data,sizeof(data));
			bzero(data,sizeof(data));
		}
	}
	close(sd);
	
	exit(0);
}
