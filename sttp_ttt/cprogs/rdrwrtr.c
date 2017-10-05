typedef int semaphore;

semaphore mutex = 1;
semaphore db = 1;
int rc = 0;

void reader(void){
	while(1){
		P(&mutex);
		rc++;
		if(rc == 1) P(&db);
		V(&mutex);
		read_database();
		P(&mutex);
		rc--;
		if(rc == 0) V(&db);
		V(&mutex);
		use_data();
	}
}

void writer(void){
	while(1){
		prepare_data();
		P(&db);
		write_database();
		V(&db);
	}
}
