#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


#define MAX 2048

void sig_pipe(int signo)
{
	printf("signal handled\n");
}

int main()
{
	int sd,n,flag=1;
	struct sockaddr_in servaddr;
	char data[MAX];
	char out[]="exit";
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("192.168.34.22");
	servaddr.sin_port = htons(9701);

	sd = socket(AF_INET,SOCK_STREAM,0);
	
	connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

	printf("Connection is established\n");
	signal( SIGPIPE, sig_pipe );
	while(1)
	{
		data[0]='\0';
		n=read(0,data,sizeof(data));
		
		flag = strncmp(data,out,4);
		
		printf("Flag is %d:\n",flag);
		if(!flag)
			break;
		
		write(sd,data,n);
		sleep(1);
		write(sd,data,n);
		data[0]='\0';
		n=read(sd,data,sizeof(data));
		write(1,data,n);
	}

	close(sd);
	
	exit(0);
}
