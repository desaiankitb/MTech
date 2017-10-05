#include <dirent.h>
#include <sys/dir.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
typedef int FLAG;

FLAG inode_flag=0,l=0,r=0,sort_size=0;
char names[50][20];
int inode[50];
int count;

void directory(char *dir)
{
	DIR *dir1;
	struct dirent *namelist;
	char temp[20];
	count =0;
	
	dir1=opendir(dir);
									
	if(dir1==NULL)
	{					
		printf("File can not be opened\n");
		exit(1);
	}								

	do
	{
		namelist=readdir(dir1);
	
		if(namelist==NULL)
			break;
	
		strcpy(temp,namelist->d_name);
		if(temp[0]=='.')
			continue;	
		
		if(inode_flag)
			inode[count]=namelist->d_ino;
	
		 strcpy(names[count],namelist->d_name);
		 count++;	
		
	}while(1);
	
	return;
	}
	
void swap(int i,int j)
{
	char temp[20];
	int tempi;
	
	strcpy(temp,names[i]);
	strcpy(names[i],names[j]);
	strcpy(names[j],temp);
	
	tempi=inode[i];
	inode[i]=inode[j];
	inode[j]=tempi;
	
	return;
}
		
void sort()
	{
	int k,j;
	int c;
	
	
	for(k=0;k<count;k++)
		for(j=0;j<(count-k-1);j++)
		{
			if(strcasecmp(names[j],names[j+1])>0)
			{
				swap(j,j+1);
			}
		}
				
	return;
	}
				
void sort_by_size()
        {
        int k,j;
        int c;


        for(k=0;k<count;k++)
                for(j=0;j<(count-k-1);j++)
                {
                        if(strcasecmp(names[j],names[j+1])>0)
                        {
                                swap(j,j+1);
                        }
                }

        return;
        }
	

int main(int argc,char **argv)
{
	int arg,c,i;
	char dir[10];
	char progname[10];
	dir[0]='.';
	dir[1]='\0';
	
	if(argc>1)		
		for(arg=1;arg<argc;arg++)
			{
			if(argv[arg][0]=='/')
				strcpy(dir,argv[arg]);
			
			else if(argv[arg][0]=='-')
			for(i=1;i<strlen(argv[arg]);i++)
				switch(argv[arg][i])
					{
					case 'i':
						inode_flag=1;
						break;
					case 'l':
						l=1;
						break;
					case 'r':
						r=1;
						break;
					case 'S':
						sort_size=1;
						break;
					}
			}
	directory(dir);
	sort();
	
	if(r)
	{
		for(c=count-1;c>=0;c--)
		{
			if(inode_flag)
				printf("%ld  ",inode[c]);
			printf("%s  ",names[c]);
		}
	}	
	else if(inode_flag)
	{
		for(c=0;c<count;c++)
		{
			printf("%ld ",inode[c]);
			printf("%s \n",names[c]);
		}
        }
	else if(l)
	{
		opt_l();
	}
	else if(sort_size)
	{
		opt_S();
	}
	printf("\n");
	return 0;
}
opt_S()
{
	int i;
	
}

opt_l()
{
	int i;
	char ch;
	char mode[10],time[27];
	struct stat sb;
	struct tm *t;
        struct passwd *pwd;
        struct group *grp;

	for(i=0;i<count;i++)
                {
                           stat(names[i],&sb);
			   t=gmtime(&sb.st_mtime);
			   printf("%d",t->tm_year);
			   strcpy(time,(char *)ctime(&sb.st_mtime));
  	                   time[strlen(time)-1]='\0';
                           if(S_ISDIR(sb.st_mode))
                                ch='d';
                           else
                                ch='-';
                           if(sb.st_mode & S_IRUSR)
                                mode[0]='r';
                           else
                                mode[0]='-';
                           if(sb.st_mode & S_IWUSR)
                                mode[1]='w';
                           else
                                mode[1]='-';
                           if(sb.st_mode & S_IXUSR)
                                mode[2]='x';
                           else
                                mode[2]='-';
                           if(sb.st_mode & S_IRGRP)
                                mode[3]='r';
                           else
				   mode[3]='-';
                           if(sb.st_mode & S_IWGRP)
                                mode[4]='w';
                           else
                                mode[4]='-';
                           if(sb.st_mode & S_IXGRP)
                                mode[5]='x';
                           else
                                mode[5]='-';
                           if(sb.st_mode & S_IROTH)
                                mode[6]='r';
                           else
                                mode[6]='-';
                           if(sb.st_mode & S_IWOTH)
                                mode[7]='w';
                           else
                                mode[7]='-';
                           if(sb.st_mode & S_IXOTH)
                                mode[8]='x';
                           else
                                mode[8]='-';
                           mode[9]='\0';

                           pwd=getpwuid(sb.st_uid);     //get user name
                           grp=getgrgid(sb.st_gid);     //get group name
                           printf("%c%-11s %2ld %5s %5s %6lld %15s %-32s \n",ch,mode,(long) sb.st_nlink,pwd->pw_name,grp->gr_name,(long long) sb.st_size,time,names[i]);
                }
}

