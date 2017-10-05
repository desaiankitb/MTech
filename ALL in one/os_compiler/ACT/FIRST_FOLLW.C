#include<stdio.h>
#include<string.h>
#include<conio.h>
typedef char arr[50];
arr k[10];
char st[25],sttemp[25],first1[10][10],follow[10][10],follownt[10][10],firstnt[10][10],nter[20];
int prod,ntr,ntc,indnt=0,firstntc,firstntr;
void first(char *);
void findfirst(char *,int );
void findterminal(int ,int);
void finalfirst(int,int);
void findfollow(char);
void finalfollow(int,int);
void findnull(int,int,char);
void main()
{
  int ind,i,l,t1,index=0,j,comma,comma1,f=0,sttempind,sttempind1,stind1,stind11,stind2,stind22,stind;
  char temp[10],ntertemp[20];
  clrscr();
  printf("enter no. of production:");
  scanf("%d",&prod);
  for(i=0;i<prod;i++)
   {
	scanf("%s",&k[i]);
   }
   for(i=0;i<prod;i++)
   {
	for(j=0;j<strlen(k[i]);j++)
	{
		if(k[i][j]!='=')
		{
			st[index++]=k[i][j];
		}
		else
		{
			st[index++]=',';
			break;
		}
	}
    }

    st[index]='\0';

    comma=0;
    sttempind=0;
    for(stind1=0;stind1<strlen(st);stind1++)
    {   f=0;
	if(st[stind1]==',')
	{
		comma++;
		continue;
	}
	if(comma<1)
		sttemp[sttempind++]=st[stind1];
	else
	{
		for(stind2=0;stind2<=stind1;stind2++)
		{
			if(sttemp[stind2]==st[stind1])
			{
				stind1++;
				f=1;
				break;
			}

		}
		if(f==0)
		{
			sttemp[sttempind++]=',';
			sttemp[sttempind++]=st[stind1];
			stind++;
		}
	}

    }
    sttemp[sttempind++]=',';
    sttemp[sttempind]='\0';
    for(i=0;i<prod;i++)
    {
	for(j=0;j<strlen(k[i]);j++)
	{
		if(k[i][j]=='=')
		{
			findterminal(i,j+1);
			break;
		}
	}
    }


    comma1=0;
    sttempind1=0;
    for(stind11=0;stind11<strlen(nter);stind11++)
    {   f=0;
	if(nter[stind11]==',')
	{
		comma1++;
		continue;
	}
	if(comma1<1)
		ntertemp[sttempind1++]=nter[stind11];
	else
	{
		for(stind22=0;stind22<=stind11;stind22++)
		{
			if(ntertemp[stind22]==nter[stind11])
			{
				stind11++;
				f=1;
				break;
			}

		}
		if(f==0)
		{
			ntertemp[sttempind1++]=',';
			ntertemp[sttempind1++]=nter[stind11];
			stind11++;
		}
	}

    }
    ntertemp[sttempind1++]=',';
    ntertemp[sttempind1]='\0';
    ntr=1;

    for(i=0;i<strlen(sttemp);i++)
    {
	 if(sttemp[i]!=',')
		first1[ntr++][0]=sttemp[i];
    }

    ntc=1;
    for(i=0;i<strlen(ntertemp);i++)
    {
	 if(ntertemp[i]!=',')
		first1[0][ntc++]=ntertemp[i];
    }
  
    firstntr=1;
    for(j=0;j<strlen(sttemp);j++)
    {
	if(sttemp[j]!=',')
	{
		firstnt[firstntr++][0]=sttemp[j];
	}
    }
    firstntc=1;
    for(j=0;j<strlen(sttemp);j++)
    {
	if(sttemp[j]!=',')
	{
		firstnt[0][firstntc++]=sttemp[j];
	}
    }

    for(i=1;i<firstntr;i++)
    {
	for(j=1;j<firstntc;j++)
		firstnt[i][j]=0;
    }
    ind=0;
    for(i=0;i<strlen(sttemp);i++)
    {
	if(sttemp[i]!=',')
		temp[ind++]=sttemp[i];
	else
	{
		temp[ind]='\0';
		first(temp);
		strcpy(temp,"");
		ind=0;
	}
    }
    for(i=firstntc-1;i>=1;i--)
    {
	for(j=1;j<firstntc;j++)
	{
		if(firstnt[i][j]=='1')
			finalfirst(i,j);
	}
    }
    for(i=1;i<ntr;i++)
    {   printf("first of %c:",first1[i][0]);
	for(j=1;j<=ntc;j++)
		if(first1[i][j]=='1')
			printf("%c  ",first1[0][j]);
	printf("\n");
    }
//code for follow
    ntr=1;
    for(i=0;i<strlen(sttemp);i++)
    {
	 if(sttemp[i]!=',')
		follow[ntr++][0]=sttemp[i];
    }

    ntc=1;
    for(i=0;i<strlen(ntertemp);i++)
    {
	 if(ntertemp[i]!=',')
		follow[0][ntc++]=ntertemp[i];
    }
    follow[0][ntc]='$';
    firstntr=1;
    for(j=0;j<strlen(sttemp);j++)
    {
	if(sttemp[j]!=',')
	{
		follownt[firstntr++][0]=sttemp[j];
	}
    }
    firstntc=1;
    for(j=0;j<strlen(sttemp);j++)
    {
	if(sttemp[j]!=',')
	{
		follownt[0][firstntc++]=sttemp[j];
	}
    }

    for(i=0;i<strlen(sttemp);i++)
    {
	if(sttemp[i]!=',')
		findfollow(sttemp[i]);
    }
    follow[1][ntc]='1';
    printf("\n");
    for(i=1;i<firstntc;i++)
    {
	for(j=1;j<firstntc;j++)
	{
		if(follownt[i][j]=='1')
			finalfollow(i,j);
	}
    }
    for(i=1;i<ntr;i++)
    {   printf("follow of %c:",follow[i][0]);
	for(j=1;j<=ntc;j++)
		if(follow[i][j]=='1')
			printf("%c  ",follow[0][j]);
	printf("\n");
    }
    getch();
}
void findfollow(char ch)
{
	int i,j,i1,i2,j1,l;
	for(i=0;i<prod;i++)
	{
		for(j=2;j<strlen(k[i]);j++)
		{
			if(k[i][j]==ch)
			{       if(k[i][j+1]=='\0')
				{
					for(i1=1;i1<ntr;i1++)
					{
						if(follownt[i1][0]==ch)
						{
						for(j1=1;j1<ntc;j1++)
							if(follownt[0][j1]==k[i][0])
								follownt[i1][j1]='1';
						}
					}
					break;
				}

				else if(strchr(nter,k[i][j+1]))
				{
					for(i1=0;i1<ntr;i1++)
					{
						if(follow[i1][0]==ch)
						{
						 for(j1=1;j1<=ntc;j1++)
						 {
						     if(follow[0][j1]==k[i][j+1])
							follow[i1][j1]='1';
						  }
						 }
					}
					// printf("\nfound %c in %d at %d",k[i][j+1],i,j+1);
					break;
				 }
				 else if(strchr(sttemp,k[i][j+1]))
				 {
				       for(i2=1;i2<ntr;i2++)
				       {
					if(follow[i2][0]==ch)
						break;
				       }
				       for(i1=1;i1<ntr;i1++)
				       {        if(first1[i1][0]==k[i][j+1])
						{
						  for(j1=1;j1<ntc;j1++)
						  {

							  if(first1[i1][j1]=='1'&& first1[0][j1]!='#')
								follow[i2][j1]='1';

							  if(first1[0][j1]=='#'&& first1[i1][j1]=='1')
							 {
							   findnull(i,j+1,ch);
							 }
						  }
						}
				       }
				       break;
				 }
			}
		}
	}
}
void findnull(int i,int j,char ch)
{
	int i1,j1,i2;
	 for(i2=1;i2<ntr;i2++)
	 {
		if(follow[i2][0]==ch)
			break;
	 }
	if(k[i][j+1]=='\0')
	{
		for(j1=1;j1<ntc;j1++)
			if(follownt[0][j1]==k[i][0])
				follownt[i2][j1]='1';
	}
	else if(strchr(sttemp,k[i][j+1]))
	{
	       //	printf("\nk[i][j]=%c\n",k[i][j+1]);

		for(i1=1;i1<ntr;i1++)
		{        if(first1[i1][0]==k[i][j+1])
			{
			  for(j1=1;j1<ntc;j1++)
			  {
				  if(first1[i1][j1]=='1'&& first1[0][j1]!='#')
					follow[i2][j1]='1';
				  if(first1[0][j1]=='#'&& first1[i1][j1]=='1')
				 {
					   findnull(i,j+1,ch);
				 }
			  }
			}
		}
	}

	else if(strchr(nter,k[i][j+1]))
	{
		for(j1=1;j1<=ntc;j1++)
		{
		     if(follow[0][j1]==k[i][j+1])
			follow[i2][j1]='1';
		}
	}
}
void findterminal(int i,int j)
{
	int l,len1,ascii;
	while(j<strlen(k[i]))
	{
			if(k[i][j]<65 || k[i][j]>90)
			       {	nter[indnt++]=k[i][j];
					nter[indnt++]=',';
			       }

		j++;
	}
}

void first(char temp[])
{
   int i,j,index;
   char temp1[10];
   for(i=0;i<prod;i++)
   {
	index=0;
	for(j=0;j<strlen(k[i]);j++)
	{
		if(k[i][j]!='=')
		{
			temp1[index++]=k[i][j];
		}
		else
		{
			temp1[index++]='\0';
			if(strcmp(temp,temp1))
			{
			      break;
			}
			else
			{      //	printf("\nstr=%s match\n",temp);
				findfirst(temp1,i);
			}
		}
	}
    }
}
void findfirst(char temp1[],int i)
{
	int j,l,stind,fr,fc,in;
	for(j=0;k[i][j]!='=';)
	{
		j++;
	}
	l=strlen(sttemp);
	in=k[i][j+1];
	if(in<65 || in>90)
	{
		for(fr=0;fr<ntr;fr++)
		{
			if(first1[fr][0]==k[i][0])
			{
				for(fc=1;fc<ntc;fc++)
				{
					if(first1[0][fc]==k[i][j+1])
					first1[fr][fc]='1';
				}
			}
		 }

	  }
	  else
	  {
		for(fr=0;fr<ntr;fr++)
		{
			if(first1[fr][0]==k[i][0])
			{
				for(l=1;l<=firstntc;l++)
				{
					if(firstnt[0][l]==k[i][j+1])
						firstnt[fr][l]='1';
				}
			       //	first1[fr][ntc]=k[i][j+1];
			}
		 }
	}
}
void finalfirst(int i,int j)
{
	int fr,fc;
	for(fc=1;fc<=ntc;fc++)
	{
		if(first1[j][fc]=='1' && first1[0][fc]!='#')
		{
			first1[i][fc]='1';
		}
	  }
}
void finalfollow(int i,int j)
{
	int fr,fc;
	for(fc=1;fc<=ntc;fc++)
	{
		if(follow[j][fc]=='1')
		{
			follow[i][fc]='1';
		}
	  }
}