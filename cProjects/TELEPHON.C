/*                    PROJECT OF TELEPHONE DIRECTORY

      CREATED BY :
		  BHARAT    -  00IT22
		  BHAVIN    -  00IT25
		  GHANSHYAM -  00IT30                                     */


#include<process.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#define COMPANY "B H A R A T   T E L E C O M     D I R E C T O R Y"

  int k=0;
  struct customer
  {
	char name[20],surname[10],sname[20];
	long t_no;
  } c[20];
  void DateTime();

  void background();
  void insert();

   void end();

   void serch();
   void spe();
   void stdcode();
   void read();
   void sort();
   void delet();
  void main()
  {

      char ch,n[20];

      long no;

      int j,b,choice;

      int menu();



      FILE *f1;
      do
      {
	  //clrscr();
	  background();
	  //DateTime();
	// for(g=1;g<=15;g++)
	// {
	  textcolor(5);
	  gotoxy(30,5);
	  cprintf("*********");
	  gotoxy(30,6);
	  cprintf("MAIN MENU");
	  gotoxy(30,7);
	  cprintf("*********");
	  gotoxy(20,9);
	  cprintf("1.ADD RECORD");
	  gotoxy(20,10);
	  cprintf("2.TELEPHONE DIRECTORY");
	  gotoxy(20,11);
	  cprintf("3.SERCHING");
	  gotoxy(20,12);
	  cprintf("4.PUBLIC UTILITY SERVICES");
	  gotoxy(20,13);
	  cprintf("5.STD CODE");
	  gotoxy(20,14);
	  cprintf("6. DELETE RECORD");
	  gotoxy(20,15);
	  cprintf("7. DO YOU WANT TO EXIT");
	  gotoxy(20,17);
	 // delay(500);
	 // }
	  textcolor(GREEN);

	  cprintf("ENTER YOUR CHOICE:");
	  textcolor(8);
	  scanf("%d",&b);
	  switch(b)
	  {
		case 1:   background();
			  DateTime();

			insert();
			break;
		case 2:
			background();
			DateTime();

			read();
			break;
		case 3: background();
			DateTime();

			serch();
			break;
		case 4: background();
			DateTime();

			spe();
			break;
		case 5: background();
			DateTime();

			stdcode();
			break;
		case 6:
		       //	background();
			//DateTime();
			delet();
			break;

		case 7: background();
			DateTime();
			end();
			break;
	      }
      }

      while(b!=7);

      closegraph();
  }

  void end()
  {
  int g;
	 DateTime();

	background();
	for(g=1;g<=15;g++)
	{
       textcolor(g);
	gotoxy(20,20);
	cprintf("***************************************");
	gotoxy(20,21);
	cprintf("THANKS FOR VISITING TELEPHONE DIRECTORY");
	gotoxy(20,22);
	cprintf("***************************************");
	delay(200);
	}

	//exit(1);
  }

  void read()
  {
	int m;
	FILE *f2;

	f2=fopen("sort","r");
	 DateTime();

	 background();
	sort();
	gotoxy(20,7);
	textcolor(5);
	cprintf("CUSTOMER NAME");
	gotoxy(50,7);
	textcolor(5);
	cprintf("TELEPHONE NUMBER");
	for(m=0;m<k;m++)
	{
		fflush(stdin);
		fscanf(f2,"%s%s%s %ld",c[m].surname,c[m].name,c[m].sname,&c[m].t_no);
		fflush(stdin);
		gotoxy(16,m+10);
		textcolor(5);
		cprintf("%s ",c[m].surname);
		gotoxy(26,m+10);
		textcolor(5);
		cprintf("%s ",c[m].name);
		gotoxy(40,m+10);
		textcolor(5);
		cprintf("%s ",c[m].sname);
		gotoxy(55,m+10);
		textcolor(5);
		cprintf("%ld ",c[m].t_no);

	}
	fclose(f2);

	getch();
  }
void spe()
  {
	int m;
	FILE *f11;
	f11=fopen("special.txt","r");
	 DateTime();

	 background();

	gotoxy(15,7);
	textcolor(5);
	cprintf("SERVICE");
	gotoxy(50,7);
	textcolor(5);
	cprintf("TELEPHONE NUMBER");
	for(m=0;m<15;m++)
	{
		fflush(stdin);
		fscanf(f11,"%s%ld",c[m].name,&c[m].t_no);
		fflush(stdin);
		gotoxy(16,m+11);
		textcolor(5);
		cprintf("%s",c[m].name);
		gotoxy(55,m+11);
		textcolor(5);
		cprintf("%ld ",c[m].t_no);

	}
	fclose(f11);

	getch();
  }
void stdcode()
  {
	int m,b=0;
	FILE *f12;
	f12=fopen("stdcode","r");
	 DateTime();

	 background();

	gotoxy(18,7);
	textcolor(5);
	cprintf("CITY");
	gotoxy(53,7);
	textcolor(5);
	cprintf("STD CODE");
	for(m=0;m<15;m++)
	{
		fflush(stdin);
		fscanf(f12,"%s%s",c[m].name,c[m].sname);
		fflush(stdin);
		gotoxy(16,m+10);
		textcolor(5);
		cprintf("%s",c[m].name);
		gotoxy(55,m+10);
		textcolor(5);
		cprintf("%s",c[m].sname);
		b++;
	     /*	if(b==15)
		{
		getch();
		b=0;
		clrscr();
		}
		   */
	}
	fclose(f12);

	getch();
  }


  void insert()
  {
		int ch;
		FILE *f3;
		f3=fopen("custom.dat","w");
		clrscr();
		do
		{
		       DateTime();

		       background();

		       textcolor(11);
			gotoxy(3,7);
			cprintf("\nENTER CUSTOMER NAME:");
			fflush(stdin);
			scanf("%s %s %s",c[k].surname,c[k].name,c[k].sname);
			gotoxy(3,8);
			cprintf("\nTELEPHONE NUMBER:");
			fflush(stdin);
			scanf("%ld",&c[k].t_no);

			fflush(stdin);
			fprintf(f3,"%s %s %s %ld\n",c[k].surname,c[k].name,c[k].sname,c[k].t_no);
			gotoxy(3,9);
			cprintf("\nMORE CUSTOMER?[Y/N]:\n");
			ch=getche();

			 k=k+1;
		}
		while(ch=='y'||ch=='Y');

		fclose(f3);

  }

  void serch()
  {
	int j,choice,g,z=0;
	FILE *f4;
	char n[20];
	long no;
	f4=fopen("custom.dat","r");


	for(j=0;j<k;j++)
	{
		fscanf(f4,"%s %s %s %ld\n",c[j].surname,c[j].name,c[j].sname,&c[j].t_no);
	}
	do
	{
		choice=menu();
		switch(choice)
		{

		   case 1:
			fflush(stdin);
			textcolor(5);
			gotoxy(3,10);
			cprintf("ENTER CUSTOMER NAME:");
			fflush(stdin);
			scanf("%s",n);

			for(j=0;j<k;++j)
			{
				if(strcmpi(n,c[j].name)==0)
				{       for(g=1;g<=15;g++)
					{
					textcolor(g);
					gotoxy(3,12);
					cprintf("CUSTOMBER NAME");
					gotoxy(30,12);
					cprintf("TELEPHONE NUMBER:");
					gotoxy(3,14+z);
					cprintf("%s %s %s",c[j].surname,c[j].name,c[j].sname);
					gotoxy(40,14+z);
					cprintf("%ld",c[j].t_no);
					delay(200);
					}
					z++;
				}
			}

			break;
		   case 2:
			gotoxy(3,10);
			cprintf("ENTER CUSTOMER TELEPHONE NUMBER:");
			scanf("%ld",&no);
			for(j=0;j<k;++j)
			{
				if(no==c[j].t_no)
				{
				for(g=0;g<=15;g++)
				{    textcolor(g);
				      gotoxy(3,12);
				       cprintf("CUSTOMER NAME:%s %s %s",c[j].surname,c[j].name,c[j].sname);

				       delay(200);
				       }
				}
			}

			break;
		   case 3:
			delay(500);
			break;
		  //	  default:
		  // exit(1);
		}
	  // choice=menu();
	}
	while(choice!=3);
  }


     //end of if
  int menu()
  {
       int choice;
       clrscr();
       background();
	// DateTime();
	textcolor(GREEN);
       gotoxy(3,6);
       cprintf("1:NAME TO NUMBER");
       gotoxy(3,7);
       cprintf("2:NUMBER TO NAME");
       gotoxy(3,8);
       cprintf("3:EXIT");
       gotoxy(3,9);
       cprintf("ENTER YOUR CHOICE(1,2,3):");
       scanf("%d",&choice);
       return choice;
  }

  void DateTime()
  {
	struct date d;
	struct time t;

	getdate(&d);

	// gotoxy(2,3);
	// cprintf("www.patel.");

	gettime(&t);
	gotoxy(68,4);
	cprintf("Time : %02d:%02d", t.ti_hour,t.ti_min);

	// center("UPDATED TO ",3);
	gotoxy(2,4);

	cprintf("Date : %02d/%02d/%4d",d.da_day,d.da_mon,d.da_year);
	textcolor(8);
  }

  void background()
  {
	char str[20];
	int row,col;

	textbackground(8);
	textcolor(WHITE);

	clrscr();

	textcolor(8);

       //	for(row=1;row<=25;row++)
	 //	for(col=1;col<=80;col++)
	   //		cprintf("%c",177);

       gotoxy(16,2);
       textcolor(YELLOW+128);
       cprintf("%s",COMPANY);
	//textcolor(6);
	//box(1,1,24,79);

	DateTime();
  }
void sort()
{
int v,g;
long temp3;
char tempt[20],temp1[20],temp2[20];
FILE *f5,*f10;
	f5=fopen("custom.dat","r");
	for(v=0;v<k;v++)
	{
	 fscanf(f5,"%s%s%s %ld",c[v].surname,c[v].name,c[v].sname,&c[v].t_no);
	 }
	 for(v=0;v<k-1;v++)
	 {
	 for(g=0;g<k-1;g++)
	 {
	 if(strcmp(c[g].surname,c[g+1].surname)>=0)
		{
		if(strcmp(c[g].surname,c[g+1].surname)==0)
			{
			if(strcmp(c[g].name,c[g+1].name)==0)
				{
				if(strcmp(c[g].sname,c[g+1].sname)==0)
				     continue;

				else
					{

					strcpy(tempt,c[g].sname);
					strcpy(temp1,c[g].surname);
					strcpy(temp2,c[g].name);
					temp3=c[g].t_no;
					strcpy(c[g].sname,c[g+1].sname);
					strcpy(c[g].surname,c[g+1].surname);
					strcpy(c[g].name,c[g+1].name);
					c[g].t_no=c[g+1].t_no;
					strcpy(c[g+1].sname,tempt);
					strcpy(c[g+1].surname,temp1);
					strcpy(c[g+1].name,temp2);
					c[g+1].t_no=temp3;
					}
				}
			else
				{
				strcpy(tempt,c[g].sname);
				strcpy(temp1,c[g].surname);
				strcpy(temp2,c[g].name);
				temp3=c[g].t_no;
				strcpy(c[g].sname,c[g+1].sname);
				strcpy(c[g].surname,c[g+1].surname);
				strcpy(c[g].name,c[g+1].name);
				c[g].t_no=c[g+1].t_no;
				strcpy(c[g+1].sname,tempt);
				strcpy(c[g+1].surname,temp1);
				strcpy(c[g+1].name,temp2);
				c[g+1].t_no=temp3;

				}
				}
		else
			{
			strcpy(tempt,c[g].sname);
			strcpy(temp1,c[g].surname);
			strcpy(temp2,c[g].name);
			temp3=c[g].t_no;
			strcpy(c[g].sname,c[g+1].sname);
			strcpy(c[g].surname,c[g+1].surname);
			strcpy(c[g].name,c[g+1].name);
			c[g].t_no=c[g+1].t_no;
			strcpy(c[g+1].sname,tempt);
			strcpy(c[g+1].surname,temp1);
			strcpy(c[g+1].name,temp2);
			c[g+1].t_no=temp3;

			}


		}
	 }
	 }


	 f10=fopen("sort","w");
	 for(v=0;v<k;v++)
	{
	 fprintf(f10,"%s %s %s %ld\n",c[v].surname,c[v].name,c[v].sname,c[v].t_no);
	 }
	 fclose(f10);
	  fclose(f5);

}

void delet()
{
int j,v;
long no;
FILE *f20,*f21;
f20=fopen("custom.dat","r");
			textcolor(11);
			gotoxy(3,19);
			cprintf("ENTER CUSTOMER TELEPHONE NUMBER:");
			scanf("%ld",&no);
			for(j=0;j<k;++j)
			{  fscanf(f20,"%s%s%s %ld",c[j].surname,c[j].name,c[j].sname,&c[j].t_no);
				if(no==c[j].t_no)
				{
				      textcolor(11);
				      gotoxy(3,21);
				      cprintf("CUSTOMER NAME:%s %s %s ",c[j].surname,c[j].name,c[j].sname);
				     // gotoxy(13,21);
				     // cprintf("%ld",c[j].t_no);
				       getch();
				       strcpy(c[j].name,c[k-1].name);
				       strcpy(c[j].surname,c[k-1].surname);
				       strcpy(c[j].sname,c[k-1].sname);
				       c[j].t_no=c[k-1].t_no;
				       k=k-1;

				}
			}
			fclose(f20);
			f21=fopen("custom.dat","w");
			for(v=0;v<k;v++)
	{
	 fprintf(f21,"%s %s %s %ld\n",c[v].surname,c[v].name,c[v].sname,c[v].t_no);
	 }
	 fclose(f21);

    }











