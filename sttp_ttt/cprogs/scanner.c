#include <ctype.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
int             token;
next()
{
    token = getchar();
}

error(s)
     char           *s;
{
    printf("\n error: %s \n", s);
    for (next(); token != '\n'; next());
}

/*------------------------------------------------------*/
main()
{
    while (1) {
	func0();
    }
}

func0()
{
    next();
    if (isdigit(token))
	func2();
    else {
	if ((token == '+') || (token == '-'))
	    func1();
	else {
	    if (token == '.')
		func3();
	    else
		error("NAN");
	}
    }
}

/*-----------------------------------------------------*/
func1()
{
    next();
    if (isdigit(token))
	func2();
    else {
	if (token == '.')
	    func3();
	else
	    error("Digit or . expected");
    }
}

func2()
{
    next();
    if (isdigit(token))
	func2();
    else {
	if (token == '.')
	    func4();
	else
	    func5();
    }
}

func3()
{
    next();
    if (isdigit(token))
	func4();
    else
	error("Digit expected");
}

func4()
{
    next();
    if (isdigit(token))
	func4();
    else
	func5();
}

func5()
{
    if (token == '\n') {
	printf("\nNUMBER\n");
    } else
	error("invalid");
}
