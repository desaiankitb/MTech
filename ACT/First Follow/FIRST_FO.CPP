/* Program to compute FIRST and FOLLOW set */
/* This program computes FISRT set of any string of terminal and non-terminal
   and FOLLOw set for any non-terminal of given grammar g*/

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
//#include<conio.h>
#include<iostream>
#include<fstream>
#include<strings.h>

#define SIZE 80

using namespace std;
/*  Grammar will be stored in an array of structure g */
struct grammar
{
	char NT;
	char rhs[10][10];
	int total_rhs;
}g[10];

int total_NTs;		//Total NTs in grammar
int total_first;       	//Total no. of first symbols
char temp_first[20];
//char follow_set[20];
char* compute_first_set(char*);
void display_first_set(char*);
char* compute_follow_set(char);
int check_null(char*);
int read_grammar(char*);
void display_grammar();
char first(char*);
void All_NTs_first_set();
char* remove_duplicate(char*);
char* sort(char*);
char* remove_duplicate(char*);

int main(int argc,char* argv[])
{
	int i,j,f_f,NT_follow,choice;
	char opt,final_first_set[20],final_follow_set[20],alpha[20];
	
	char* first_set=(char *) malloc(20*sizeof(char));

	//clrscr();
	total_NTs=read_grammar(argv[1]);	//Read grammar from file

	do
	{
		printf("\n\t1.FIRST\n\t2.FOLLOW\n\n\tEnter your choice\n");
		cin>>f_f;
		switch(f_f)
		{
			case 1:
				display_grammar();
				cout<<"\n\t1. Compute FIRST of all NTs\n\t2. Compute FIRST for a specific SENTENTIAL form\n\n\tEnter your chice:";
				cin>>choice;
				if(choice==1)
					All_NTs_first_set();
				else if(choice==2)
				{
					cout<<"\n\tEnter String: ";
					cin>>alpha;
					first_set=NULL;
					cout<<"\n********************  FIRST  *********************\n";
					first_set=compute_first_set(alpha);
					strcpy(final_first_set,remove_duplicate(first_set));
					cout<<"\n\t\tFirst of  "<<alpha<<" : ";
					display_first_set(final_first_set);
					cout<<"\n********************  FIRST  *********************\n";
				}
				break;
			case 2:
				display_grammar();
				cout<<"\n*******************  FOLLOW  ********************\n\n";
				for(NT_follow=0;NT_follow<total_NTs;NT_follow++)
				{
					strcpy(final_follow_set,compute_follow_set(g[NT_follow].NT));
					cout<<"\tFOLLOW  of "<<g[NT_follow].NT<<": ";
					display_first_set(final_follow_set);
					cout<<"\n";
				}
				cout<<"\n*******************  FOLLOW  ********************\n";
				break;
		}
		cout <<"\nWould you like to continue PRESS 'Y' or 'y'";
		cin>>opt;
	}while(opt=='Y' || opt=='y');
	return 0;
}//End of main


/* This function computes FOLLOW(NT) for given non-terminal NT by using the following rules:
   If there is a production of the form A -> <alpha>B<beta> then
   FOLLOW(B) = FIRST(<beta>) 			   if '@' is not there in FIRST(<beta>)
	     = FIRST(<beta>)-{@} + FOLLOW(A)       if '@' is in FIRST(<beta>)  */
char*  compute_follow_set(char NT)
{
	int i,j,k,l,m,isnull;
	char beta[30],first_beta[20],follow_lhs[20],temp_set[20],follow_set[20];
	strcpy(follow_set,"");

	/* If given non-terminal NT is the starting non-terminla of grammar '$' is in FOLLOW(NT)  */
	if(g[0].NT==NT | NT=='S')
	{
		strcpy(follow_set,"$");
	}

	/* To compute FOLLOW(B) search for a production of the form: A -> <alpha>B<beta>   form given grammar  */
	for(i=0;i<total_NTs;i++)
	{
		for(j=0;j<g[i].total_rhs;j++)
		{
			for(k=0;g[i].rhs[j][k]!='\0';k++)
			{
			       /* If production of the form: A -> <alpha>B<beta> is found extract <beta> from that production */
			       if(g[i].rhs[j][k]==NT)
			       {
				       l=0;
				       beta[0]='\0';
				       k++;
				       m=k;
				       total_first=0;
				       while(g[i].rhs[j][m]!='\0')
				       {
						beta[l++]=g[i].rhs[j][m++];
				       }
				       beta[l]='\0';

				       /*  Find FIRST(<beta>)  */
				       strcpy(first_beta,compute_first_set(beta));

				       /*  Check  '@' is in FIRST(<beta>) or not  */
				       isnull=check_null(first_beta);

				       strcpy(follow_lhs,"");  //initialize FOLLOW(A) as an empty set

				       /* If '@' is in FIRST(<beta>) the compute FOLLOW(A) */
				       if(isnull && NT!=g[i].NT)
				       {
						strcpy(follow_lhs,compute_follow_set(g[i].NT));
				       }
				       /* FOLLOW(B) = FIRST(<beta>)-{@} + FOLLOW(A)
						      if '@' is in FIRST(<beta>) and there is a production A -> <alpha>B<beta> */
				       strcat(first_beta,follow_lhs);

				       /*  Remove duplicate elements from the FOLLOW set  */
				       strcpy(follow_set,remove_duplicate(strcat(follow_set,first_beta)));
			       }
			}
		}
	}
	return follow_set;
}

/* This function checks for '@' is present in given set str or not
   If '@' is in set str it returns 1 otherwise it returns 0 */
int check_null(char *str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='@')
		{
			while(str[i]!='\0')
				str[i]=str[i+1];
			return 1;
		}
	}
	return 0;
}

/* This function computes the first set for all nonterminal in given grammar g
   For that first it copies each non-terminal into str and then computes FIRST(str) */
void All_NTs_first_set()
{
	int i,j;
	char *final_first_set=(char *)malloc(20*sizeof(char));
	char* first_set =(char *) malloc(30*sizeof(char));
	char *str = (char *)malloc(10 *sizeof(char));
	cout<<"\n********************  FIRST  *********************\n";
	for(i=0;i<total_NTs;i++)
	{
				
		total_first=0;
		//cout<<"success\n";
		bzero(&temp_first,sizeof(temp_first));
		//cout<<"success\n";
		str[0]=g[i].NT;		  			//Copy a non-termianal into str
		str[1]='\0';
		first_set=NULL; 
		        		        //initialize FISRT set as an empty set
		first_set=compute_first_set(str);		//Compute FIRST set of str i.e non-terminal stored in str
		final_first_set=remove_duplicate(first_set);	// Remove duplicate terminal symbols from FIRST set
		cout<<"\n\t\tFirst of  "<<g[i].NT<<" : ";
		display_first_set(final_first_set);
	}
	cout<<"\n********************  FIRST  *********************\n";
}

/* This function displays the set passed as an argumen */
void display_first_set(char* set)
{
	int j;
	for(j=0;j<strlen(set);j++)
	{
		cout<<set[j];
		if(j<(strlen(set)-1))
			cout<<",";
	}

}

/*  This function displays a grammar in g  */
void display_grammar()
{
	int i,j;
	cout<<"\n\n*******************  GRAMMAR  ********************\n\n";
	for(j=0;j<total_NTs;j++)
	{
		cout<<"\t\t"<<g[j].NT<<" -> ";
		for(i=0;i<g[j].total_rhs;i++)
		{
			cout<<g[j].rhs[i];
			if(i<g[j].total_rhs-1)
				cout<<" | ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	cout<<"\n*******************  GRAMMAR  ********************\n\n";
}

/* sort all character in str in ascending oreder so that
   we can remove duplicate symbols easily  */
char* sort(char* str)
{
	int i=0,j=0;
	char dummy;
	int n=strlen(str);
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(str[j-1]>str[j])
			{
				dummy=str[j-1];
				str[j-1]=str[j];
				str[j]=dummy;
			}
		}
	}
	return str;
}

/* This function removes duplicate elements from set passed as an argument */
char* remove_duplicate(char* str)
{
	int i,j,n;
	char *str1=(char *)malloc(20*sizeof(char));
	str1=sort(str);
	n=strlen(str1);
	for(i=1;i<n;i++)
	{
		if(str1[i-1]==str1[i])
		{
			for(j=i;j<n;j++)
			{

			       str1[j]=str1[j+1];
			}
			n--;
			i--;
		}
	}
	return str1;
}

/* This function computes FISRT set of any string of terminal and non-terminal
   It applys the following rules:
   CASE 1:	FIRST(XYZ) = {X}				if X is a terminal
   CASE 2:		   = FIRST(X)				if '@' is not in FIRST(X)
   CASE 3:		   = FIRST(X) - {@} + FIRST(YZ)		if '@' is in FIRST(X)
   Here X,Y,Z represents any grammar symbol (i.e terminal or non-terminal) */
char* compute_first_set(char *str)
{
	int i,j,k,flag,curr_symb=0;
	if(str[0]!='\0')
	{
		do
		{
			/* CASE 1: when first symbol of given string str is a terminal symbol  */
			if(!isupper(str[curr_symb]))
			{
				temp_first[total_first++]=str[curr_symb];
				temp_first[total_first]='\0';
				break;
			}

			/* CASE 2,3: When first symbol of given string str is a non-terminal symbol
				     Find FIRST for that non-trminal by computing FISRT of all its
				     alternatives  and take union of all */
			else
			{
				for(i=0;i<total_NTs;i++)
				{
					if(str[curr_symb]==g[i].NT)
						break;
				}

				/* compute FIRST for all the alternatives of non-terminal */
				for(j=0;j<g[i].total_rhs;j++)
				{
					if(str[curr_symb]!=g[i].rhs[j][0])
						compute_first_set(g[i].rhs[j]);
				}
				curr_symb++;
				flag=0;
				temp_first[total_first]='\0';

				/* If '@' is in FIRST of non-terminal then CASE 2 otherwise CASE 3 */
				for(k=0;k<temp_first[k]!='\0';k++)
				{
					if(temp_first[k]=='@')
					{
						flag=1;
						total_first--;
						break;
					}
				}
			}
		}while(flag==1 && str[curr_symb]!='\0');
	}
	/* consider the case where str is a null string
	   in that case FIRST(STR) ={@}
	   This case is used when there is a production of the form A -> @  */
	else
	{
		temp_first[0]='@';
		temp_first[1]='\0';
	}
	return temp_first;
}

/*Reads a grammar from a specified file and stores it into g (array of structure gammar)
  this function ignores the white spaces
  it assumes the grammar written in file is CFG
  it assumes all the possible alternatives for a same nonterminal are
  written in same line and they are separated by '|'*/
int read_grammar(char *file)
{
	//char *file;
	char str[SIZE];
	fstream input;// =  ( "gram6.txt" , ifstream::in );
	//file=argv[1];
	int index=0;

	input.open(file);
	while(!input.eof())
	{
		input.getline(str,SIZE);
		int i=0,j=0,k;
		char temp[10],temp1;
		/*Read nonterminal present at left hand side of the production*/
		while(str[i]!='-'&&str[i+1]!='>')
		{
			if(str[i]==' ')
				i++;
			else
			{
				temp1=str[i];
				i++;
			}
		}
		g[index].NT=temp1;
		temp[0]='\0';
		i++;
		j=k=0;
		i++;

		/*read write hand side of the productions and separate different alternatives present in production*/
		do
		{                         //Start of while
			if(str[i]==' ')
				i++;
			else if(str[i]!='|')
			{
				temp[k++]=str[i++];

			}
			else
			{
				temp[k]='\0';
				strcpy(g[index].rhs[j],temp);
				k=0;
				i++;
				j++;
			}
		}while(str[i]!='\0');			 //End of while
		temp[k]='\0';
		strcpy(g[index].rhs[j],temp);

		/*Initialize total no of right hand side production alternatives*/
		g[index].total_rhs=j+1;
		j=0;
		index++;
		//read next line (containing productions for the next non-terminal)from the file
	}  //end of while
	return (index);
}
