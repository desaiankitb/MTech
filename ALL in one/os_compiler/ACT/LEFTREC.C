#include<stdio.h>
#include<string.h>
#include<conio.h>
typedef char arr[50];
arr k[10];
arr k1[10];
int indr=0;
void factor(int,int);
void main()
{
  int i,prod,index,j,indc,col,f;
  char nt[10],st[10];
  clrscr();
  printf("enter no. of production:");
  scanf("%d",&prod);
  for(i=0;i<prod;i++)
  {

		scanf("%s",&k[i]);
   }

  for(i=0;i<prod;i++)
  {
	f=0;
	for(j=2;j<strlen(k[i]);j++)
	{
		if(k[i][0]==k[i][j])
		{       f=1;
			factor(i,j+1);
			while(k[i][j]!='/')
				j++;
		}
		else if(f==1)
		{
			indc=0;
			k1[indr][indc++]=k[i][0];
			k1[indr][indc++]='=';
			for(col=j;k[i][col]!='/' && k[i][col]!='\0';col++)
			{	k1[indr][indc++]=k[i][j];
				j++;
			}
			k1[indr][indc++]=k[i][0];
			k1[indr][indc++]='\'';
			indr++;
		}
		else
		{
			for(col=0;col<=strlen(k[i]);col++)
			{	k1[indr][col]=k[i][col];
				j++;
			}
			indr++;
		}
	}
  }
  for(i=0;i<indr;i++)
  {
	printf("%s\n",k1[i]);

  }
getch();
}
void factor(int i,int j)
{
	int col,indc=0;
	k1[indr][indc++]=k[i][0];
	k1[indr][indc++]='\'';
	k1[indr][indc++]='=';
	for(col=j;k[i][col]!='/' && k[i][col]!='\0';col++)
	{
		k1[indr][indc]=k[i][col];
		indc++;
	}
	k1[indr][indc++]=k[i][0];
	k1[indr][indc++]='\'';
	k1[indr][indc]='\0';
	k1[indr][indc++]='/';
	k1[indr][indc++]='#';
	indr++;
}