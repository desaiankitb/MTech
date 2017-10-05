#include<dos.h>

int initmouse()
{
   _AX=0;
   geninterrupt(0x33);
   return(_AX);
}

void showmouse()
{
 _AX=1;
 geninterrupt(0x33);
}


void getmouse(int *b,int *x, int *y)
{
 _AX=3;
 geninterrupt(0x33);
* b=_BX ;
* x=_CX;
* y=_DX;
}

void hidemouse()
{
_AX=2;
geninterrupt(0x33);
}