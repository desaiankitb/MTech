#define N 100

typedef int semaphore;
semaphore mutex = 1
semaphore empty = N;
semaphore full = 0;

void producer(void){
	int item;
	
	while(1){
		produce_item(&item);
		P(&empty);
		P(&mutex);
		enter_item(item);
		V(&mutex);
		V(&full);
	}
}

void consumer(void){
	int item;
	
	while(1){
		P(&full);
		P(&mutex);
		remove_item(&item);
		V(&mutex);
		V(&empty);
		consume_item(item);
	}
}