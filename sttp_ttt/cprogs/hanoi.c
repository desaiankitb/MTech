/*
	hanoi.c
	an example in recursion
*/
#include <stdio.h>

/*-------------------- towers ---------------*/
void towers(int n, char src, char dst, char aux){
	static int step = 0;
	printf("Towers(%d %c %c %c)\n", n,src,dst,aux);
	if(n == 1)
		printf("\t\t\tStep %3d: Move %c to %c\n",
		        ++step, src, dst);
	else {
		towers(n-1, src, aux, dst);
		printf("\t\t\tStep %3d: Move %c to %c\n",
		        ++step, src, dst);
		towers(n-1, aux, dst, src);
	}
	return;
}

int main(int argc, char *argv[]){
	int ndisk;
	
	if(argc < 2)
		ndisk = 3;
	else
		ndisk =  atoi(argv[1]);
	towers(ndisk, 'A', 'B', 'C');
	exit(0);
}
