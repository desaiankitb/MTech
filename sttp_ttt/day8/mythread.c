#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t tot_cally;
sem_t tot_ticket;


void * call(void *para)
{
	int i;
	for(i=0;i<=10;i++)
	printf("Enter in cally");
}

int main()
{
	//init total no of tickets = 50 and total no of cally = 3
	sem_init( &tot_cally , 0 , 1 );
	sem_init( &tot_ticket , 0 , 50 );


	pthread_t call_thread;
 	pthread_create( &call_thread, NULL, call, 0);    // this call will start our thread make a call

	pthread_detach(call_thread);			// this here will detach the thread
	printf("Enter in main");
	return 0;
}





