#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
FILE *fp;
char delim[14]={' ','\t','\n',',',';','(',')','{','}','[',']','#','<','>'};
char oper[7]={'+','-','*','/','%','=','!'};
char key[21][12]={"int","float","char","double","bool","void","extern","unsigned","goto","static","class","struct","for","if","else","return","register","long","while","do"};
char predirect[2][12]={"include","define"};
char header[6][15]={"stdio.h","conio.h","malloc.h","process.h","string.h","ctype.h"};
void skipcomment();
void analyze();
void check(char []);
int isdelim(char);
int isop(char);
int fop=0,numflag=0,f=0;
char c,ch,sop;
void main()
{
char fname[12];
clrscr();
fp=fopen("d:/cc/lex_text.txt","r");
if(fp==NULL)
	printf("\n the file does not exist");
else
	analyze();
printf("\n end of file \n");
getch();
}
void analyze()
{
	char token[50];
	int j=0;
	while(!feof(fp))
	{
		c=getc(fp);
		if(c=='/')
		{
		       //	skip comment();
		}
		else if(c==" ")
			while(c!=" ")
				{c=fgetc(fp);}
		else if(isalpha(c))
		{
			if(numflag==1)
			{
				token[j]='\0';
				check(token);
				numflag=0;
				j=0;
				f=0;
			}
			else
			{
				token[j]=c;
				j++;
			}
			if(f==0)
				f=1;
		}
		else if(isalnum(c))
		{
			if(numflag==0)
			numflag=1;
			token[j]=c;
			j++;
		}
		else
		{
			if(isdelim(c))
			{
				if(numflag==1)
				{
					token[j]='\0';
					check(token);
					numflag=0;
				}
				if(f==1)
				{
					token[j]='\0';
					numflag=0;
					check(token);
				}
				j=0;
				f=0;
				printf("\n delimiters \t%c",c);
			}
			else if(isop(c))
			{
				if(numflag==1)
				{
					token[j]='\0';
					check(token);
					numflag=0;
					j=0;
					f=0;
				}
				if(f==1)
				{
					token[j]='\0';
					j=0;
					f=0;
					numflag=0;
					check(token);
				}
				if(fop==1)
				{
					fop=0;
					printf("\n operator \t %c%c",c,sop);
				}
				else
					printf("\n operator \t%c",c);
			}
			else if(c=='.')
			{
				token[j]=c;
				j++;
			}
		}
	}//end while
}
int isdelim(char c)
{
	int i;
	for(i=0;i<14;i++)
	{
		if(c==delim[i])
		return 1;
	}
	return 0;
}
int isop(char c)
{
	int i,j;
	char ch;
	for(i=0;i<7;i++)
	{
		if(c==oper[i])
		{
			ch=getc(fp);
			for(j=0;j<6;j++)
			{
				if(ch==oper[j])
				{
					fop=1;
					sop=ch;
					return 1;
				}
			}
			ungetc(ch,fp);
			return 1;
		}
	}
	return 0;
}
void check(char t[])
{
	int i;
	if(numflag==1)
	{
		printf("\n number \t\t%s",t);
		return;
	}
	for(i=0;i<2;i++)
	{
		if(strcmp(t,predirect[i])==0)
		{
			printf("\n preprocessor directive %s",t);
			return;
		}
	}
	for(i=0;i<6;i++)
	{
		if(strcmp(t,header[i])==0)
		{
			printf("\n header file \t%s",t);
			return;
		}
	}
	for(i=0;i<21;i++)
	{
		if(strcmp(key[i],t)==0)
		{
			printf("\n keyword \t\t%s",key[i]);
			return;
		}
	}
	printf("\n identifier \t%s",t);
}
void skipcomment()
{
	ch=getc(fp);
	if(ch=='/')
	{
		while((ch=getc(fp))!='\0');
	}
	else if(ch=='*')
	{
		while(f==0)
			ch=getc(fp);
		if(c=='/')
		f=1;
	}
	f=0;
}


