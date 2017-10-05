#define N 5
#define LEFT (i-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY   1
#define EATING   2

typedef int semaphore
int state[N];
semaphore mutex = 1; 
semaphore s[N];

void philo(int i){
	while(1){
		think();
		take_forks(i);
		eat();
		put_forks(i);
	}
}
void take_forks(int i){
	P(&mutex);
	state[i] = HUNGRY;
	test(i);
	V(&mutex);
	P(&s[i]);
}
void put_forks(int i){
	P(&mutex);
	state[i] = THINKING;
	test(LEFT);
	test(RIGHT);
	V(&mutex);
}
void test(int i){
	if(state[i] == HUNGRY && state[LEFT] != EATING && 
	               state[RIGHT] != EATING){
		state[i] = EATING;
		V(&s[i]);
	} 
}
