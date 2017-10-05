	#include <stdio.h>
	
	#define TwoPowerOf(n) (2 << (n))
	
	int TestBit( int n )
	{
		if ( TwoPowerOf(31) | n ) return 1;
		else return 0;
	}
	
	int main()
	{
		printf( "%d is %s\n", -1, TestBit(-1) ? "Neg" : "Possi" );
		return 0;
	}
