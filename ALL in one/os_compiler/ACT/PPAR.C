#include<stdio.h>
#include<conio.h>
#include<string.h>

char str[10],out,in,output[10],input[10],temp;
char tl[10]={'x','+','*','(',')','$','@'};
char ntl[10]={'E','e','T','t','F'};
int err=0,flag=0,i,j,k,l,m;
char c[10][10][7]={{{"Te"},{"ERROR!"},{"ERROR!"},{"Te"},{"ERROR!"},{"ERROR!"}},
			{"ERROR!","+Te","ERROR!","ERROR!","@","@"},
			{"Ft","ERROR!","ERROR!","Ft","ERROR!","ERROR!"},
			{"ERROR!","@","*Ft","ERROR!","@","@"},
			{"x","ERROR!","ERROR!","(E)","ERROR!","ERROR!"}};

struct stack
	{
		char sic[10];
		int top;
	};

void push(struct stack *s,char p)
	{
		s->sic[++s->top]=p;
		s->sic[s->top+1]='\0';
	}

char pop(struct stack *s)
	{
		char a;
		a=s->sic[s->top];
		s->sic[s->top--]='\0';
		return(a);
	}
char sttop(struct stack *s)
	{
		return(s->sic[s->top]);
	}

void pobo(struct stack *s)
	{
	//printf("%s\n",str);
		m=0;
		while(str[m]!='\0')
			m++;
			m--;
		while(m!=-1)
		{
			if(str[m]!='@')
			push(s,str[m]);
			m--;
		}
	}

void search(int l)
	{
		for(k=0;k<7;k++)
			if(in==tl[k])
				break;
			if(l==0)
			strcpy(str,c[l][k]);
			else if(l==1)
				strcpy(str,c[l][k]);
				else if(l==2)
					strcpy(str,c[l][k]);
					else if(l==3)
						strcpy(str,c[l][k]);
						else strcpy(str,c[l][k]);
	}

void main()
{
	struct stack s1;
	struct stack *s;
	s=&s1;
	s->top=-1;
	clrscr();

	printf("\t\tPARSING TABLE\n \t=============================================\n\n\tx\t+\t*\t(\t)\t$\n");
	printf(" \t=============================================\n\n");
	for(i=0;i<5;i++)
	{
		printf("%c\t",ntl[i]);
		for(j=0;j<6;j++)
		if(strcmp(c[i][j],"ERROR!")==0)
		printf("ERROR!\t");
		else
		printf("%c->%s\t",ntl[i],c[i][j]);
		printf("\n\n");
	}
	printf(" \t=============================================\n\n");
push(s,'$');
push(s,'E');
printf("\nENTER THE INPUT STRING: ");
scanf("%s",input);

	printf("\n\nTHE BEHAVIOUR OF THE PARSER FOR GIVEN INPUT STRING IS:\n\n");
	printf("STACK\tINPUT\tOUTPUT\n");
		i=0;
		in=input[i];
	printf("%s\t",s->sic);
		for(k=i;k<strlen(input);k++)
		printf("%c",input[k]);
		if(strcmp(str,"")!=0)
		printf("\t%c->%s",ntl[j],str);
		printf("\n");
		while((s->sic[s->top]!='$')&&err!=1&&strcmp(str,"ERROR!")!=0)
			{
				strcpy(str,"");
				flag=0;

				for(j=0;j<7;j++)
				if(in==tl[j])
					{
						flag=1;
						break;
					}
				if(flag==0)
					in='x';


				flag=0;
				out=sttop(s);
				for(j=0;j<7;j++)
				if(out==tl[j])
					{
						flag=1;
						break;
					}
				if(flag==1)
				{
					if(out==in)
					{
						temp=pop(s);
						in=input[++i];
					       if(str=='@')
					       temp=pop(s);
					       //	err=1;
					}
					else
					{
						strcpy(str,"ERROR!");
						err=1;
					}
				}
				else
				{
					flag=0;
					for(j=0;j<5;j++)
					if(out==ntl[j])
						{
							flag=1;
							break;
						}
					if(flag==1)
						{
							search(j);
							temp=pop(s);
							pobo(s);
						}
					else
						{
							strcpy(str,"ERROR!");
							err=1;
						}
				}
		if(strcmp(str,"ERROR!")!=0)
		{
		printf("%s\t",s->sic);
		for(k=i;k<strlen(input);k++)
		printf("%c",input[k]);
		if((strcmp(str,"")!=0)&&(strcmp(str,"ERROR!")!=0))
		printf("\t%c->%s",ntl[j],str);
		printf("\n");
		}
	}
if(strcmp(str,"ERROR!")==0)
printf("\n\nTHE STRING IS NOT ACCEPTED!!!!");
else printf("$\t$\tACCEPT\n\n\nTHE STRING IS ACCEPTED!!!");

getch();
}