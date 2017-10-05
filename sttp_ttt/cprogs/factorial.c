/*
	factorial.c
*/
#include <stdio.h>

int depth = 0;
int factorial(int n){
	int f;
	
	
	printf("%*s call arg n: %d\n",depth, " ", n);
	if(n <= 1){
		printf("\n%*s n = 1, returns: 1",depth); 
		return 1;
	}
	depth++;
	f =  n*factorial(n-1);
	depth--;
	printf("\n %*s n = %d, returns: %d", depth, " ",n, f);
	return f;
}
int main(int argc, char *argv[]){
	int n;
	
	if(argc < 2){
		printf("Usage: %s <n>\n", argv[0]);
		n = 3;
	} else {
		n = atoi(argv[1]);
	}
	printf("\nFactorial(%d) = %d\n", n, factorial(n));
}
