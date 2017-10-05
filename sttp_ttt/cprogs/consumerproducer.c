#define N 100

int count = 0;

void producer(void){
	int item;
	
	while(1){
		produce_item(&item);
		if(count == N) sleep(); /* if buffer full */
		enter_item(item);
		count++;
		if(count == 1) wakeup(consumer);
	}
}

void consumer(void){
	int item;
	
	while(1){
		if(count == 0) sleep(); /* if buffer empty */
		remove_item(&item);
		count--;
		if(count == N-1) wakeup(producer);
		consume_item(item);
	}
}