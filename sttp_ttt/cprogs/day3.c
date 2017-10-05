	#include <stdio.h>	

	float Plus(float, float);
	float Minus(float, float);
	float Mul(float, float);
	float Div(float, float);
	
	void  Switch(float, float, char);
	int main()
	{
		float fA,fB,fResult;
		char chOp;
		int iIndex;
		//float (*fp[])(float,float) = {Plus,Minus,Mul,Div};
		printf("\n\n\t Enter the Operator:");
                //fflush(stdin);
                scanf("%c%c",&chOp);

		printf("\n\n\t Enter the value for a:");
		scanf("%f",&fA);
		printf("\n\n\t Enter the value for b:");
                scanf("%f",&fB);
			
		Switch(fA,fB,chOp);
	
		/*for( iIndex=0; iIndex < 4//(sizeof(fp) / sizeof(fp[iIndex]))
					; iIndex++ )
		{
			fResult = fp[iIndex](fA,fB);
			printf("\n\n\tAns::%f",fResult);
		}*/
		
		return 0;		
	}
	
	void Switch(float a,float b,char ch)
	{
		float (*fp)(float, float);
		float fResult = 0.0;
		switch(ch)
		{
			case '+': fp = &Plus; fResult = fp(a,b); break;
			case '-': fp = &Minus; fResult = fp(a,b); break;
			case '*': fp = &Mul; fResult = fp(a,b); break;
			case '/': fp = &Div; fResult = fp(a,b); break;
		}	
		printf("\n\n\tAns::%f",fResult);
	}
	
	float Plus(float a, float b)
	{
		return (a+b);	
	}
	float Minus(float a, float b)
        {
                return (a-b);
        }
	float Mul(float a, float b)
        {
                return (a*b);
        }
	float Div(float a, float b)
        {
                return (a/b);
        }


