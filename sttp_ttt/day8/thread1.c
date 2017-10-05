/*detachable thread example*/
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t tot_cally;
sem_t tot_ticket;
void* cally(void*);

pthread_t call_thread;	   			// this a handle to our thread, similar to a file handle
pthread_t cally_thread;

void* call_thread_routine(void *dummy)
{
	int value,i=0,sem_val_cally;
	sem_getvalue(&tot_ticket,&value);


	if(value == 0)
	{
		printf("\n FULL");
		exit(-1);
	}
	if(value>0 || value<=10)
	{
		pthread_create( &cally_thread, NULL, cally, 0);
		pthread_join(cally_thread,(void **)(cally_thread));	// this here will detach the thread
		sem_getvalue(&tot_cally,&sem_val_cally);
		if( value > 0 && sem_val_cally>0 )
		{
			printf("\n Ticket no::%d sold",value);
			sem_wait(&tot_ticket);
		}
		else
		{
			
		}
	}
}
void* cally(void *arg)
{
	int value1,i=0,choice;
	char temp;
	sem_getvalue(&tot_cally,&value1);
	printf(" cally no. %d::\n",value1);
	if(value1==0)
	{
		do
		{
			printf(" whoule u like to stop any call?? (0:no/1:yes)::");
			scanf("%d",&i);
			if(i==1)
			{
				sem_post(&tot_cally);
			}
			else if(i>1)
			{
				break;
			}
			else
			{
				
				printf("\n\n All are busy");
				break;
			}
			printf(" \nMore stop?:");
			scanf("%d",&choice);
		}while(choice!=0);
	}
	else
	{
			sem_wait(&tot_cally);
	}
}

int main()
{
	
	int choice=1;
	
	sem_init( &tot_cally , 0 , 3 );
	sem_init( &tot_ticket , 0 , 10 );
	
		do
		{
			printf(" \nAny other calls?(1/0)");
			scanf("%d",&choice);
			if(choice == 0)
				break;
			pthread_create(&call_thread, NULL, call_thread_routine, 0);	// this call will start our thread
			pthread_join(call_thread,(void **)(call_thread));	// this here will detach the thread
		}while(choice != 0);
	
	return 0;
}

