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
int buffer[10000];
FILE *fdc;
FILE *fdp;

void produce(/*void *buff*/)
{
	int i;
	//int *buffer = (int *)buff;
	fdp = fopen("producted.txt","w+");
	fclose(fdp);
	while(1)
	{
		for(i=0;i<=10000;i++)
		{
						
			if(count==10000){sleep(2);count=0;}
			buffer[i] = i;
			fdp = fopen("producted.txt","a");
			count++;
			//printf("producted=%d by %u count=%ld\n",i,(unsigned int)pthread_self(),count);
			fprintf(fdp,"produced=%d  by %u \n",i,(unsigned int)pthread_self());
			fclose(fdp);
		}
	}
}
void consume(/*void *buff*/)
{
	int i;
	//int *buffer = (int *)buff;
	fdc = fopen("consumted.txt","w+");
	fclose(fdc);

	
	while(1)
	{
		for(i=0;i<=10000;i++)
		{
						
			if(count==0)sleep(1);
			fdc = fopen("consumted.txt","a");
			//buffer[i]=0;
			count--;
			//printf("consumed=%d  by %u count=%ld\n",i,(unsigned int)pthread_self(),count);
			fprintf(fdc,"Item %d consumed at=%d by %u \n",buffer[i],i,(unsigned int)pthread_self());	
			fclose(fdc);
		}
	}
}
int main()
{
	pthread_t producer[2],consumer[2];
	
	int i;
	for(i=0;i<=1;i++){
		pthread_create(&producer[i],NULL,(void *) &produce,/*(void *)&buffer*/NULL);
		pthread_create(&consumer[i],NULL,(void *) &consume,/*(void *)&buffer*/NULL);
	}
	for(i=0;i<=1;i++){
		pthread_join(producer[i],NULL);
		pthread_join(consumer[i],NULL);
	}

	return 0;

}

