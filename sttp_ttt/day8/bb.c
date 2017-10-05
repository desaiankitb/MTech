#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define BUFSIZE 10

/* Data shared by the two threads */

sem_t empty;
sem_t full;
sem_t mutex;
int buffer[BUFSIZE];

void *Producer ( void *arg ) {
    int iNextProduced = 0;
    int nextitem;
    do {
        nextitem = random()%1000;
        printf( "Producer produced item %d\n", nextitem );

        sem_wait( &empty );
        sem_wait( &mutex );

        buffer[iNextProduced] = nextitem;
        iNextProduced = (iNextProduced+1)%BUFSIZE;

        sem_post( &mutex );
        sem_post( &full );
    } while ( 1 );

    return NULL;
}

void *Consumer ( void *arg ) {
    int iNextConsumed = 0;
    int nextitem;
    do {
        sem_wait( &full );
        sem_wait( &mutex );

        nextitem = buffer[iNextConsumed];
        iNextConsumed = (iNextConsumed+1)%BUFSIZE;

        sem_post( &mutex );
        sem_post( &empty );

        printf( "Consumer consumed item %d\n", nextitem );

    } while ( 1 );

    return NULL;
}

int main( void ) {
    pthread_attr_t attr;
    pthread_t tid_Producer;
    pthread_t tid_Consumer;

    srandom( 123 );

    pthread_attr_init( &attr );
    sem_init( &mutex, 0, 1 );
    sem_init( &empty, 0, BUFSIZE );
    sem_init( &full, 0, 0 );

    pthread_create( &tid_Producer, &attr, Producer, NULL );
    pthread_create( &tid_Consumer, &attr, Consumer, NULL );

    pthread_join( tid_Consumer, NULL );
    pthread_join( tid_Producer, NULL );

    return 0;
}

