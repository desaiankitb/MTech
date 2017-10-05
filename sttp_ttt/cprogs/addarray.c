#include <stdio.h>
int main()
{
	int i, sum, n = 5;
	int a[5] = {11, 22, 33, 44, 55};
	
	i = 0;
	sum = 0;
	while(i < n){
		sum = sum + a[i];
		i++; 
	}
}
