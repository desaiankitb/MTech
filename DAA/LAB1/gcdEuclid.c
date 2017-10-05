#include<stdio.h>
#include<unistd.h>
int main()
{

	int m=0,n=0,t=0;
	
	printf("Enter the no1:\n");
	scanf("%d",&m);

	printf("Enter the no2:\n");
	scanf("%d",&n);
	t = euclid(m,n);
	printf("GCD of %d & %d is: %d\n",m , n , t);
	return 0;
}
int euclid(int m,int n)

{
	int t;
	while(n!=0)
	{
		t = m % n;
		m = n;
		n = t;
	}
	return m;
}
