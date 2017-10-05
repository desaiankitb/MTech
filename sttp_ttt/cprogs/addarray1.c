/*
	addarray1.c
*/
#include <stdio.h>
int main()
{
	int i, sum, n;
	int a[10];
	
	i = 0;
	sum = 0;
	
	scanf("%d", &n);
	scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
	while(i < n){
		sum = sum + a[i];
		i++; 
	}
	printf("sum is %d \n", sum);
}
