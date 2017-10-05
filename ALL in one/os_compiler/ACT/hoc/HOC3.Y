%{
#include "c:\99140\hoc.h"
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<signal.h>
#include<setjmp.h>
#include "c:\99140\init.c"
#include "c:\99140\symbol.c"
#include "c:\99140\math.c"
extern double Pow();
%}
%union  {
	 double val;
	 Symbol *sym;
}
%token <val> NUMBER
%token <sym> VAR BLTIN UNDEF
%type <val> expr asgn
%right '='
%left '+' '-'
%left '*' '/'
%left UNARYMINUS
%right '^'
%%
list:
      | list '\n'
      | list asgn '\n'
      | list expr '\n'        { printf("\t%.8g\n",$2); }
      | list error '\n'       { yyerrok; }
      ;
asgn:   VAR '=' expr { $$=$1->u.val=$3; $1->type = VAR; }
      ;
expr:   NUMBER
      | VAR { if ($1->type == UNDEF)
		 execerror("undefined variable", $1->name);
	     $$ = $1->u.val; }
      | asgn
      | BLTIN '(' expr ')'   { $$ = (*($1->u.ptr))($3); }
      | expr '+' expr { $$ = $1 + $3 ; }
      | expr '-' expr { $$ = $1 + $3 ; }
      | expr '*' expr { $$ = $1 * $3 ; }
      | expr '/' expr {
	     if($3 == 0.0)
		 execerror("division by zero ","");
	     $$ = $1 / $3; }
      | expr '^' expr { $$ = Pow($1, $3); }
      | '(' expr ')' { $$ = $2 ; }
      | '-' expr %prec UNARYMINUS { $$ = -$2 ; }
      ;
%%


jmp_buf begin;
#ifdef __cplusplus
typedef void (*fptr)(int);
#else
typedef void (*fptr)();
#endif
char *progname;
int lineno = 1;

main(argc,argv)
      char *argv[];
 {
     int fpecatch();

     progname = argv[0];
     init();
     setjmp(begin);
     signal(SIGFPE, (fptr)fpecatch);
     yyparse();
}


yyerror(s)
   char *s;
{
  warning(s, (char *) 0);
}

warning(s,t)
    char *s, *t;
{
    fprintf(stderr, "%s: %s", progname, s);
    if (t)
	   fprintf(stderr, " %s", t);
    fprintf(stderr, " near line %d\n", lineno);
}


execerror(s,t)
	char *s , *t;
{
	warning(s,t);
	longjmp(begin,0);
}

fpecatch()
{
	execerror("floating point exception",(char *) 0);
}


yylex()
{
	int c;

	while ((c=getchar()) == ' ' || c == '\t')
			     ;
	if (c == EOF)
		return 0;
	if (c == '.' || isdigit(c))   {
		 ungetc(c,stdin);
		 scanf("%lf", &yylval.val);
		 return NUMBER;
	}
	if (c == '\n')
	       lineno++;
	/*if(islower(c)) {
	yylval.index = c - 'a';
	return VAR;
	} */
       if(isalpha(c)) {
		Symbol *s ;
		char sbuf[100], *p = sbuf;
		do {
			*p++ = c;
		} while((c=getchar()) != EOF && isalnum(c));
		ungetc(c, stdin);
		*p = '\0';
		if ((s=lookup(sbuf)) == 0)
			s = install(sbuf,UNDEF,0.0);
		yylval.sym = s;
		return s->type == UNDEF ? VAR : s->type;
      }
      return c;
}


/*#include<math.h>
#include<errno.h>
extern int  errno;
double errcheck();

double Log(x)
       double x;
{
	return errcheck(log(x), "log");
}
double Log10(x)
	double x;
{
	return errcheck(log10(x),"log10");
}
double Exp(x)
	double x;
{
	 return errcheck(exp(x),"exp");
}
double Sqrt(x)
	double x ;
{
	return ercheck(sqrt(x),"sqrt");
}
double Pow(x, y)
	double x,y;
{
	return errcheck(pow(x, y), "exponentiation");
}
double integer(x)
	double x;
{
	return (double)(long)x;
}
double errcheck(d, s)
	double d;
	char *s;
{
	if(errno == EDOM)  {
		    errno=0;
		    execerror(s, "argument out of domain");
	} else if(errno == ERANGE) {
		errno = 0;
		execerror(s, "result out of range");
       }
       return d;
}
$ */


