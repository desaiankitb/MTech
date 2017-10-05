#define CHAIRS 5

typedef int semaphores;

semaphore customers = 0;
semaphore barbers = 0;
semaphore mutex = 1;
int waiting = 0;

void barber(void){
	while(1){
		P(&customers);
		P(&mutex);
		waiting--;
		V(&barbers);
		V(&mutex);
		cut_hair();
	}
}

void customer(void){
	P(&mutex);
	if(waiting < CHAIRS){
		waiting++;
		V(&customers);
		V(&mutex);
		P(&barbers);
		get_haircut();
	} else {
		V(&mutex);
	}
}