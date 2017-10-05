#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

long count=0;
//FILE* fd;
void produce(void *buff)
{
	int i;
	int *buffer = (int *)buff;
	FILE *fdp;
	fdp = fopen("producted.txt","w+");
	fclose(fdp);
	while(1)
	{
		for(i=0;i<10000;i++)
		{
			if(count==10000)sleep(2);
			buffer[i] = i;
			fdp = fopen("producted.txt","a");
			count++;
			printf("producted=%d count=%ld\n",i,count);
			fprintf(fdp,"produced=%d count=%ld\n",i,count);
			fclose(fdp);
		}
	}
}
void consume(void *buff)
{
	int i;
	int *buffer = (int *)buff;
	long possition_in_file = 0;
	FILE *fdc;
	fdc = fopen("consumted.txt","w+");
	fclose(fdc);
	
	while(1)
	{
		for(i=0;i<10000;i++)
		{
			if(count==0)sleep(1);
			fdc = fopen("consumted.txt","a");
			buffer[i]=0;	
			count--;
			printf("consumed=%d count=%ld\n",i,count);
			fprintf(fdc,"consumed=%d count=%ld\n",i,count);	
			fclose(fdc);
		}
	}
}
int main()
{
	pthread_t producer,consumer;
	int buffer[10000];

	pthread_create(&producer,NULL,(void *) &produce,(void *)&buffer);

	pthread_create(&consumer,NULL,(void *) &consume,(void *)&buffer);
	pthread_join(producer,NULL);

	
	pthread_join(consumer,NULL);

	return 0;

}

