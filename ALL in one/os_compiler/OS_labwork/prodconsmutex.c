
#include<semaphore.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <errno.h>
#define MAXNTHREADS 100
#define MAXITEMS 1000000
int min(int a,int b)
{
	if(a>b) return b;
	else 	return a;
}
int nitems;
struct {
	pthread_mutex_t mutex;
	int buff[MAXITEMS];
	int nput;
	int nval;
}shared ={
	PTHREAD_MUTEX_INITIALIZER
};
void *produce(void*), *consume(void*);

void *produce(void *arg)
{
	for(;;)
	{
		pthread_mutex_lock(&shared.mutex);
		if(shared.nput>=nitems)
		{
			pthread_mutex_unlock(&shared.mutex);
		return NULL;
	}
	shared.buff[shared.nput]=shared.nval;
	shared.nput++;
	shared.nval++;
	pthread_mutex_unlock(&shared.mutex);
	*((int*)arg)+=1; 
}
}
void * consume(void *arg)
{
	int i;
	for(i=0;i<nitems;i++)
	{
		if(shared.buff[i]!=i)
		printf("buff[%d]=%d\n",i,shared.buff[i]);
	}
	return NULL;
}

int main(int argc,char** argv)
{
	int i,nthreads,count[MAXNTHREADS];
	pthread_t tid_produce[MAXNTHREADS],tid_consume;
	if(argc!=3)
		printf("error\n");
		//err_quit("usage:prodcons2 <#items> <#threads>");
	nitems=min(atoi(argv[1]),MAXITEMS);
	nthreads=min(atoi(argv[2]),MAXNTHREADS);
	//set_concurrency(nthreads);
	for(i=0;i<nthreads;i++)
	{
		count[i]=0;
		pthread_create(&tid_produce[i],NULL,produce, &count[i]);
	}
	  
	for(i=0;i<nthreads;i++)
	{
		pthread_join(tid_produce[i],NULL);
		printf("count[%d]=%d\n",i,count[i]);
	}
	
	pthread_create(&tid_consume,NULL,consume,NULL);
	pthread_join(tid_consume,NULL);
	exit(0);
}
 
