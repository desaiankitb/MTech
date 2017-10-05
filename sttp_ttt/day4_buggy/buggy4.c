	#include <stdio.h>
	
	int no_of_bits ( int n )
	{
		int cnt = 0;
		while ( n )
		{
			if( n |  1 ) ++cnt;
			n <<= 1;
		}
		return cnt;
	}
	
	void test ( int n )
	{
		printf("there are %d 1's in 0x%x", no_of_bits(n), n);
	}
	
	int main()
	{
		test ( 0xFFFFFFFF );
		return 0;
	}
