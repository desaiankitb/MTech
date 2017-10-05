%{

	int lines = 0, chars = 0,w=0;

%}


%%
\n		++lines; ++chars;
.		++chars;
[^ \t\n]+	++w; chars+=yyleng;
%%
int main ()
{
	yylex ();
	printf ("There were %d lines and %d words and %d characters.\n",lines,w,chars);
	return 0;
}

