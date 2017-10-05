#include<stdio.h>
#include<unistd.h>
int main()
{
	int m=0,n=0,t=0;
	
	printf("Enter the no1:\n");
	scanf("%d",&m);

	printf("Enter the no2:\n");
	scanf("%d",&n);

	if(m <= n)
	{
		t = m;
	}
	else
	{
		t = n;
	}
	while(m%t != 0) 
	{
		t = t-1;
	}
	prev:
	if(n%t == 0)
	{
		printf("GCD of %d & %d is: %d\n",m , n , t);
		_exit(0);
	}
	t--;	
	goto prev;

	
	return 0;
}
