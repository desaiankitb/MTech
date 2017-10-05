#include <stdio.h>
#include <conio.h>

char *input,next;
int cursor;
int expr();
int factor();
int term();
char getnext();

void main()
{
	clrscr();
	printf("Enter the string...\n");
	gets(input);
	cursor=0;
	next=getnext();
	if(expr())
	{
		if(next==NULL)
			printf("\nVALID STRING");
		else
			printf("\nINVALID STRING");
	}
	else
			printf("\nINVALID STRING");
	getch();
}

int expr()
{
	if(! (term()) )
		return(0);
	if(next == '+')
	{
		next = getnext();
		if(next == NULL)
			return(0);
		if(! (expr()) )
			return(0);
		else
			return(1);
	}
	else
		return(1);
}

int term()
{
	if(! (factor()) )
		return(0);
	if(next=='*')
	{
		next = getnext();
		if(next==NULL)
			return(0);
		if(! (term()) )
			return(0);
		else
			return(1);
	}
	else
		return(1);
}

int factor()
{
	if(next == NULL)
		return(0);
	if(next == '(')
	{
		next = getnext();
		if(next == NULL)
			return(0);
		if(!expr())
			return(0);
		if(next != ')')
			return(0);
		else
		{
			next = getnext();
			return(1);
		}
	}
	if(next == 'a')
	{
		next = getnext();
		return(1);
	}
	else
		return(0);
}

char getnext()
{
	char ch1;
	ch1 = input[cursor];
	cursor++;
	return(ch1);
}