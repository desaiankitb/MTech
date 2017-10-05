#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sleeprand(){
	int r;
	r = 1+(int) (1000000.0*rand()/(RAND_MAX+1.0));
	usleep(r);
}
int main(int argc, char *argv[]){
	int pid;
	int x = 999;

	if( (pid = fork()) == -1){
		perror("Fork:");
		exit(-1);
	}
	if(pid == 0) {
		x = 222;
		printf("1. I am child: x = %d\n", x);
		sleeprand();
		printf("2. I am child: x = %d\n", x);
		sleeprand();
		printf("3. I am child: x = %d\n", x);
		sleeprand();
		printf("4. I am child: x = %d\n", x);
		sleeprand();
		printf("5. I am child: x = %d\n", x);
	} else {
		printf("1. I am parent: x = %d\n", x);
		sleeprand();
		printf("2. I am parent: x = %d\n", x);
		sleeprand();
		printf("3. I am parent: x = %d\n", x);
		sleeprand();
		printf("4. I am parent: x = %d\n", x);
		sleeprand();
		printf("5. I am parent: x = %d\n", x);
	}
	return 0;
}
