#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
int cho,ar,br;
clrscr();
cho=0;
while(cho!=6)
{
	clrscr();
	printf("\n\n\t\tMain menu");
	printf("\n\t\t**********");
	printf("\n\n\t1.clock");
	printf("\n\n\t2.alaram");
	printf("\n\n\t3.Date To Day");
	printf("\n\n\t4.counter");
	printf("\n\n\t5.Event counter");
	printf("\n\n\t6.exit");
	scanf("%d",&cho);
	if(cho==1)
	{
	ar=25;
	clock(ar,br);
	}
	if(cho==2)
	{
	alaram(ar,br);
	}
	if(cho==3)
	{
	date_to_day();
	}
	if(cho==4)
	{
	counter();
	}
	if(cho==5)
	{
	eve_counter();
	}
}
}

//userdefine functions
clock(ar,br)
{
int a,b,hod,mid,i,digit[2],c,d,x,ho,po,mi;
#define OUT 0x378
struct date today;
struct time now;
clrscr();
getdate(&today);
gotoxy(10,10);
printf("today's date is :- %d/%d/%d\n ",today.da_mon,today.da_day,today.da_year);
a=8;
b=8;
c=8;
d=4;
while(!kbhit())
{
gettime(&now);
gotoxy(10,13);
printf("today's time is :- %02d:%02d:%02d:%02d\n ",now.ti_hour,now.ti_min,now.ti_sec,now.ti_hund);
ho=now.ti_hour;
mi=now.ti_min;
hod=ho;
mid=mi;
	for(i=0;i<2;i++)
	{
		digit[i]=hod%10;
		hod=hod/10;
	}
	outportb(OUT,digit[1]+16);
	delay(a);
	outportb(OUT,digit[0]+32);
	delay(b);
	for(i=0;i<2;i++)
	{
		digit[i]=mid%10;
		mid=mid/10;
	}
	outportb(OUT,digit[1]+64);
	delay(c);
	outportb(OUT,digit[0]+128);
	delay(d);
//	delay(2000);
if(ar==now.ti_hour && br==now.ti_min)
{
	for(i=200;i<1500;i+=100)
	{
		sound(i);
		delay(100);
		outportb(OUT,0);

	}
	nosound();
}
outportb(OUT,0);
}
}
//alram
alaram()
{
int hou,min,sec;
clrscr();
printf("Enter the time(ho,min)");
scanf("%d %d",&hou,&min);
clock(hou,min);
}

//counter
counter()
{
int ini,del,digit[4],i,no,update,temp;
printf("\n\n\tEnter the initial value");
scanf("%d",&ini);
printf("\n\n\tEnter delay(second)");
scanf("%d",&del);
update = ini;
while(!kbhit())
{
	clrscr();
	gotoxy(10,10);

	update = update++;
	printf("\n\n\tCOUNTER:%d",update);
	no = update;
	for(i=0;i<4;i++)
	{
//		temp = update
		digit[i]=no%10;
		no=no/10;
	}

		outportb(0x378,digit[3]+16);
		delay(del);
		outportb(0x378,digit[2]+32);
		delay(del);
		outportb(0x378,digit[1]+64);
		delay(del);
		outportb(0x378,digit[0]+128);
		delay(del);

		delay(del);

		ini++;
}
outportb(0x378,0);
}
//next
next(int ini)
{
	int no;
	no=ini;
	ini++;
	return ini;
}
//event counter
eve_counter()
{

}

//date to day
date_to_day()
{
int cc,dd,mm,yy;
int cc_no,yy_no=0,yy_arr[16]={0,4,10,21,27,32,38,49,55,60,66,77,83,88,94,94};
int temp_yy,i,mm_no,dd_no;
int DOW;
int cc_leap,yy_leap;
clrscr();
	printf("\n\n\tEnter the date:(dd/mm/cc/yy);");
	printf("\n\n\tEnter centuary:");
	scanf("%d",&cc);
	printf("\n\n\tEnter Year:");
	scanf("%d",&yy);
	printf("\n\n\tEnter month:");
	scanf("%d",&mm);
	printf("\n\n\tEnter day:");
	scanf("%d",&dd);

		if(cc==4 || cc==11 || cc==18 || cc==25)
			cc_no = 0;
		else
			if(cc<4)
				cc_no = 4 - cc;
			else if(cc<11)
				cc_no = 11 - cc;
			else if(cc<18)
				cc_no = 18 - cc;
			else if(cc<25)
				cc_no = 25 - cc;
	/*//find cc_no
	for(i=1;i<=99;i=i+4)
	{
		if(cc==i)
			cc_no=3;
	}
	for(i=2;i<=99;i=i+4)
	{
		if(cc==i)
			cc_no=5;
	}
	for(i=3;i<=99;i=i+4)
	{
		if(cc==i)
			cc_no=0;
	}
	for(i=4;i<=99;i=i+4)
	{
		if(cc==i)
			cc_no=1;
	} */

	//calculate yy_no
	for(i=0;;)
	{
		if(yy>=yy_arr[i])
			i++;
		else
		{
			temp_yy = yy_arr[i-1];
			yy_no = yy - temp_yy;
			yy_no = yy_no + leap_check(temp_yy,yy,yy_no,cc);
			break;
		}

	}


	//count mm_no
	if(mm==3 || mm==11)
		mm_no=1;
	else if(mm==6)
		mm_no=2;
	else if(mm==9 || mm==12)
		mm_no=3;
	else if(mm==4 || mm==7)
		mm_no=4;
	else if(mm==10)
		mm_no=5;
	else if(mm==5)
		mm_no=6;

	cc_leap=cc*100;
	yy_leap=yy+cc_leap;
	if( yy_leap%4==0 && (yy_leap%100!=0 || yy_leap%400==0) )
	{
		if(mm==1)
			mm_no = 4;
		else if(mm==2)
			mm_no = 0;
	}
	else
	{
		if(mm==1)
			mm_no = 5;
		else if(mm==2)
			mm_no = 1;
	}

	//calc dd_no
		dd_no = dd;

	//calculate result finally day of the week
	DOW=(cc_no+yy_no+dd_no+mm_no)%7;
	clrscr();
	printf("\n\n\tAt the date:%d/%d/%d/%d(dd/mm/cc/yy)",dd,mm,cc,yy);
	printf("\n\n\tThe day of the week:%d\n",DOW);
	switch(DOW)
	{
		case 0:
			printf("\n\tSunday=0");break;
		case 1:
			printf("\n\tMonday=1");break;
		case 2:
			printf("\n\tTueday=2");break;
		case 3:
			printf("\n\tWednesday=3");break;
		case 4:
			printf("\n\tThursday=4");break;
		case 5:
			printf("\n\tFriday=5");break;
		case 6:
			printf("\n\tSaturday=6");break;
	}
	do
	{
		outportb(0x378,DOW+128);
	}while(!getch());
	outportb(0x378,0);
       //printf("%d %d %d %d",cc_no,yy_no,mm_no,dd_no);
getch();
}
//check for the year value
leap_check(int temp_yy,int yy,int yy_no,int cc)
{
int i,count=0;
int temp2_yy=cc*100;
yy=temp2_yy+yy;
temp_yy=temp2_yy+temp_yy;
	for(i=temp_yy;i<=yy;i++)
	{
		if( !((i)%4) && ( ((i)%100) || !((i)%400) ) )
		{
			count++;
		}
		else
		{
			//count++;
		}
	}
	//printf("\nno of leap years%d\n",count);
return count;
}

