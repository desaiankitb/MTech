#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>

#define MAX 100

int main()
{
	int cd,sd,n,clilen,pid;
	struct sockaddr_in servaddr,cliaddr;
	int n_hops,s_hops;
	char data[MAX];
	
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(9701);

	sd = socket(AF_INET,SOCK_STREAM,0);
	bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

	listen(sd,10);
		
	for(; ;)
	{
		clilen = sizeof(cliaddr);
		cd = accept(sd,(struct sockaddr*)&cliaddr,&clilen);
		
		if((pid=fork())==0)
		{
			printf("In Child Process\n");
			close(sd);
			for(; ;)
			{
				n=read(cd,data,MAX);
				data[n]='\0';
				if(n==0)
				{
					printf("Client is closed\n");	
					exit(0);
				}
				write(cd,data,n);
			}
			exit(0);
		}
		close(cd);
	}

	close(sd);
	
	exit(0);
}
