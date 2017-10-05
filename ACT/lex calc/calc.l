%{
	#include<stdio.h>
	int operand=0,operator=0,flag=0,ans=0;
%}
%%
[0-9]* {
	if(flag==0)
	{
		operand=atoi(yytext);
		flag=1;
	}
	else
	{
		switch(operator)
		{
			case 1:
				operand=operand+atoi(yytext);
				break;
			case 2: operand=operand-atoi(yytext);
				break;
			case 3:	operand=operand*atoi(yytext);
				break;
			case 4: operand=operand/atoi(yytext);
				
		}
		
		
		
	}
	}
"+" operator=1;
"-" operator=2;
"*" operator=3;
"/" operator=4;
"=" {printf("Answer=%d",operand);operand=0;flag=0;}
%%
