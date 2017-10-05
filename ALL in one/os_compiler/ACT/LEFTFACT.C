#include<stdio.h>
#include<string.h>
#include<conio.h>
typedef char arr[50];
arr k[10];
arr k1[10][10];
void factor(int,int,char [12]);
int ind;
void main()
{
  int i,prod,index,j,col,tind,count;
  char temp[10];
  clrscr();
  printf("enter no. of production:");
  scanf("%d",&prod);
  for(i=0;i<prod;i++)
  {
	scanf("%s",&k[i]);
  }
  printf("after removing left factor\n");
  for(i=0;i<prod;i++)
  {
	ind=0;
	col=0;
	for(j=2;j<strlen(k[i]);j++)
	{       if(k[i][j]!='/' && k[i][j]!='\0')
			k1[i][ind][col++]=k[i][j];
		else
		{	col=0;
			ind++;
		}
	}
	ind++;
  }
  for(i=0;i<prod;i++)
  {    count=0;
       tind=0;
       for(j=0;j<ind;j++)
       {
		for(col=0;col<strlen(k1[i][j]);col++)
		{
			if(k1[i][j][col]==k1[i][j+1][col])
			{	count++;
				temp[tind++]=k1[i][j][col];
			}
		}
       }
       temp[tind]='\0';
       if(count!=0)
	       factor(i,count,temp);
       else
	       printf("%s",k[i]);
  }
getch();
}
void factor(int i,int count,char temp[10])
{
	int j,col,temp1ind;
	char temp1[10];
	for(j=0;j<1;j++)
	{
		if(j==0)
		{
			printf("%c",k[i][0]);
			printf("=");
		}
		for(col=0;col<count;col++)
		{      // if(k1[i][j][col]==temp[col])
				printf("%c",k1[i][j][col]);
		}
		printf("%c",k[i][0]);
		printf("\'\n");
		printf("%c",k[i][0]);
		printf("'");
		printf("=");
		for(j=0;j<ind;j++)
		{
			for(temp1ind=0;temp1ind<count;temp1ind++)
				temp1[temp1ind]=k1[i][j][temp1ind];
			temp1[temp1ind]='\0';
			if(strcmp(temp,temp1)==0)
			{
			  for(col=count;col<=strlen(k1[i][j]);col++)
			  {
				if(count<strlen(k1[i][j]))
					printf("%c",k1[i][j][col]);
				else
					printf("n");
			  }
			  printf("/");
			}
		}
		printf("\n");
	}
}
