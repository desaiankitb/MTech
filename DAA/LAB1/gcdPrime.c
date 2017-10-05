#include<stdio.h>
#include<unistd.h>
#include<math.h>

#define MAX 100
void findprime(int arr[],float x)
{
	int i,j;
	int p,l[MAX];
	
/*	for(i=2;i<x;i++)
	{
		for(j=0;j<i;j++)
		{
			if(i%j==0)
				{flag = 1; break;}
			else
				flag = 0;
		}
		if(flag == 0)
		{
			arr[k] = i;
			k++;
		}
	}*/
	for(p=2;p<=x;p++)
	{
		arr[p] = x;
	}

	for(p=2; p <= ceil(sqrt(x)); p++)
	{
		if(arr[p] != 0)
		{
			j = p*p;
		}
		while(j<=x)
		{
			arr[j] = 0;
			j = j + p;
		}
	}

	i=0;
	for(p=2;p<=x;p++)
	{
		if(arr[p]!=0)
		{
			l[i] = arr[p];
			i++;
		}
	}

	for(p=0;p<=i;p++)
	{
		printf("%d\n",l[i]);
	}

}
int main()
{
	int arr[MAX],n,m,p,i,l[MAX],j;
	float x;
	
	printf("Enter the no1:\n");
	scanf("%d",&m);

	printf("Enter the no2:\n");
	scanf("%d",&n);

	if(m <= n)
	{
		x = m;
	}
	else
	{
		x = n;
	}
	
	findprime(arr,x);
	
	return 0;
}
