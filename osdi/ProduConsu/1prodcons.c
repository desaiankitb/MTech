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
			printf("Race condition at %ld\n",out);
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
	pthread_t producer_thread;
	pthread_t consumer_thread;
	int i=0;
	long index=0;
	
	for(index=0;index<MAX;index++)
		array[index]=-1;
		
	pthread_create(&producer_thread,NULL,(void *)producer,NULL);
	pthread_create(&consumer_thread,NULL,(void *)consumer,NULL);
	

	pthread_join(producer_thread,NULL);
	pthread_join(consumer_thread,NULL);
	

	
	return 0;
}
