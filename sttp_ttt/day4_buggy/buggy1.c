	#include <stdio.h>
	
	int an[4] = { 1, 2, 3, 4 };
	
	int sum ( int a[4] )
	{
		int limit = sizeof(a) / sizeof(int);
		int result = 0;
		int i;
		for(i = 0 ; i < limit ; i++)
		{
			result += a[i];
		}
		return result;
	}
	
	int main()
	{
		printf("%d\n",sum( an ));
		return 0;
	}
