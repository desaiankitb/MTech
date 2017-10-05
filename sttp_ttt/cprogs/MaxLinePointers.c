	#include <stdio.h>
	#include <string.h>
	
	#define ROWS 3
	void input(char **);
	void process(char **);
	void output(char **,int *,int);
	int findMax(int *);
	int iArrSize[ROWS];
	
	int iSize = 0;
	int iCol = 0;
	int max = 0;
	int main()
	{
		char **pchLine;
		int *pchResult;
		input(pchLine);
		process(pchLine);
		max = findMax(iArrSize);
		output(pchLine,iArrSize,max);
		
		return 0;
	}
	
	int findMax(int *pchT)
	{
		int iIndex;
		for(iIndex = 0; iIndex < iSize; iIndex++ )
                {
			if(max < *pchT)
			{
				max = *pchT;
			}
			else
				continue;
		}
		printf("MAX END");
		return max;
	}

	void input( char **pchT )
	{
		int iIndex;
		printf("\n\n\t Enter No of Lines:");
		scanf("%d",&iSize);
		pchT  =(char **) malloc( sizeof(char *) * iSize );
		for(iIndex = 0; iIndex < iSize; iIndex++ )
		{
			printf("Enter the no of char for line %d",iIndex);
			scanf("%d",&iCol);
			pchT = (char **) malloc ( sizeof(char)*iCol );
			getchar();
			getline( &pchT , &iSize , stdin );
			printf("%s",*(pchT + iIndex));
		}
	}
	
	void process( char ** pchT )
	{
		int iIndex ;
		for(iIndex = 0; iIndex < iSize; iIndex++)
                {
                        iArrSize[iIndex] = 0;
                }

		for(iIndex = 0; iIndex < iSize; iIndex++)
		{
			iArrSize[iIndex] = strlen(*(pchT + iIndex));
			printf("%d",iArrSize[iIndex]);
		}
		printf("Process END:");
		//return iArrSize;
	}
	
	void output( char **pchL ,int *pchR, int max)
	{
		int iIndex = 0;
                for(iIndex = 0; iIndex < iSize; iIndex++)
                {
			if(max == *(pchR + iIndex))
			{
				printf("%s",**pchL+iIndex);
			}
                }

	}
