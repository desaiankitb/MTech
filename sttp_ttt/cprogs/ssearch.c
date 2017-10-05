/*
	ssearch.c
*/
/*
  pre-condition: given an integer array a[i], i = 0 to n-1, size n, 
                 and a target integer x.
  post-condition: the index (position) m of the first element a[m]
                 equal to x. 0 < m < n. If x not in the array, m = n.
  action:        search for value x in the array.
  returns:       value m.
*/

#include <stdio.h>
#include <stdlib.h>   /* for atoi(), random()       */

int a[1000000];         /* assume: largest n is 1000000 */
int main(int argc, char *argv[])
{
	int i, n, m, x;
	
		
	if(argc < 3){
		printf("Usage: %s <n> <x>\n", argv[0]);
		exit(1);
	}
	n = atoi(argv[1]);
	x = atoi(argv[2]); 	
	
	if(n < 1 || n > 1000000){
		printf("Wrong value of n.\n");
		exit(-1);
	}
	for(i=0; i<n; i++)
		a[i] = n-i;
	
	for(i=0; i<n; i++){
		if(a[i] == x){
			m = i; break;
		}
	}
	if(i == n) m = n;
	printf("x is %s found, ", (m==n)?"not":"");
	if(m <n)  printf("at a[%d]\n", m);
}
