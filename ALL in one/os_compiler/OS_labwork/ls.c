#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
char str[100][50],accessper[100][10],pwd1[100][25],gid1[100][25];
void sortstr();
int inode[100],link1[100];
//longint size[100];
char str1[20];
int strc=0;
void printi();
void printls();
void printl();
int main(int argc, char *argv[])
{
        DIR *dp;
        struct dirent *d;
	struct stat sb;
	struct tm *t;
        struct passwd *pwd2;
        struct group *gid2;
	int j=0,i;
	char ch,time[100];

	if((dp = opendir(".")) == NULL)    
                perror("opendir");
        else           
           {

                while((d = readdir(dp)) != NULL)
                {
                        if(!strcmp(d->d_name,".") || !strcmp(d->d_name,".."))
                                continue;
                        strcpy(str[strc],d->d_name);
                        inode[strc]=d->d_ino;
                        strc++;
		}
	    }
	sortstr();	
        for(i=0;i<=strc;i++)
	{       
	//	printf("%d",i);        
		stat(str[i], &sb);
                        if((sb.st_mode & S_IFDIR)==S_IFDIR) 
				accessper[i][0]='d';                       
                        else 
				accessper[i][0]='-';
			if((sb.st_mode & S_IRUSR)==S_IRUSR)
				accessper[i][1]='r';
			 else 
				accessper[i][1]='-';

            		if((sb.st_mode & S_IWUSR)==S_IWUSR) 
				accessper[i][2]='w';
			 else
				accessper[i][2]='-';

	                if((sb.st_mode & S_IXUSR)==S_IXUSR) 
				accessper[i][3]='x';
			else
				accessper[i][3]='-';
	
        		 if((sb.st_mode & S_IRGRP)==S_IRGRP)
				accessper[i][4]='r';
			 else 
				accessper[i][4]='-';
	                if((sb.st_mode & S_IWGRP)==S_IWGRP)
				accessper[i][5]='w';
	 		else
 				accessper[i][5]='-';
	                if((sb.st_mode & S_IXGRP)==S_IXGRP)
				accessper[i][6]='x';
			 else 
				accessper[i][6]='-';
	                if((sb.st_mode & S_IROTH)==S_IROTH)
				accessper[i][7]='r';
			 else 
				accessper[i][7]='-';
	                if((sb.st_mode & S_IWOTH)==S_IWOTH)
				accessper[i][8]='w';
			else 
				accessper[i][8]='-';
	                if((sb.st_mode & S_IXOTH)==S_IXOTH)
				accessper[i][9]='x'; 
			else 
				accessper[i][9]='-';
			link1[i]=sb.st_nlink;
			 printf("%lld\n",sb.st_size);

			 pwd2=getpwuid(sb.st_uid);     
			if (pwd2 == NULL) {
				printf("\nerror 1\n");
				exit(1);
			}
		//	printf(" %d ", (int)sb.st_gid);
                     gid2=getgrgid(500);   
			
		/*	if (gid2 == NULL) {
				printf("\nerror 2\n");
				exit(2);
			}*/
			strncpy(pwd1[i],pwd2->pw_name,25);
			strncpy(gid1[i],gid2->gr_name,25);
			//printf("%5s %5s",pwd2->pw_name,gid2->gr_name);

		//	printf("%s %s\n",pwd2->pw_name,gid2->gr_name);

		//	printf("%s\nii ",pwd2->pw_name);
		//	printf("%lld\n",sb.st_size);
			 t=gmtime(&sb.st_mtime);
			   printf("%d",t->tm_year);	
		strcpy(time,(char *)ctime(&sb.st_mtime));
  	                 time[strlen(time)-1]='\0';
			printf("%s year=%s\n",time,t->tm_mon);
                                      
           }
  	if(argc==2)	
	{
		if(!strcmp(argv[1],"ls"))	
			printls();
	}
	else if(argc>=2)
	{
		//printf("%s",argv[1]);
		while(argv[2][j]!='-')
		{
			j++;
		}
		ch=argv[2][j+1];
//		printf("i=%d",j);
 //		printf("%c\n",ch);
	}
        
	switch(ch)
	{
		case 'i':printi();
			 break;
		case 'l':printl();
			 break;
		 default:printf("command not found");
			break;		
}
return 0;
}
void printi()
{
	int i;
	for(i=0;i<=strc;i++)
	{
		printf("%d\t",inode[i]);
		printf("%s\n",str[i]);
	}
}
void sortstr()
{
	int i,j;
        char temp[25];
	int temp1;
	for(i=0;i<=strc;i++)
		for(j=0;j<strc;j++)
                {
                        if(strcasecmp(str[j],str[j+1])>0)
                        {
                              strcpy(temp,str[j]);  
			      strcpy(str[j],str[j+1]);
			      strcpy(str[j+1],temp);
			
			      temp1=inode[j];
                              inode[j]=inode[j+1];
                              inode[j+1]=temp1;

                        }
                }

        return;
}
void printls()
{
        int i;
        for(i=0;i<=strc;i++)
        {
                printf("%s\n",str[i]);
        }

}
void printl()
{
	int i;
	int j;
        for(i=0;i<=strc;i++)
        {
		for(j=0;j<=9;j++)
		{
			printf("%c",accessper[i][j]);
		}
		printf("  %s",pwd1[i]);
		printf("  %s",gid1[i]);
//		printf("  %s",size[i]);
		printf("  %d",link1[i]);
                printf("  %s\n",str[i]);
        }

}
