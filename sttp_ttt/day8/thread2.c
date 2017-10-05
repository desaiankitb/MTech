#include <pthread.h>
#include <stdio.h>


void* thread_routine(void *dummy)
{
	printf( "thread_routine just started\n.");
	int i,j;
	// thread stuff 
	for (i=0; i<10; ++i)
	{
		for (j=0; j<100000000; ++j);	// for loop
		printf("hi I am in the thread!\n.");
	}

	printf("thread_routine exit\n.");
		
	pthread_exit(5);
}

int main()
{
	pthread_t my_thread;		// this a handle to our thread, similar to a file handle
	int i,j;
	pthread_create(&my_thread, NULL, thread_routine, 0);	// this call will start our thread

	for (i=0; i<15; i++)
	{
		for (j=0; j<100000000; ++j);	// for loop
		printf("Hi I am in the main()\n");
	}
	
	int *my_thread_retval = 0;
	pthread_join(my_thread,(void**)(&my_thread_retval));
		
	printf( "my_thread exited with: %d", *my_thread_retval);
	
	free( my_thread_retval);
	return 0;
}

