	#include <stdio.h>
	
	#define N 10
	
	int a[N];
	void fill( int from , int fill )
	{
		int i , j;
		for( i = from ; i < N ; i++)
		{
			a[i] = fill;
		}
		for( j = 0; j < from ; j++)
		{
			a[j] = 0;
		}
	}
	int main()
	{
		int i;
		fill( 8 , 22 );
		printf(" a[] contains\n");
		for(i = 0; i < N; i++)
		{
			printf(" %d " , a[i]);
		}
		printf("\n");
		return 0;
	}
