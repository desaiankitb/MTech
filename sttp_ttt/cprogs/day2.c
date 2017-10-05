	#include <stdio.h>
	#include <string.h>

	#define ROWS 3
	#define COLS 3

	void 
	nextGeneration(

	);
	int cnt[ROWS][COLS];
	int iArrayWorld[ROWS][COLS];
	void neighbourCount(void);
	void neighbourCount()
	{
		int i,j;
		
		for(i=0;i<ROWS;i++)
		{
			for(j=0;j<COLS;j++)
			{
				if(i >= 1 && i < (ROWS-1))
				{
					if( j >= 1 && j < COLS - 1)//only for i=others  and j= others
					{
						if( iArrayWorld[i-1][j-1] == 1 )
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i-1][j] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i-1][j+1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i][j-1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i][j+1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j-1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j+1] == 1)
						{
							cnt[i][j]++;
						}
					}
					else if(j==0)
					{
						if( iArrayWorld[i-1][j] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i-1][j+1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i][j+1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j+1] == 1)
						{
							cnt[i][j]++;
						}	
					}
					else//LAST COL
					{
					 	if( iArrayWorld[i-1][j-1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i-1][j] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i][j-1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i+1][j-1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i+1][j] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
	
					}
				}
				else if( i == 0 )
				{
					if( j == 0 )
					{
						if ( iArrayWorld[i][j+1] == 1 )
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j] == 1)
						{
							cnt[i][j]++;
						}
						if(iArrayWorld[i+1][j+1] == 1)
						{
							cnt[i][j]++;
						}	
					}
					else if( j == COLS-1 )
					{
						if( iArrayWorld[i][j-1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j-1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j] == 1)
						{
							cnt[i][j]++;
						}
					}
					else 
					{
						if( iArrayWorld[i][j-1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i][j+1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j-1] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j] == 1)
						{
							cnt[i][j]++;
						}
						if( iArrayWorld[i+1][j+1] == 1)
						{
							cnt[i][j]++;
						}
					}	
				}
				else//i = ROWS 
				{
					if(j==0)
					{
					 	if( iArrayWorld[i-1][j] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i-1][j+1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i][j+1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
	
					}
					else if( j == COLS-1 )
					{
						if( iArrayWorld[i-1][j-1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i-1][j] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i][j-1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }

					}
					else//OTHERS
					{
						if( iArrayWorld[i-1][j-1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i-1][j] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i-1][j+1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
						 if( iArrayWorld[i][j-1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
                                                if( iArrayWorld[i][j+1] == 1)
                                                {
                                                        cnt[i][j]++;
                                                }
					}
				}
			}
		}
	}
	
	void printNextGen();
	void printNextGen()
	{
		int iI,iJ;
		for(iI=0 ;iI < ROWS; iI++)
		{
			for(iJ=0; iJ< COLS; iJ++)
			{
				//if( iArrayWorld[iI][iJ] == 0)
				//{
					printf("\t%d",cnt[iI][iJ]);
					//printf("\t.");
					//printf("\t%d",iArrayWorld[iI][iJ]);
				//}
				//else
				//{
					//printf("\t%d",cnt[iI][iJ]);
					//printf("\tX");
				//}
			}
			printf("\n");
		}
	}
	void iniZero()
	{
		int i,j;
		for(i=0;i<ROWS;i++)
		{
			for(j=0;j<COLS;j++)
			{
				cnt[i][j]=0;
				iArrayWorld[i][j]=0;
			}
		}
	}
	int main()
	{
		int iRowNo=999,iColNo=999;
		printf("\n\n\t :::GAME OF LIFE:::\n");
		iniZero();
		while( (iRowNo != -1) && (iColNo != -1) )
		{
			printf("\n\n\tEnter row and Col., Seprated by Space:  ");
			scanf("%d %d",&iRowNo,&iColNo);
			
			iArrayWorld[iRowNo][iColNo] = 1;
		}
		printNextGen();
		neighbourCount();
		printf("\n\n");
		printNextGen();
		return 0;
	}
