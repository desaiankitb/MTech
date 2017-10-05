#include <stdio.h>
int func1(int m){
	short i;
	for(i=0;i<m;i++) 
                ;
}

int main(int argc, char * argv[]){
	int n;
	n = atoi(argv[1]);
	func1(n);
}
