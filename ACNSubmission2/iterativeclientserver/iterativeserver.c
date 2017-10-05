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

bind(sd,(struct sockaddr *)&serv,sizeof(serv));

listen(sd,8);

cd=accept(sd,(struct sockaddr *)&cliaddr,&len);

n=read(cd,buf,sizeof(buf));

write(cd,buf,n);
                                                                                                                                                                                                                                                   
return 0;
}
