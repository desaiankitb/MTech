/*
	maxarray1.c
*/
/*
Pre-condition:  n > 0, and integer elements a[i], i = 0 to n-1.
Post-condition: max =  max(a[i], i = 0 to n-1).
Action:         Get the values n, a[i], i = 0 to n-1, from stdin, 
                find the maximum max and print it out.
Returns:        Exits with exit code 0.
*/

#include <stdio.h>

int main()
{
	int i,            /* loop index variable      */ 
	    n,            /* size of array            */
	    max;          /* current maximum value    */
	int a[100];       /* assume: largest n is 100 */
		
	printf("Size?\n");
	scanf("%d", &n);
	if(n < 1 || n > 100){
		printf("size out of range.\n");
		exit(-1);
	}
	printf("Give one element value per line:\n");
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
	exit(0);
}
