/* 
	timing.c
	see how to use gettimeofday()
*/
#include <stdio.h>
#include <sys/time.h>  /* for gettimeofday(), timeval_t */

void f1(int n){
	int a = 0;
	while(n--){
		a += 1;
	}
}

void f2(int n){
	int a = 0;
	while(n--){
		a *= 1.01;
	}
}
float timediff(struct timeval *t2, struct timeval *t1){
	int sec, usec;
	
	sec = t2->tv_sec - t1->tv_sec;
	usec = t2->tv_usec - t1->tv_usec;
	return (float) sec+ usec*1e-6;
}
int main(int argc, char *argv[]){
	struct timeval t1, t2, t3;
	int n;
	
	if(argc < 2)
		n = 1000000;
	else n = atoi(argv[1]);
		
	gettimeofday(&t1, NULL);
	f1(n);
	gettimeofday(&t2, NULL);
	f2(n);
	gettimeofday(&t3, NULL);
	printf("n=%d: f1 %f, f2 %f\n", n, timediff(&t2, &t1), timediff(&t3, &t2)); 
}
