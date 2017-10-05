/*=============================================================*/
/*
 * A SIMPLE RECURSIVE DESCENT PARSER 
 */
/*-------------------------------------------- Parag Dave -----*/
#include <stdio.h>
#include <string.h>
/* #include <conio.h> */
int             pos,
                err,
                t;
char            str[82];
poscur()
{
    int             i;
    printf("\n");
    for (i = 0; i < pos; i++)
	putchar(' ');
}
enter(s)
     char           *s;
{
    pos += 3;
    poscur();
    printf("%s", s);
}
out()
{
    poscur();
    printf("|");
    pos -= 3;
}
error(i)
     int             i;
{
    err = 1;
    printf(" error number %d\n", i);
    while (mgetch() != '\0');
}
nextsymbol()
{
    int             c;
    c = mgetch();
    mungetc();
    return (c);
}
pE()
{
    enter("pE");
    pT();
    while (nextsymbol() == '+') {
	pplus();
	pT();
    }
    out();
}
pT()
{
    enter("pT");
    pF();
    while (nextsymbol() == '*') {
	ppast();
	pF();
    }
    out();
}
pF()
{
    enter("pF");
    switch (nextsymbol()) {
    case '(':{


	    plp();
	    pE();
	    prp();
	    break;
	}


    case 'a':{
	    pa();
	}


    }
    out();
}
pa()
{
    enter("pa");
    if (symbol() != 'a')
	error(1);
    out();
}
plp()
{
    enter("plp");
    if (symbol() != '(')
	error(2);
    out();
}
prp()
{
    enter("prp");
    if (symbol() != ')')
	error(3);
    out();
}
pplus()
{
    enter("pplus");
    if (symbol() != '+')
	error(4);
    out();
}
ppast()
{
    enter("ppast");
    if (symbol() != '*')
	error(5);
    out();
}
symbol()
{
    int             c;
    c = mgetch();
    return (c);
}
mgetch()
{
    char c;
    
    t++;
    c =str[t];
    return ((c>='a' && c <= 'z')?'a':c);
}
mungetc()
{
    t--;
}
main()
{
    int             c;
    while (1) {
	err = 0;
	pos = 0;
	t = -1;
	fgets(str,82,stdin);
	printf("\n%s", str);
	pE();
	c = mgetch();
	if (c == '\n') {
	    if (!err) {
		printf("\n ACCEPTED\n");
	    } else
		printf("\n REJECTED\n");
	}
    }
}
