#include <graphics.h>
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

char *fname[] = { "Tic-Tac-Toe",
		  "By Desai Ankit",
		};
char *s[]={"BLACK        ",
	   "BLUE         ",
	   "GREEN        ",
	   "CYAN         ",
	   "RED          ",
	   "MAGENTA      ",
	   "BROWN        ",
	   "LIGHTGRAY    ",
	   "DARKGRAY     ",
	   "LIGHTBLUE    ",
	   "LIGHTGREEN   ",
	   "LIGHTCYAN    ",
	   "LIGHTRED     ",
	   "LIGHTMAGENTA ",
	   "YELLOW       ",
	   "WHITE        "
	  };



void disply(char b[10])
{
int i;
clrscr();
printf("\n\n\n");
for(i=0;i<9;i++)
   {
   if ((i%3==0))
      {
       printf("\n\t\t\t---------------------");
       printf("\n\t\t\t|%3c  |",b[i]);
      }
     else
     printf("|%3c  |",b[i]);
   }
   printf("\n\t\t\t---------------------\n\n");
}

int win(char a[10],char c)
{
int x=0;
static m=0;
  m++;
  if((a[0]==c && a[1]==c && a[2]==c) || (a[0]==c && a[3]==c && a[6]==c) ||
  (a[0]==c && a[4]==c && a[8]==c) ||(a[1]==c && a[4]==c && a[7]==c) ||
  (a[2]==c && a[5]==c && a[8]==c) ||(a[2]==c && a[4]==c && a[6]==c) ||
  (a[3]==c && a[4]==c && a[5]==c) ||(a[6]==c && a[7]==c && a[8]==c))
  {
  x=1;
  m=0;
  }
  if(m==9)
  {
  x=2;
  m=0;
  }
return x;
}

void main()
{
int i,ans,flag=1,ch,count,j,k,choice,r,bc=7,tc=0;
char a[10],n1[30],n2[30],s1,s2,c,ans1='y';
int gdriver = DETECT, gmode, errorcode;
int midx, midy,o,p=50,q=219,l=1;
int size = 1;


   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

      settextjustify(CENTER_TEXT, CENTER_TEXT);
    j=7000;
   for (o=-20 ; o<=219 ; o++)
   {
      sound(j);
      if(l==16) l=1;
      setcolor(l);
      midx = getmaxx() / 2 - 10;
      midy = o;
      cleardevice();
      size = 8;
      settextstyle(1, HORIZ_DIR, size);
      outtextxy(midx, midy, fname[0]);
      if(o>50) p=45;
      if(o>100) p=35;
      if(o>150) p=25;
      delay(p);
      l++;
      j=j-75;
   }
   p=700;
   j=2500;
   for (o=500; o>=420; o--)
   {
      sound(j);
     cleardevice();
      if(l==16) l=1;
      if(o==420) l=13;
      setcolor(l);

      midx = getmaxx() / 2 - 10;
      midy = q;
      settextjustify(CENTER_TEXT, CENTER_TEXT);
	 size = 8;
      settextstyle(1, HORIZ_DIR, size);
      outtextxy(midx, midy, fname[0]);


	   size = 4;
	   midx = p ;
	   midy = o ;
	   if(o==420)setcolor(14);
	   settextjustify(RIGHT_TEXT, LEFT_TEXT);
	   settextstyle(4, HORIZ_DIR, size);
	   outtextxy(midx, midy, fname[1]);
      delay(50);
      if(p!=600) p--;
      q--;
      l++;
      j=j-100;
   }
 delay(1500);
closegraph();

jkl:
textbackground(bc);
textcolor(tc);

clrscr();
printf("\n\n\t\t1. One player(To play with computer)");
printf("\n\t\t2. Two players");
printf("\n\t\t3. Change Graphics ");
printf("\n\t\tOTHER KEY: To Exit");

j=4000;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j-100;
     }
    nosound();

printf("\n\n\t\tEnter your choice : ");
scanf("%d",&choice);

switch(choice)
{

case 3:

   int gdriver = 0, gmode = 0, errorcode;
   int color, maxcolor, x, y,i;
   char msg[80];
  initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
  errorcode = graphresult();

  if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
  maxcolor = getmaxcolor();


   settextjustify(CENTER_TEXT, CENTER_TEXT);
   x = 92;
   y = 10;
      setcolor(15);
      sprintf(msg, "See The Colors.",15);
      outtextxy(x, y, msg);

      j=4000;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j-100;
     }
    nosound();
    delay(1500);
    x=100;
    y=40;


   for (i=0; i<=maxcolor; i++)
   {
      if(i==0) color=15;
      else color=i;


      setcolor(color);
      if(i>=10)
      sprintf(msg,"%s: %d",s[i] , i);
      else
      sprintf(msg,"%s:  %d",s[i] , i);
      outtextxy(x, y, msg);

      if(i==0) color=0;
      color++;
      i++;
      x=x+350;

      setcolor(color);
      if(i>=10)
      sprintf(msg,"%s: %d",s[i] , i);
      else
      sprintf(msg,"%s:  %d",s[i] , i);
      outtextxy(x, y, msg);
      delay(900);
      x=100;
      y=y+20;
   }
     x = 100;
     y = y+40;
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n    ( 8 To 15 colors can't be set as BACKGROUND )\n\n    Enter for the background color :");
   scanf("%d",&bc);
   printf("    Enter for the foreground color :");
   scanf("%d",&tc);
   closegraph();
goto jkl;


case 1:

clrscr();
flushall();

printf("\n\n\t\tENTER THE PLAYER NAME : ");
j=4000;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j-100;
     }
    nosound();

gets(n1);

baj:printf("\t\tENTER THE SYMBOL OF PLAYER : ");
scanf("%c",&s1);
if(s1>47&&s1<58)
{
 printf("\a\n\t\tERROR:Symbol must not be digit.\n");
 flushall();
 goto baj;
}
if (s1!='@')
s2='@';
else
s2='*';
flag=1;
do
{
 count=0;

 for(i=0;i<9;i++)
 a[i]=49+i;
 textbackground(bc);
 textcolor(tc);
 ans=0;
  while (ans!=1)
   {
    clrscr();
    printf("\n\n\n");



    for (i=0;i<9;i++)
     {
     if ((i%3==0))
      {
       printf("\n\t\t\t---------------------");
       printf("\n\t\t\t|%3c  |",a[i]);
      }
     else
     printf("|%3c  |",a[i]);
    }
   printf("\n\t\t\t---------------------\n\n");
   if(flag==1)
    {
    j=4000;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j-100;
     }
    nosound();
    }
   else
    {
    j=500;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j+50;
     }
    nosound();
    }



if((a[0]==s1 && a[1]==s1 && a[2]==s1) || (a[0]==s1 && a[3]==s1 && a[6]==s1) ||
(a[0]==s1 && a[4]==s1 && a[8]==s1) ||(a[1]==s1 && a[4]==s1 && a[7]==s1) ||
(a[2]==s1 && a[5]==s1 && a[8]==s1) ||(a[2]==s1 && a[4]==s1 && a[6]==s1) ||
(a[3]==s1 && a[4]==s1 && a[5]==s1) ||(a[6]==s1 && a[7]==s1 && a[8]==s1))
 {
   textattr(15<<5);
   cprintf("\n\n\t\tCONGRATULATION %s  \n\n\t\tYOU WON THE GAME ",n1);
   j=500;
   for (i=1;i<100;i++)
    {
    sound(j);
    delay(150);
    j=j+50;
    }
   nosound();
   ans=1;
   flag=1;
 }

if((a[0]==s2 && a[1]==s2 && a[2]==s2) || (a[0]==s2 && a[3]==s2 && a[6]==s2) ||
(a[0]==s2 && a[4]==s2 && a[8]==s2) ||(a[1]==s2 && a[4]==s2 && a[7]==s2) ||
(a[2]==s2 && a[5]==s2 && a[8]==s2) ||(a[2]==s2 && a[4]==s2 && a[6]==s2) ||
(a[3]==s2 && a[4]==s2 && a[5]==s2) ||(a[6]==s2 && a[7]==s2 && a[8]==s2))
 {
  textattr(15<<5);
  cprintf("\n\n\t\tSORRY!!!!! YOU HAVE LOST THE GAME\n\n\t\t\tCOMPUTER HAS WON ");
  j=1;
  for (i=1;i<100;i++)
   {
   if(i<50)
    {
     sound(j);
     delay(100);
     j=j+50;
    }
   else
    {
     sound(j);
     delay(50);
     j=j-50;
    }
   }
  nosound();
  ans=1;
  flag=2;
 }


 if (ans==1)
 break;
 if (count==9)
  {
  printf("\n\n\t\t\"THE GAME IS DRAWN.\"");
  break;
  }
 count++;

 if (flag==1)
  {
   tri : printf("\n\t\t%s ENTER YOUR CHOICE : ",n1);
   scanf("%d",&ch);
    if (a[ch-1]>48 && a[ch-1]<59 && ch>=1 && ch<=9)
     {
     a[ch-1]=s1;
     flag=2;
     }
    else
    {
     printf("\a");
     goto tri;
    }
  }
 else if (flag==2)
   {
 ch=0;
for(k=0;k<2;k++)
{
 if(k==0) c=s2;
 else c=s1;
if(a[0]==c && a[1]==c && a[2]>48 && a[2]<58 ) ch=3;
else if(a[0]==c && a[2]==c &&  a[1]>48 && a[1]<58 ) ch=2;
else if (a[1]==c && a[2]==c &&  a[0]>48 && a[0]<58 ) ch=1;

else if (a[0]==c && a[3]==c &&  a[6]>48 && a[6]<58 ) ch=7;
else if (a[0]==c && a[6]==c &&  a[3]>48 && a[3]<58 ) ch=4;
else if (a[3]==c && a[6]==c &&  a[0]>48 && a[0]<58 ) ch=1;

else if (a[0]==c && a[4]==c &&  a[8]>48 && a[8]<58 ) ch=9;
else if (a[0]==c && a[8]==c &&  a[4]>48 && a[4]<58 ) ch=5;
else if (a[4]==c && a[8]==c &&  a[0]>48 && a[0]<58 ) ch=1;

else if (a[1]==c && a[4]==c &&  a[7]>48 && a[7]<58 ) ch=8;
else if (a[1]==c && a[7]==c &&  a[4]>48 && a[4]<58 ) ch=5;
else if (a[4]==c && a[7]==c &&  a[1]>48 && a[1]<58 ) ch=2;


else if (a[2]==c && a[5]==c &&  a[8]>48 && a[8]<58 ) ch=9;
else if (a[2]==c && a[8]==c &&  a[5]>48 && a[5]<58 ) ch=6;
else if (a[5]==c && a[8]==c &&  a[2]>48 && a[2]<58 ) ch=3;

else if (a[2]==c && a[4]==c &&  a[6]>48 && a[6]<58 ) ch=7;
else if (a[2]==c && a[6]==c &&  a[4]>48 && a[4]<58 ) ch=5;
else if (a[4]==c && a[6]==c &&  a[2]>48 && a[2]<58 ) ch=3;

else if (a[3]==c && a[4]==c &&  a[5]>48 && a[5]<58 ) ch=6;
else if (a[3]==c && a[5]==c &&  a[4]>48 && a[4]<58 ) ch=5;
else if (a[4]==c && a[5]==c &&  a[3]>48 && a[3]<58 ) ch=4;

else if (a[6]==c && a[7]==c &&  a[8]>48 && a[8]<58 ) ch=9;
else if (a[6]==c && a[8]==c &&  a[7]>48 && a[7]<58 ) ch=8;
else if (a[7]==c && a[8]==c &&  a[6]>48 && a[6]<58 ) ch=7;

if(ch!=0) break;
}
if(ch==0)
{
if (a[4]>48 && a[4]<58) ch=5;
else if (a[5]==s1 &&   a[2]>48 && a[2]<58 ) ch=3;
else if (a[3]==s1  &&  a[0]>48 && a[0]<58 ) ch=1;


else if (a[0]==s1 && a[8]==s1 &&  a[5]>48 && a[5]<58 ) ch=6;
else if (a[0]==s1 && a[8]==s1 &&  a[7]>48 && a[7]<58 ) ch=8;

else if (a[2]==s1 && a[6]==s1 &&  a[5]>48 && a[5]<58 ) ch=6;
else if (a[2]==s1 && a[6]==s1 &&  a[1]>48 && a[1]<58 ) ch=2;

else if (a[0]>48 && a[0]<58) ch=1;
else if (a[2]>48 && a[2]<58) ch=3;
else if (a[6]>48 && a[6]<58) ch=7;
else if (a[8]>48 && a[8]<58) ch=9;
else if (a[7]>48 && a[7]<58) ch=8;
else if (a[5]>48 && a[5]<58) ch=6;
else if (a[1]>48 && a[1]<58) ch=2;
else if (a[3]>48 && a[3]<58) ch=4;

}
printf("\n\n\t\t   COMPUTER IS THINKING ");
delay(600);
printf("\n\n\t\t   COMPUTER HAS CHOSEN : %d",ch);
delay(2000);

a[ch-1]=s2;
flag=1;
}
}
printf("\n\n\t\t   DO YOU WNAT TO PLAY AGAIN ? (Y\\N) : ");
scanf("\n%c",&ans1);
}
while (ans1=='y' || ans1=='Y');
goto jkl;

case 2:

clrscr();
flushall();
printf("\n\n\t\tENTER THE NAME OF PLAYER `A' : ");
j=4000;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j-100;
     }
    nosound();

gets(n1);
alj:printf("\t\tENTER THE SYMBOL OF PLAYER  `A' : ");
scanf("%c",&s1);

flushall();
if(s1>47&&s1<58)
{
printf("\a\n\t\tERROR:Symbol must not be digit.\n");
goto alj;
}

printf("\n\n\t\tENTER THE NAME OF PLAYER `B' : ");
gets(n2);

maj:printf("\t\tENTER THE SYMBOL OF PLAYER  `B' : ");
scanf("%c",&s2);
printf("\t\t%s %c %s",n1,s1,n2);
if ((s1==s2)||(s2>47&&s2<58))
 {
 printf("\a\n\t\tERROR:Symbol must not be digit.\n\t\t      OR Symbols must not be same.\n");
 flushall();
 goto maj;
 }


do
{
 count=0;

 for(i=0;i<9;i++)
 a[i]=49+i;
 textbackground(bc);
 textcolor(tc);
 ans=0;

while (ans!=1)
 {
  clrscr();

 if (count==9)
  {
  printf("\n\n\t\t         NO ONE WON THE GAME ");
  break;
  }
 count++;

 if (flag==1)
  {
   disply(a);
     j=4000;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j-100;
     }
    nosound();

   xyz : printf("\n\t\t%s ENTER YOUR CHOICE : ",n1);
   scanf("%d",&ch);
    if (a[ch-1]>48 && a[ch-1]<59 && ch>=1 && ch<=9)
     {
     a[ch-1]=s1;
     flag=2;
     }
    else
    {
    printf("\a");
    goto xyz;
    }
     r=win(a,s1);

    if(r==1)
    {
    j=500;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j+50;
     }
    nosound();
     delay(30);
    disply(a);
    textattr(15<<5);
    cprintf("\n\n\t\tCONGRATULATION %s  \n\n\t\tYOU WON THE GAME ",n1);
     j=1;
     for (i=1;i<100;i++)
     {
      if(i<50)
       {
	sound(j);
	delay(100);
	j=j+50;
       }
      else
       {
	sound(j);
	delay(50);
	j=j-50;
       }
     }
     nosound();
     flag=1;
     break;
   }
   else
   flag=2;

   if(r==2)
   {
   disply(a);
    j=500;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j+50;
     }
    nosound();
     delay(30);
   printf("\n\n\t\t\"THE GAME IS DRAWN.\"");
   break;
   }
 }


  if (flag==2)
  {
   disply(a);
    j=500;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j+50;
     }
    nosound();

   abc : printf("\n\t\t%s ENTER YOUR CHOICE : ",n2);
    scanf("%d",&ch);
    if (a[ch-1]>48 && a[ch-1]<59 && ch>=1 && ch<=9)
     {
     a[ch-1]=s2;
     }
    else
    {
     printf("\a");
     goto abc;
    }
    r=win(a,s2);

    if(r==1)
    {
	j=4000;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j-100;
     }
    nosound();
    delay(30);
    disply(a);
    textattr(15<<5);
    cprintf("\n\n\t\tCONGRATULATION %s  \n\n\t\tYOU WON THE GAME ",n2);
     j=1;
     for (i=1;i<100;i++)
     {
      if(i<50)
       {
	sound(j);
	delay(100);
	j=j+50;
       }
      else
       {
	sound(j);
	delay(50);
	j=j-50;
       }
     }
     nosound();
     flag=2;
     break;
   }
   else
   flag=1;
   if(r==2)
   {
   disply(a);
	j=4000;
    for (i=1;i<50;i++)
     {
      sound(j);
      delay(30);
      j=j-100;
     }
    nosound();
    delay(30);
   printf("\n\n\t\t\"THE GAME IS DRAWN.\"");
   break;
   }
  }

 }

 printf("\n\n\t\t   DO YOU WNAT TO PLAY AGAIN ? (Y\\N) : ");
 scanf("\n%c",&ans1);
 }
 while (ans1=='y' || ans1=='Y');
goto jkl;

default:
break;
}
}


