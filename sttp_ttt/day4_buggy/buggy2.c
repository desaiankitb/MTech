	#include <stdio.h>
	
	const char *wind[4] = 
		{
			"N 12 MPH"
			"NW 14 MHP" ,
			"N 22 MPH" ,
			NULL
		};

	float avg( const char * a[] )
	{
		float sum =0, vel = 0;
		int i;
		char direction[10];
		for( i = 0 ;  a[i] ; i++ )
		{
			sscanf( a[i] , "%s%d" , direction, &vel );
			sum += vel;
		}
		return sum / i;
	}
	
	int main()
	{
		printf("Avg widn velo is %g.\n", avg(wind) );
		return 0;
	}
