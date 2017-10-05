/*
	maxarray.c
*/
/*
Pre-condition:  n > 0, and integer elements a[i], i = 0 to n-1.
Post-condition: max =  max(a[i], i = 0 to n-1).
Action:         Get the values n, a[i], i = 0 to n-1, from stdin, 
                find the maximum max and print it out.
Returns:        Nothing.
*/

#include <stdio.h>

int main()
{
	int i, n, max;
	int a[100];       /* assume: largest n is 100 */
		
	scanf("%d", &n);
	i = 0;
	while(i < n){
		scanf("%d", &a[i]);
		i++;
	}
	
	i = 0;
	max = -99999;
	while(i < n){
		if(a[i] > max)
			max = a[i];
		i++;
	}
	printf("Maximum is %d \n", max);
}
