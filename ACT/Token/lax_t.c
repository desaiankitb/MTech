#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int no_sym = 0; //number of symbols in symbol table entry

char operator_table[][32] = {"+","-","/","*",";"};
FILE *fdtest;
char isidentifier(char sym_table[][32])
{
	char temp[32];
	int i=0,is_id_repeat,flag_id_only,floatflag=0;
	char ch;
	

	/* seprate the token from input */
	fread(&ch , 1 , 1 ,fdtest);
	do
	{
		temp[i++]=ch;
		fread(&ch , 1 , 1 ,fdtest);
		if(ch=='.')
		{
			floatflag=1;
		}
	}while( isalpha(ch) != 0 || isdigit(ch) != 0 || ch == '_' || ch=='.');

	temp[i] = '\0';
	
	is_id_repeat = search(temp,sym_table,no_sym);
	if(is_id_repeat < 0)
	{
		strcpy( sym_table[no_sym] , temp );
		is_id_repeat = no_sym;
		no_sym++;
	}
	if( (isdigit(temp[0]) &&  strlen(temp) <= 5 || floatflag ) || isalpha(temp[0]) || temp[0] == '_' )
	{
		if(floatflag)
		{
		printf("\n\tFloat Token\t %10s \t ID%d",temp,is_id_repeat);		
		}
		else
		{	
		printf("\n\tvalid integer token\t %10s \t ID%d",temp,is_id_repeat);
		}
	}
	else
	{
		printf("\n\tInvalid integer%10s \t ID%d",temp,is_id_repeat);		
	}

	return ch;
}

int search(char str[32],char sym_table[][32],int entries_in_table)
{
	int i;

	for(i=0;i<entries_in_table;i++)
	{
		if(strcmp(str,sym_table[i]) == 0)
		{
			break;
		}
	}
	if(i>=entries_in_table)
		return -1;
	else
		return i;
}


//  This function ignores the mutiline comments written within "/* " and  "*/"
//  It also ignores the single line comment starting with "//"
int check_comment(char ch,int i)
{
	char ch1;
	ch1=fgetc(fdtest);

	//Check for  multiline comment written within "/*" and "*/"
	if(ch1=='*')
	{
		do
		{
			ch=fgetc(fdtest);
			ch1=fgetc(fdtest);
		}while(ch!='*' &&ch1!='/');
		i--;
	}

	//Check single line comment starting with "//"
	else if(ch1=='/')
	{
		do
		{
			ch=fgetc(fdtest);
		}while(ch!='\n');
	i--;
	}
	else
	{
		ungetc(ch1,fdtest);
		ungetc(ch,fdtest);
	}
	return i;
}





int chek_2_char_operator(char ch,char *temp,int i)
{
	switch(ch)
	{

		
		/* check for comment and if it is a comment ingnore it */
		case '/':
			i=check_comment(ch,i);
			break;
	}
	return i;
}



int main(int argc, char* argv[])
{

	char buf;
	char symbol_table[100][32]={'\0'};
	char ch;
	int i=0,j;
	int operator_no;
	char temp[2]={'\0','\0'};

	fdtest = fopen( (char *)argv[1]  , "r" );
	
	while( (j = fread(&ch , 1 , 1 ,fdtest) ) > 0 )
	{
		buf = ch;
		if(isalpha(buf) || buf == '_' || isdigit(buf) )
		{		
			ungetc(buf,fdtest);
			ch = isidentifier(symbol_table);
		}
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/' || ch==';')
		{
			i=0;			
			temp[i++]=ch;
			i=chek_2_char_operator(ch,temp,i);
			temp[i]='\0';
			operator_no=999;
			operator_no=search(temp,operator_table,5);
			if(operator_no>=0 && operator_no<4)
				printf("\n\tOperator\t%10s\top%d\n",temp,operator_no);
			else if( operator_no == 4)
				printf("\n\tEnd of line\t%10s\top%d\n",temp,operator_no);
			else
			{}	
			i=0;
		}
		
	}
	printf("\n");
	return 0;
}










