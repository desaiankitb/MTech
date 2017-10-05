#include<stdio.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <netdb.h>
#include<string.h>

int main()
{
	int sd=socket(PF_INET,SOCK_DGRAM,0);
	
	struct sockaddr_in name,reply;

	name.sin_family = AF_INET;
        name.sin_port = htons (9500);
	name.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	char buff[20];
	int len=sizeof(name);
	while(1)
	{
		int n=read(0,buff,sizeof(buff));
		int s=sendto (sd, buff,n,0, (struct sockaddr*) &name, len);
		printf("data sent : %d\n",s);
		n=recvfrom(sd, buff, 20, 0,(struct sockaddr*) &name, &len);
		if( n != sizeof(name) || memcmp(&name,&reply,n) != 0 ){
			printf("reply (ignored)\n");
			continue;
		}
		printf("data received : %d\n",n);
		write(1,buff,n);
	}
	close(sd);
}
