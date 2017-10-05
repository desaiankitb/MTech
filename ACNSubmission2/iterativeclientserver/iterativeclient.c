#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
	struct sockaddr_in serv,cliaddr;
	int sd,cd,n;
	char buf[5];
	int len=sizeof(cliaddr);

	serv.sin_family=AF_INET;
	serv.sin_port=htons(9500);
	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	sd=socket(AF_INET,SOCK_STREAM,0);

	connect(sd,(struct sockaddr *)&serv,sizeof(serv));

	n=read(0,buf,sizeof(buf));
	write(sd,buf,n);

	n=read(sd,buf,sizeof(buf));
	write(1,buf,n);

	return 0;
}
