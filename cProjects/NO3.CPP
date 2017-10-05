#include <graphics.h>
#include<iostream.h>
#include<dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<time.h>

class k
{
int a,b;
char l,m;
public:
void d1(int);
void win(long int);
void gameover(long int);
void graphs(int);
void blink(int);
void life(int);
void bg(int,char *s);
void br(int g,int g1,char *s,char *s1);
void gr_50();
void gr_ap();
void color_y();
void ap(int,int,int,int,int);
void selans(int,int,int,int,int);
void sq();
void sn();
};




void k:: ap(int p1,int p2,int p3,int p4,int pc)
    {
     sound(700);
  delay(600);
  nosound();
setfillstyle(SOLID_FILL,9);
 settextstyle(SMALL_FONT, HORIZ_DIR, 4);
 setcolor(1);
outtextxy(135,5,"Audiance Pole" );
rectangle(130,20,215,145);
rectangle(130,145,215,160);
bar3d(145,145-p1,155,145,5,1);
bar3d(160,145-p2,170,145,5,1);                      //  EMPTY_FILL",
bar3d(175,145-p3 ,185 ,145, 5,1);
bar3d(190,145-p4 ,200,145, 5,1);

  settextstyle(SMALL_FONT, HORIZ_DIR, 3);

  setcolor(4);

 switch(pc)
 {
  case 0:
   outtextxy(145,150,"40%");
  outtextxy(160,150,"20%");
  outtextxy(175,150,"10%");
  outtextxy(190,150,"30%");
break;
case 1:
   outtextxy(145,150,"03%");
  outtextxy(160,150,"32%");
  outtextxy(175,150,"31%");
  outtextxy(190,150,"34%");
break;
case 2:
   outtextxy(145,150,"35%");
  outtextxy(160,150,"15%");
  outtextxy(175,150,"11%");
  outtextxy(190,150,"29%");
break;
case 3:
   outtextxy(145,150,"10%");
  outtextxy(160,150,"60%");
  outtextxy(175,150,"22%");
  outtextxy(190,150,"8%");
break;
case 4:
   outtextxy(145,150,"17%");
  outtextxy(160,150,"23%");
  outtextxy(175,150,"40%");
  outtextxy(190,150,"30%");
break;
case 5:
   outtextxy(145,150,"15%");
  outtextxy(160,150,"05%");
  outtextxy(175,150,"60%");
  outtextxy(190,150,"20%");
break;
case 6:
   outtextxy(145,150,"10%");
  outtextxy(160,150,"20%");
  outtextxy(175,150,"30%");
  outtextxy(190,150,"40%");
break;
case 7:
   outtextxy(145,150,"10%");
  outtextxy(160,150,"10%");
  outtextxy(175,150,"35%");
  outtextxy(190,150,"45%");
break;
case 8:
   outtextxy(145,150,"25");
  outtextxy(160,150,"40");
  outtextxy(175,150,"25%");
  outtextxy(190,150,"10%");
break;
case 9:
   outtextxy(145,150,"40%");
  outtextxy(160,150,"10%");
  outtextxy(175,150,"20%");
  outtextxy(190,150,"30%");
break;

case 10:
   outtextxy(145,150,"40%");
  outtextxy(160,150,"20%");
  outtextxy(175,150,"10%");
  outtextxy(190,150,"30%");
break;
  }
  setcolor(9);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   outtextxy(145,15,"A");
  outtextxy(160,15,"B");
  outtextxy(175,15,"C");
  outtextxy(190,15,"D");
  line(130,37,215,37);
   setcolor(15);
  }

  void k:: gameover(long int p)
{
   sound(70);

  delay(3100);
   nosound();
    cleardevice();
     _setcursortype(_NOCURSOR);
   textmode(1);
   gotoxy(15,6);
   textcolor(14);

   cprintf("GAME OVER");
   cout<<endl;
   gotoxy(12,12);
    textcolor(4 + BLINK);
   cprintf("Price money is %ld",p);
   delay(2000);
    clrscr();
   cleardevice();
   delay(1000);
   textcolor(6);
   settextstyle(SMALL_FONT, HORIZ_DIR, 5);
   for(int z=24;z>8;z--)
   {
   clrscr();
    gotoxy(25,z);
    outtextxy(25,z,"DEVELOPED BY:");

    settextstyle(SMALL_FONT, HORIZ_DIR, 4);
    outtextxy(26,z+2,"RAVI SUHANE");

    settextstyle(SMALL_FONT, HORIZ_DIR, 3);
    outtextxy(26,z+3,"JEC JABALPUR");

    delay(500);
   }



     }

     void k::win(long int p)
     {
     clrscr();
      textmode(1);
       _setcursortype(_NOCURSOR);
   gotoxy(15,6);
   textcolor(14);
   cprintf("WIN");
   cout<<endl;
   gotoxy(12,12);
    textcolor(4 + BLINK);
   cprintf("Price money is %ld",p);
 }
   void k::graphs(int c)
   {
   int r,t;
   setcolor(1);
   rectangle(10,5,120,160);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    setcolor(15);
    if(c==11)
      {
      setcolor(4);
      }
    outtextxy(15,8,"10000000");
    if(c==10)
      {
      setcolor(4);
      }
     outtextxy(15,20,"5000000");
     if(c==9)
      {
      setcolor(4);
      }
      outtextxy(15,32,"2500000");
      if(c==8)
      {
      setcolor(4);
      }
      outtextxy(15,44,"1000000");
      if(c==7)
      {
      setcolor(4);
      }
      outtextxy(15,56,"500000");
      if(c==6)
      {
      setcolor(4);
      }
      outtextxy(15,68,"100000");
      if(c==5)
      {
      setcolor(4);
      }
      outtextxy(15,80,"50000");
      if(c==4)
      {
      setcolor(4);
      }
      outtextxy(15,92,"25000");
      if(c==3)
      {
      setcolor(4);
      }
      outtextxy(15,104,"10000");
       if(c==2)
      {
      setcolor(4);
      }
      outtextxy(15,116,"5000");
      if(c==1)
      {
      setcolor(4);
      }
      outtextxy(15,128,"1000");
      setcolor(4);
       outtextxy(15,140,"0");
	setcolor(1);
       settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   ellipse(320,210,0,360,290,22);
   ellipse(170,278,0,360,115,15);
   ellipse(460,278,0,360,115,15);
   ellipse(170,340,0,360,115,15);
   ellipse(460,340,0,360,115,15);
     line(285,278,345,278);
      outtextxy(330,260,"B");
     line(285,340,345,340);
      outtextxy(330,321,"D");
     line(0,278,55,278);
     outtextxy(40,260,"A");
     line(575,278,660,278);
      line(0,340,55,340);
       outtextxy(40,321,"C");
     line(575,340,660,340);
     line(0,210,30,210);
     line(610,210,660,210);

      for(r=0;r<=650;r++)
 {
   if(r<=220)
   {
   t=6;
   }
     if(r<440&r>220)
   {
   t=15;
   }
     if(r<660&r>440)
   {
   t=2;
   }
putpixel(r,470,t);
 putpixel(r,472,t);
 putpixel(r,471,t);
 putpixel(r,473,t);
 putpixel(r,469,t);
 putpixel(r,468,t);
 putpixel(r,467,t);
 putpixel(r,466,t);
  putpixel(r,465,t);
 putpixel(r,464,t);
 putpixel(r,463,t);
 putpixel(r,462,t);
 putpixel(r,461,t);
  putpixel(r,460,t);
 putpixel(r,459,t);
 putpixel;(r,458,t);
 putpixel(r,457,t);
}
 setcolor(15);

}

     void k::gr_50()
     {
     setfillstyle(SOLID_FILL, 4);
fillellipse(460, 25, 40, 25);
outtextxy(438,15,"50:50");
}
void k::gr_ap()
     {
     setfillstyle(SOLID_FILL, 1);
fillellipse(460, 100, 40, 25);
 setfillstyle(SOLID_FILL, 0);
fillellipse(445, 98, 4, 5);
 fillellipse(460, 98, 4, 5);
 fillellipse(475, 98, 4, 5);
 fillellipse(445, 110, 6, 8);
 fillellipse(460, 110, 6, 8);
 fillellipse(475, 110, 6, 8);
}

     void k::bg(int g,char *s)        //pass b
     {
     int i,x,y,w,h;
     switch(g)
     {
     case 1:
     x= 170;y=278;w=115;h=15;
     break;
	 case 2:
     x= 460;y=278;w=115;h=15;
     break;
	case 3:
     x= 170;y=340;w=115;h=15;
     break;
	case 4:
     x= 460;y=340;w=115;h=15;
       break;
       }
	setfillstyle(SOLID_FILL,6);
	fillellipse(x,y,w,h);
	outtextxy(x-90,y-13,s);
	delay(2500);
	for(i=0;i<=10;i++)
       {
       sound(1000+i*20);
       delay(230);
       }
     for(i=0;i<=5;i++)
       {
	 setfillstyle(SOLID_FILL, 2);
	fillellipse(x,y,w,h);
	outtextxy(x-90,y-13,s);
	delay(500);
		setfillstyle( EMPTY_FILL, 0);
	fillellipse(x,y,w,h);
		outtextxy(x-90,y-13,s);
	delay(500);
	 nosound();
       }
}

void k::br(int r,int g1 ,char *s,char *s1)        //pass b
     {
     int j,x1,y1,w1,h1,x,y,w,h;
      char str[20];
       strcpy(str,s);

	switch(g1)
     {
     case 1:
     x= 170;y=278;w=115;h=15;
    // strcpy(str,s);
     break;
	 case 2:
     x= 460;y=278;w=115;h=15;
     break;
	case 3:
     x= 170;y=340;w=115;h=15;
     break;
	case 4:
     x= 460;y=340;w=115;h=15;
       break;
       }
     switch(r)
     {
     case 1:
     x1= 170;y1=278;w1=115;h1=15;
     break;
	 case 2:
     x1= 460;y1=278;w1=115;h1=15;
     break;
	case 3:
     x1= 170;y1=340;w1=115;h1=15;
     break;
	case 4:
     x1= 460;y1=340;w1=115;h1=15;
       break;
       }
	setfillstyle(SOLID_FILL,6);
	fillellipse(x1,y1,w1,h1);
	outtextxy(x1-90,y1-13,s);
	delay(2500);
     for(j=0;j<=5;j++)
       {
	setfillstyle(SOLID_FILL, 4);
	fillellipse(x1,y1,w1,h1);
		outtextxy(x1-90,y1-13,s);
		 setfillstyle(SOLID_FILL, 2);
		fillellipse(x,y,w,h);
		outtextxy(x-90,y-13,s1);
	sound(700-100*j);
	delay(500);
	setfillstyle(SOLID_FILL, 0);
	fillellipse(x1,y1,w1,h1);
		outtextxy(x1-90,y1-13,s);
	 delay(500);
       }
       nosound();
}

 void k::life(int f)
 {
  setcolor(0);
  sound(1100);
  delay(800);
  nosound();
 switch(f)
 {
case 0:
outtextxy(80,327,"Bargi");
outtextxy(370,327,"Nagarjuna");
 setcolor(15);
break;
case 1:
outtextxy(80,265,"Sugar");
 outtextxy(80,327,"Water");
  setcolor(15);
  break;
 case 2:
outtextxy (80,265,"Marse");
outtextxy(360,265,"Saturn ");
setcolor(15);
  break;
  case 3:
  outtextxy(80,327,"Indo-Greek");
outtextxy(370,327,"Indo-Chinese");
setcolor(15);
  break;
  case 4:
  outtextxy(360,265,"Norway");
outtextxy(370,327,"Australia");
setcolor(15);
  break;
case 5:
  outtextxy(80,265,"Abul Fazal");
outtextxy(360,265,"Ramdas");
setcolor(15);
  break;
  case 6:
  outtextxy(80,327,"Bhutan");
outtextxy(370,327,"Bangladesh");
setcolor(15);
  break;
  case 7:
  outtextxy(80,265,"764 watts");
outtextxy(360,265,"760 watts ");
setcolor(15);
  break;
  case 8:
  outtextxy(80,327,"Green");
outtextxy(370,327,"Pink");
setcolor(15);
  break;
  case 9:
  outtextxy(360,265,"Newton ");
outtextxy(80,327,"Edison");
setcolor(15);
  break;
  case 10:
  outtextxy(360,265,"Plants");
outtextxy(80,327,"Animals");
setcolor(15);
  break;
  }
  }
  void k::selans(int a1,int a2,int a3,int a4,int a)
  {
   if(m!='n')
{ outtextxy(220,90,"Enter 6 for:        ");
  gr_ap();
 }
if (l!='n')
{
outtextxy(220,10,"Enter 5 for:");
gr_50();
cin>>b;
if(b==5)
{
life(a);
 l='n';
 if(m!='n')
 {
 cin>>b;
 if(b==6)
 {
 ap(a1,a2,a3,a4,a);
 m='n';
cin>>b;
 }}}}
if(m!='n')
   {
//cin>>b;
    if(b==6)
    {
  ap(a1,a2,a3,a4,a);
  m='n';
 cin>>b;
  if(l!='n')
  {
  if(b==5)
  {
   life(a);
 l='n';
 cin>>b;
   }}}}

   if(l=='n'&m=='n')
   {
   cin>>b;
    }
}

void k::sq()
{
 sound(900);
 delay(350);
 nosound();
  sound(300);
 delay(300);
 nosound();
  sound(200);
 delay(400);
 nosound();
  sound(150);
 delay(1800);
 nosound();
 delay(3000);
}
void k::sn()
{
//sound(600);
//delay(400);
////nosound();
delay(1500);
 }
void k::d1(int a)
{
setcolor(15);
switch(a)
{
case 0:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
gr_50();
gr_ap();

outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q1. Which is the bigest dam in India");
sq();
outtextxy(80,265,"Hirakund");
sn();
outtextxy(360,265," Tehari ");
sn();
outtextxy(80,327,"Bargi");
sn();
outtextxy(370,327,"Nagarjuna");
sn();
outtextxy(220,10,"Enter 5 for:        ");
outtextxy(220,90,"Enter 6 for:        ");
 selans(40,10,20,30,a);
if(b==1)
 {
 bg(b,"Hirakund");    //blinking the right ans
 a=1;
  }
 if(b!=1)
 {
  switch(b)
  {
  case 2:
  br(b,1,"Tehari","Hirakund");	      //blinking wrong ans
   break;
   case 3:
  br(b,1,"Bargi","Hirakund");
  break;
   case 4:
  br(b,1,"Nagarjuna","Hirakund");
  break;
   }
  gameover(0);
  break;
  }
 case 1:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q2. Milk always contains");
sq();
outtextxy(80,265,"Sugar");
sn();
outtextxy(360,265," Fats ");
sn();
outtextxy(80,327,"Water");
sn();
outtextxy(370,327,"Calcium");
sn();
selans(3,32,31,34,a);
if(b==4)
 {
 bg(b,"Calcium");    //blinking the right ans
 a=2;
  }
 if(b!=4)
 {
  switch(b)
  {
  case 1:
  br(b,4,"Sugar","Calcium");                //blinking wrong ans
  break;
   case 2:
  br(b,4,"Fats","Calcium");
  break;
   case 3:
  br(b,4,"Water","Clcium");
  break;
    }
  gameover(1000);
break;
}
 case 2:
     cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q3. The largest planet is");
sq();
outtextxy(80,265,"Marse");
sn();
outtextxy(360,265,"Saturn ");
sn();
outtextxy(80,327,"Pluto");
sn();
outtextxy(370,327,"Jupiter");
sn();
selans(35,15,10,40,a);
if(b==4)
 {
 bg(b,"Jupiter");    //blinking the right ans
 a=3;
  }
 if(b!=4)
 {
  switch(b)
  {
  case 1:
  br(b,4,"Marse","Jupiter");                //blinking wrong ans
  break;
   case 2:
  br(b,4,"Sturn","Jupiter");
  break;
   case 3:
  br(b,4,"Pluto","Jupiter");
  break;
    }
  gameover(5000);
 break;
  }
 case 3:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(80,200,"Q4. Taj Mahal is an example of Which type of architect.");
 sq();
outtextxy(80,265,"India-British");
sn();
outtextxy(360,265,"Indo-Persian ");
sn();
outtextxy(80,327,"Indo-Greek");
sn();
outtextxy(370,327,"Indo-Chinese");
sn();
selans(10,60,20,10,a);
if(b==2)
 {
 bg(b,"Indo-Persian");    //blinking the right ans
 a=4;
  }
 if(b!=2)
 {
  switch(b)
  {
  case 1:
  br(b,2,"India-British","Indo-Percian");                //blinking wrong ans
  break;
   case 3:
  br(b,2,"Indo-Greek","Indo-Percian");
  break;
   case 4:
  br(b,2,"Indo-Chinese","Indo-Percian");
  break;
    }
  gameover(10000);
 break;
  }
 case 4:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q5. Which country is more advanced in ship-building?");
sq();
outtextxy(80,265,"Japan");
sn();
outtextxy(360,265,"Norway");
sn();
outtextxy(80,327,"Canada");
sn();
outtextxy(370,327,"Australia");
sn();
selans(20,10,40,30,a);
if(b==1)
 {
 bg(b,"Japan");    //blinking the right ans
 a=5;
  }
 if(b!=1)
 {
  switch(b)
  {
  case 4:
  br(b,1,"Australia","Japan");                //blinking wrong ans
  break;
   case 2:
  br(b,1,"Norway","Japan");
  break;
   case 3:
  br(b,1,"Canada","Japan");
  break;
    }
  gameover(25000);
 break;
  }
     case 5:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q6. A great musician in the court of Akbar was");
sq();
outtextxy(80,265,"Abul Fazal");
sn();
outtextxy(360,265,"Ramdas");
sn();
outtextxy(80,327,"Tansen");
sn();
outtextxy(370,327," Amir Khusro");
sn();
ap(15,5,60,20,5);
if(b==3)
 {
 bg(b,"Tansen");    //blinking the right ans
 a=6;
  }
 if(b!=3)
 {
  switch(b)
  {
  case 1:
  br(b,3,"Abul Fazal","Tansen");                //blinking wrong ans
  break;
   case 2:
  br(b,3,"Ramdas","Tansen");
  break;
   case 4:
  br(b,3,"Amir Khusro","Tansen");
  break;
    }
  gameover(50000);
 break;
  }
case 6:
 cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q7. The Naga hills form the watershed between India and");
sq();
outtextxy(80,265,"China");
sn();
outtextxy(360,265,"Myanmar ");
sn();
outtextxy(80,327,"Bhutan");
sn();
outtextxy(370,327,"Bangladesh");
sn();
  selans(10,20,30,40,a);
 if(b==2)
 {
 bg(b,"Myanmar");    //blinking the right ans
 a=7;
  }
 if(b!=2)
 {
  switch(b)
  {
  case 1:
  br(b,2,"China","Myanmar");                //blinking wrong ans
  break;
   case 4:
  br(b,2,"Bangladesh","Myanmar");
  break;
   case 3:
  br(b,2,"Bhutan","Myanmar");
  break;
    }
  gameover(100000);
 break;
  }
  case 7:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q8. One horse power Equls approximately");
sq();
outtextxy(80,265,"764 watts");
sn();
outtextxy(360,265,"760 watts ");
sn();
outtextxy(80,327,"476 watts");
sn();
outtextxy(370,327,"746 watts");
sn();
selans(10,10,35,45,a);
if(b==4)
 {
 bg(b,"746 watts");    //blinking the right ans
 a=8;
  }
 if(b!=4)
 {
  switch(b)
  {
  case 1:
  br(b,4,"764 watts","746 watts");                //blinking wrong ans
  break;
   case 2:
  br(b,4,"760 watts","746 watts");
  break;
   case 3:
  br(b,4,"476 watts","746 watts");
  break;
    }
  gameover(500000);
 break;
  }
      case 8:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q9. A red rose will appear through green light");
sq();
outtextxy(80,265,"Blue");
sn();
outtextxy(360,265,"Dark");
sn();
outtextxy(80,327,"Green");
sn();
outtextxy(370,327,"Pink");
sn();
 selans(25,40,25,10,a);
if(b==2)
 {
 bg(b,"Dark");    //blinking the right ans
 a=9;
  }
 if(b!=2)
 {
  switch(b)
  {
  case 1:
  br(b,2,"Blue","Dark");                //blinking wrong ans
  break;
   case 4:
  br(b,2,"Pink","Dark");
  break;
   case 3:
  br(b,2,"Green","Dark");
  break;
    }
  gameover(1000000);
 break;
  }
   case 9:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q10. Television was invented by");
sq();
outtextxy(80,265,"Baird");
sn();
outtextxy(360,265,"Newton ");
sn();
outtextxy(80,327,"Edison");
sn();
outtextxy(370,327,"Marconi");
sn();
selans(40,10,20,30,a);
if(b==1)
 {
 bg(b,"Baird");    //blinking the right ans
 a=10;
  }
 if(b!=1)
 {
  switch(b)
  {
  case 4:
  br(b,1,"Marconi","Baird");                //blinking wrong ans
  break;
   case 2:
  br(b,1,"Newton","Baird");
  break;
   case 3:
  br(b,1,"Edison","Baird");
  break;
    }
  gameover(2500000);
 break;
  }
   case 10:
cleardevice();
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
graphs(a);
outtextxy(220,50, "Enter 1 for: A,2 for: B,3 for: C,4 for: D");
outtextxy(100,200,"Q11.Metrology is the science of");
sq();
outtextxy(80,265,"Atmosphere");
sn();
outtextxy(360,265,"Plants");
sn();
outtextxy(80,327,"Animals");
sn();
outtextxy(370,327," None");
sn();
selans(40,10,20,30,a);
if(b==1)
 {
 bg(b,"Atmosphere""Atmosphere");    //blinking the right ans
 a=11;
  }
 if(b!=1)
 {
  switch(b)
  {
  case 4:
  br(b,1,"None","Atmosphere");                //blinking wrong ans
  break;
   case 2:
  br(b,1,"Plants","Atmosphere");
  break;
   case 3:
  br(b,1,"Animals","Atmosphere");
  break;
    }
  gameover(5000000);
 break;
  }
   win(10000000);
  }
}
void main()
{
clrscr();
/* request autodetection */
  int gdriver = DETECT, gmode,i;

  /* initialize graphics and local variables */
  initgraph(&gdriver, &gmode, "");
    _setcursortype(_NOCURSOR);
 for(i=0;i<=110;i++)
 {
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 setcolor(1);
 circle(310,247,i);
// sound(1000+100*i);
 delay(5);
 nosound();
 }
for(i=0;i<=100;i++)
{
 setcolor(4);
 circle(310,247,i);
 //sound(100+100*i);
 delay(10);
 nosound();
}
// textmode(C40);
  setcolor(0);
  settextstyle(BOLD_FONT, HORIZ_DIR, 1);
  outtextxy(283,220,"KBC");
   setcolor(4);

 for(i=0;i<=600;i++)
 {
 putpixel(636,600-i,4);
 putpixel(635,600-i,4);
 putpixel(634,600-i,4);
 putpixel(633,600-i,4);
 putpixel(4,i,4);
 putpixel(6,i,4);
 putpixel(5,i,4);
 putpixel(3,i,4);

  //sound(400+10*i);
 delay(1);
 nosound();
 }

  for(i=0;i<=636;i++)
 {
 putpixel(636-i,5,4);
 putpixel(636-i,3,4);
 putpixel(636-i,2,4);
 putpixel(636-i,4,4);
 putpixel(i,470,4);
 putpixel(i,472,4);
 putpixel(i,471,4);
 putpixel(i,473,4);
 //sound(400+10*i);
 delay(1);
 nosound();
 }
 delay(2000);
  /* set fill pattern  getmaxcolor() */
  setfillstyle(SOLID_FILL, 2);
  /* draw a filled ellipse */
  for(i=0;i<=70;i++)
  {
  fillellipse(500, 390, i, 40);
  //sound(1000-10*i);
  delay(10);
}
nosound();
setcolor(0);
settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
outtextxy(460,350,"By");
outtextxy(435,380,"Ravi Suhane");
delay(6000);
k o;
 o.d1(0);
getch();
}
