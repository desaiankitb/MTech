//***************************************************************************
//                           Crorepati Game
//***************************************************************************
//  coded by:A.Atheek Rahuman

//  e-mail me at:atheek_rahman@yahoo.com

//  !!  make sure to include the right path for graphics driver in initgraph()
//    b4 u run  !!

//*****************************************************************************

#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"mouse.h"

 struct quest
{
char q[50],c1[30],c2[30],c3[30],c4[30];
int r;
};






void set_question(quest *q)
{

 strcpy(q[0].q,"Which is the currency of Japan?");
strcpy(q[0].c1," Japanese Dollar");
strcpy(q[0].c2," Zen");
strcpy(q[0].c3, " Jen");
strcpy(q[0].c4," Yen");
q[0].r=4;
 strcpy(q[1].q,"Which is the tallest monument in India?");
strcpy(q[1].c1," Taj Mahal");
strcpy(q[1].c2," Qutab Minar");
strcpy(q[1].c3," Gol Gumbaaz");
strcpy(q[1].c4," Red Fort ");
q[1].r=1;
 strcpy(q[2].q," who is the author of ""Malgudi Days?"" ");
strcpy(q[2].c1," K.R.Narayan");
strcpy(q[2].c2," R.K.Narayan");
strcpy(q[2].c3," R.K.Laxman");
strcpy(q[2].c4," K.R.Laxman");
q[2].r=2;
 strcpy(q[3].q,"Who composed music for ""Bombay Dreams"" ?");
strcpy(q[3].c1," A.R.Rahman");
strcpy(q[3].c2," Anu Malik");
strcpy(q[3].c3,"R.D.Burman");
strcpy(q[3].c4,"S.D.Burman ");
q[3].r=1;
 strcpy(q[4].q,"How many 9's are there b'ween 1 & 100 ?");
strcpy(q[4].c1,"11");
strcpy(q[4].c2,"19");
strcpy(q[4].c3,"20");
strcpy(q[4].c4,"10");
q[4].r=3;
strcpy(q[5].q,"Which is the official language of Nagaland?");
strcpy(q[5].c1,"Naga");
strcpy(q[5].c2,"Bengali");
strcpy(q[5].c3,"Hindi");
strcpy(q[5].c4,"English");
q[5].r=4;
 strcpy(q[6].q,"Where is Nalanda University located?");
strcpy(q[6].c1,"Nepal");
strcpy(q[6].c2,"Sikkim");
strcpy(q[6].c3,"Bihar");
strcpy(q[6].c4,"Madhya Pradesh");
q[6].r=3;

 strcpy(q[7].q,"Which is the largest mammal?");
strcpy(q[7].c1,"Elephant");
strcpy(q[7].c2,"Hippo");
strcpy(q[7].c3,"Lion");
strcpy(q[7].c4,"Blue Whale");
q[7].r=4;
  strcpy(q[8].q,"Where is ""Sea of Tranquilty"" located ?");
strcpy(q[8].c1,"Earth");
strcpy(q[8].c2,"Moon");
strcpy(q[8].c3,"Mars");
strcpy(q[8].c4,"Sun");
q[8].r=2;

 strcpy(q[9].q,"Which company's logo has 42 dots?");
strcpy(q[9].c1,"Sony");
strcpy(q[9].c2,"Intel");
strcpy(q[9].c3,"LG");
strcpy(q[9].c4,"Microsoft");
q[9].r=1;
strcpy(q[10].q,"Who scored the first test century for India?");
strcpy(q[10].c1,"Mohinder Amarnath");
strcpy(q[10].c2,"Vijay Hazare");
strcpy(q[10].c3,"Lala Amarnath");
strcpy(q[10].c4,"Sachin Tendulkar");
q[10].r=3;

 strcpy(q[11].q,"Which of these animals ""laughs""?");
strcpy(q[11].c1,"Tiger");
strcpy(q[11].c2,"Rhino");
strcpy(q[11].c3,"Hyna");
strcpy(q[11].c4,"Myna");
q[11].r=3;
  strcpy(q[12].q,"Which is the symbol of Nazis?");
strcpy(q[12].c1,"Skull");
strcpy(q[12].c2,"Bone");
strcpy(q[12].c3,"Owl");
strcpy(q[12].c4,"Swastika");
q[12].r=4;
 strcpy(q[13].q,"Who is known as ""Flying Sikh""?");
strcpy(q[13].c1,"Milka Singh");
strcpy(q[13].c2,"Boota Singh");
strcpy(q[13].c3,"Navjyot Singh Sidhu");
strcpy(q[13].c4,"Pargat Singh ");
q[13].r=1;
 strcpy(q[14].q,"Which is the power voltage available at home?");
strcpy(q[14].c1,"22 K.V.");
strcpy(q[14].c2,"11 K.V.");
strcpy(q[14].c3,"230 V");
strcpy(q[14].c4,"10 V");
q[14].r=3;


}



void set_screen(char ** buff)
{

setcolor(LIGHTBLUE);
setfillstyle(SOLID_FILL,LIGHTBLUE);
circle(230,130,110);
floodfill(230,130,LIGHTBLUE);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
circle(230,130,105);
floodfill(230,130,BLUE);
setcolor(MAGENTA);
setfillstyle(SOLID_FILL,MAGENTA);
circle(230,130,80);
floodfill(230,130,MAGENTA);
setcolor(LIGHTBLUE);
setfillstyle(SOLID_FILL,LIGHTBLUE);
circle(230,130,75);
floodfill(230,130,LIGHTBLUE);
setcolor(LIGHTRED);
setfillstyle(SOLID_FILL,LIGHTRED);
circle(230,130,35);
floodfill(230,130,LIGHTRED);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(138,120,"C R O R E P A T I");
setcolor(RED);


setcolor(LIGHTBLUE);
rectangle(440,10,443,270);
setfillstyle(SOLID_FILL,LIGHTBLUE);
floodfill(441,11,LIGHTBLUE);

settextstyle(0,0,1);
setcolor(BROWN);
outtextxy(464,12,"RS.   1 CRORE");
outtextxy(464,30,"RS. 50,00,000");
outtextxy(464,48,"RS. 25,00,000");
outtextxy(464,66,"RS. 12,50,000 ");
outtextxy(464,84,"RS.  6,25,000");
outtextxy(464,102,"RS.  3,20,000");
outtextxy(464,120,"RS.  1,60,000 ");
outtextxy(464,138,"RS.    80,000");
outtextxy(464,156,"RS.    40,000");
outtextxy(464,174,"RS.    20,000");
outtextxy(464,192,"RS.    10,000");
outtextxy(464,210,"RS.     5,000");
outtextxy(464,228,"RS.     3,000");
outtextxy(464,246,"RS.     2,000");
outtextxy(464,264,"RS.     1,000");
   putimage(20,300,buff[0],COPY_PUT);
   putimage(20,360,buff[1],COPY_PUT);
   putimage(20,420,buff[1],COPY_PUT);
   putimage(326,360,buff[1],COPY_PUT);
   putimage(326,420,buff[1],COPY_PUT);
 }


 void capture_image(char * * buff)
{
 int area;



  setcolor(CYAN);
 setlinestyle(SOLID_LINE,USERBIT_LINE,1);
 int a[]={20,320,40,340,592,340,612,320,592,300,40,300,20,320};
 drawpoly(7,a);
 area=imagesize(20,300,612,340);
 buff[0]=new char[area];
 getimage(20,300,612,340,buff[0]);

 int b[]={20,380,40,400,286,400,306,380,286,360,40,360,20,380};
 drawpoly(7,b);
 area=imagesize(20,360,306,400);
 buff[1]=new char[area];
 getimage(20,360,306,400,buff[1]);
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 floodfill(45,380,CYAN);
  area=imagesize(20,360,306,400);
 buff[2]=new char[area];
 getimage(20,360,306,400,buff[2]);
  setfillstyle(SOLID_FILL,GREEN);
 floodfill(45,380,CYAN);
  area=imagesize(20,360,306,400);
 buff[3]=new char[area];
 getimage(20,360,306,400,buff[3]);

}







int found(int j,int *checked,int n)
{
 for(int i=0;i<n;i++)
 if(checked[i]==j)
 return(1);
 return(0);
 }

int select(int *checked,int n)
{
 int j;
 randomize();
 j=random(15);
while(found(j,checked,n))
j=random(15);
checked[n]=j;
  return(j);
}







void main()
{
int gd=DETECT,gm,x,y,b,j,ch,a=450,c=264,l=0;
char *buff[5];
quest q[15];

char *prize[]={"0","1000","2000","3000","5000","10000","20000","40000",
	      "80000","160000","320000","640000","1250000","2500000",
	      "5000000", "1 CRORE"};
 char str[2];
int checked[15],n=0;
int area;

initgraph(&gd,&gm,"c:\\tc\\bgi");


capture_image(buff);

if(!initmouse())
{
 exit(1);  //Mouse driver not installed
}
showmouse();

clearviewport();
set_question(q);
set_screen(buff);



str[0]=3;
str[1]=0;

for(int k=0;k<15;k++)
{
j=select(checked,n);
n++;
settextstyle(2,0,7);
setcolor(WHITE);
hidemouse();
outtextxy(40,310,q[j].q);
outtextxy(50,370,q[j].c1);
outtextxy(356,370,q[j].c2);
outtextxy(50,430,q[j].c3);
outtextxy(356,430,q[j].c4);
showmouse();

while(1)
{
getmouse(&b,&x,&y);
if(b==1)
{
 if(x>40 && y> 360&& x<286 && y<400)
 {
  ch=1;
  hidemouse();
  while(b==1)
  getmouse(&b,&x,&y);

  putimage(20,360,buff[2],COPY_PUT);
  delay(30);
  putimage(20,360,buff[1],COPY_PUT);
  outtextxy(50,370,q[j].c1);
  showmouse();
  break;
 }
 else if(x>326 && y> 360&& x<592 && y<400)
 {
  ch=2;
  hidemouse();
  while(b==1)
  getmouse(&b,&x,&y);
  putimage(326,360,buff[2],COPY_PUT);
  delay(30);
  putimage(326,360,buff[1],COPY_PUT);

   outtextxy(356,370,q[j].c2);
   showmouse();
  break;
 }


 else if(x>40 && y> 420&& x<286 && y<460)
 {

  ch=3;
  hidemouse();
  while(b==1)
  getmouse(&b,&x,&y);
  putimage(20,420,buff[2],COPY_PUT);
  delay(30);
  putimage(20,420,buff[1],COPY_PUT);
  outtextxy(50,430,q[j].c3);
  showmouse();
    break;
 }

 else if(x>326 && y> 420&& x<592 && y<460)
 {
  ch=4;
  hidemouse();
  while(b==1)
  getmouse(&b,&x,&y);
  putimage(326,420,buff[2],COPY_PUT);
  delay(30);
  putimage(326,420,buff[1],COPY_PUT);
  outtextxy(356,430,q[j].c4);
  showmouse();
  break;
 }

}
}



 delay(1000);
  if(q[j].r==1)
  {


  hidemouse();
  putimage(20,360,buff[3],COPY_PUT);
  outtextxy(50,370,q[j].c1);
  delay(600);
  putimage(20,360,buff[1],COPY_PUT);
  outtextxy(50,370,q[j].c1);
  showmouse();


  }
 else  if(q[j].r==2)
  {


   hidemouse();
  putimage(326,360,buff[3],COPY_PUT);
  outtextxy(356,370,q[j].c2);
  delay(600);
  putimage(326,360,buff[1],COPY_PUT);
  outtextxy(356,370,q[j].c2);

   showmouse();

  }
   else if(q[j].r==3)
  {

       hidemouse();

  putimage(20,420,buff[3],COPY_PUT);
  outtextxy(50,430,q[j].c3);
  delay(600);
  putimage(20,420,buff[1],COPY_PUT);
  outtextxy(50,430,q[j].c3);

    showmouse();

  }
   else if(q[j].r==4)
  {


   hidemouse();
  putimage(326,420,buff[3],COPY_PUT);
  outtextxy(356,430,q[j].c4);
  delay(600);
  putimage(326,420,buff[1],COPY_PUT);
  outtextxy(356,430,q[j].c4);
    showmouse();


  }

   if(ch==q[j].r)
   {

    l++;
    settextstyle(0,0,1);
    setcolor(RED);
    outtextxy(a,c,str);
    c-=18;

   }
    else
    break;



   hidemouse();
   putimage(20,300,buff[0],COPY_PUT);
   putimage(20,360,buff[1],COPY_PUT);
   putimage(20,420,buff[1],COPY_PUT);
   putimage(326,360,buff[1],COPY_PUT);
   putimage(326,420,buff[1],COPY_PUT);
   showmouse();




}
hidemouse();
cleardevice();
 setcolor(LIGHTRED);
 int z[]={20,220,60,260,572,260,612,220,572,180,60,180,20,220};
 drawpoly(7,z);
 setcolor(LIGHTGREEN);
 setfillstyle(SOLID_FILL,BLUE);
 floodfill(80,220,LIGHTRED);
 settextstyle(0,0,1);
 settextjustify(0,1);
 outtextxy(55,220,"T O T A L  P R I Z E  M O N E Y : Rs ");
 outtextxy(480,220,prize[l]);
 getch();
closegraph();
restorecrtmode();
}

