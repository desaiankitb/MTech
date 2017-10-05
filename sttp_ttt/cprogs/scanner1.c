#include <ctype.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
int             token;
char analysis[200];
int index;
next()
{
    token = getchar();
}

error(s)
     char           *s;
{
    printf("\n error in %s \n", s);
    for (next(); token != '\n'; next());
    index = 0;
}

/*------------------------------------------------------*/
main()
{
    
    while (1) {
        index = 0;
	func0();
    }
}

func0()
{
    next();
    if (isdigit(token)){
    	analysis[index++] = 'd';
	func2();
    }	
    else {
	if ((token == '+') || (token == '-')){
	    analysis[index++] = token;
	    func1();
	}    
	else {
	    if (token == '.'){
	        analysis[index++] = '.';
		func3();
	    }
	    else
		error("func0");
	}
    }
}

/*-----------------------------------------------------*/
func1()
{
    next();
    if (isdigit(token)){
        analysis[index++] = 'd';
	func2();
    }	
    else {
	if (token == '.'){
            analysis[index++] = '.';
	    func3();
	}
	else
	    error("func1");
    }
}

func2()
{
    next();
    if (isdigit(token)){
        analysis[index++] = 'd';
	func2();
    }
    else {
	if (token == '.'){
	    analysis[index++] = '.';
	    func4();
	}
	else
	    func5();
    }
}

func3()
{
    next();
    if (isdigit(token)){
        analysis[index++] = 'd';
	func4();
    }	
    else
	error("func3");
}

func4()
{
    next();
    if (isdigit(token)){
        analysis[index++] = 'd';    
	func4();
    }
    else
	func5();
}

func5()
{
    if (token == '\n') {
        analysis[index] = 0;
	printf("\nOK: %s\n", analysis);
    } else
	error("func5");
}
