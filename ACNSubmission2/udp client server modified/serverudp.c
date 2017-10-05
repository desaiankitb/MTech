#include<stdio.h>
#include <sys/socket.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <netdb.h>
#include<string.h>

int main()
{
	int sd=socket(PF_INET,SOCK_DGRAM,0);
	struct sockaddr_in name;

	name.sin_family = AF_INET;
        name.sin_port = htons (9500);
	name.sin_addr.s_addr=inet_addr("127.0.0.1");
	

	if(bind(sd,(struct sockaddr *) &name,sizeof (name))<0)
	{
	printf("Cannot bind\n");
	}
	//printf("1\n");
	char buff[20];

	struct sockaddr clad;
	int len=sizeof(clad);
	//printf("2\n");
	while(1)
	{
		//printf("3\n");
		int n=recvfrom(sd, buff, 20, 0,(struct sockaddr*) &clad, &len);
		printf("data received : %d\n",n);
		int s=sendto (sd, buff,n,0, (struct sockaddr*) &clad, len);
		printf("data sent : %d\n",s);
	}

}
