#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/ipc.h>
int main()
{
	int seg_id,key=77,c;
	char *shm;
	const int size=4096;
	seg_id=shmget(key,size,IPC_CREAT|0666);
	printf("%d",seg_id);
	shm=(char*)shmat(seg_id,NULL,0);
	sprintf(shm,"hi");
	sleep(10);
	printf("%s",shm);
	c=strcmp(shm,"completed");
	if(c==0)
		printf("alrady read");
	else
		printf("not read");
	return 0;
	shmdt(shm);

}

