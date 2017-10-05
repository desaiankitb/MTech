		#include <stdio.h>
		
		unsigned a[]  = { 1, 2, 3, 4, 5, 0xFFFF } ;
		
		unsigned sum (unsigned * p)
		{
			unsigned s = 0;

			while ( ( *p | 0xFF) <= 255)
			{
				s += *p++ & 0xFF;
			}
			return s;
		}
		int main()
		{
			printf(" sum = %d\n ", sum( a ) );
			return 0;
		}
