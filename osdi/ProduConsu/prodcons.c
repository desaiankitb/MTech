#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


#define MAX 1000

long count=0,in=0,out=0;
long array[MAX];
int continue_check=1;

void producer()
{
	while(continue_check)
	{
		if(count<MAX)
		{
			array[in]=in;
			printf("Producer : Item %ld produced\n",in);
			count++;
			in = (in+1)%MAX;
		}
	}
}

void consumer()
{
	while(continue_check)
	{
		while(count==0);
			
		if((array[out]!=out) && array[out]>-1)
		{
			continue_check=-1;
			printf("Race condition at %ld : in thread %u\n",out,pthread_self());
			return;			
		}
		else
		{
			printf("Consumer : Item %ld consumed at index %ld\n",array[out],out);
			count--;
			out=(out+1)%MAX;
		}
	}
}

int main()
{
	pthread_t producer_thread[20];
	pthread_t consumer_thread[20];
	int i=0;
	long index=0;
	
	for(index=0;index<MAX;index++)
		array[index]=-1;
		
	for(index=0;index<20;index++)
	{	
		pthread_create(&producer_thread[index],NULL,(void *)producer,NULL);
		pthread_create(&consumer_thread[index],NULL,(void *)consumer,NULL);
	}

	for(i=0;i<20;i++)
	{
		pthread_join(producer_thread[i],NULL);
		pthread_join(consumer_thread[i],NULL);
	}

	
	return 0;
}
