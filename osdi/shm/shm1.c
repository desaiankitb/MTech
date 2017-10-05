#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int main()
{
	pid_t pida[2];
	int pid;
	char buffer[1024];
	pid = fork();
	if(pid != 0)
	{
	printf("from write end:%s\n",strcpy((shmat(shmget((key_t)2,(size_t)1024,IPC_CREAT|0666),NULL,0)),"hello world\n"));
	}
	else
	{
		sleep(1);
		printf("from read end:%s\n",strcpy(buffer,shmat(shmget((key_t)2,(size_t)1024,0666),NULL,0)));
	}
}
