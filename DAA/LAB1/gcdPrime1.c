#include<stdio.h>
#include<unistd.h>
#include<math.h>

#define MAX 100

int arr[MAX],l[MAX],m,n;

void findprime(int arr[],int x)
{
	int i,j,flag=0,k=0;
	for(i=0;i<=MAX;i++)
	{
		arr[i] = 0;
	}
	for(i=2;i<=x;i++)
	{
		if(x%i == 0)
		{
			for(j=2;j<i;j++)
			{
				if(i%j == 0)
					{flag = 1; break;}
				else
					flag = 0;
			}
			if(flag == 0)
			{
				arr[k] = i;
				k++;
			}
		}
	}
	for(j=0;j<k;j++)
	{		
		printf("%d\n",arr[j]);
	}
}

void commonfactors(int arr[],int m)
{
	int totalprime=0,i=0,ans=1;
	while( arr[i]!=0 ) {totalprime++; i++;}

	for(i=0; i<totalprime-1; i++)
	{
		if( m%arr[i] != 0 )
			ans = ans * arr[i];
	}
	printf("\n\nans : %d\n",ans);
}

int main()
{
	int p,i,j;
	int x;
	
	printf("Enter the no1:\n");
	scanf("%d",&m);

	printf("Enter the no2:\n");
	scanf("%d",&n);
	
	findprime(arr,m);
	findprime(l,n);
	
	return 0;
}

