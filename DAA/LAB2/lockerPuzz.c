#include<stdio.h>
#include<unistd.h>

#define MAX 2000



void initial(char *locker,int no)
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		locker[i]='c';
	}
	/*for(i=1;i<=no;i++)
	{
		printf("%c\t",locker[i]);
	}
	printf("\n");*/
}

void simulate(int no,char* locker)
{
	int i,j,k,l;
	printf("locker #\t\n");
	for(i=1;i<=no;i++)
	{
		printf("\t%d",i);
	}
	printf("\n=========================================================================================\n");
	for(i=1;i<=no;i++)//no. of stds loop
	{
		printf("%dth std   ",i);
		for(j=1;j<=no;j++)//no. of lockers loop
		{
			if(i==1)//std #1 opens every locker
			{
				for(k=1;k<=no;k++){
					locker[k] = 'o';
					printf("%c\t",locker[k]);
				}
				printf("\n");
				break;
			}
			if(j%i == 0)//toggle if multiple of i
			{		
				if(locker[j] == 'o')
				{	
					locker[j] = 'c';
				}
				else
					locker[j] = 'o';
			}
			printf("%c\t",locker[j]);
		}
		printf("\n");
	}
}

int main(int argc,char** argv)
{
	int noOfStd;
	char locker[MAX];
	initial(locker,noOfStd);
	noOfStd = atoi(argv[1]);
	simulate(noOfStd,locker);
	return 0;
}
