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

FLAG inode_flag=0,l=0,r=0,sort_size=0,hidd_file=0,m_t=0,bs=0,R=0,d=0;
char names[50][20];
int inode[50],size[50];
time_t time_mt[50];
int count;
void display_l(int);

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
		if(hidd_file==0)
		{
			if(temp[0]=='.')
				continue;	
		}

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
	time_t tmp;
	strcpy(temp,names[i]);
	strcpy(names[i],names[j]);
	strcpy(names[j],temp);
	
	tempi=inode[i];
	inode[i]=inode[j];
	inode[j]=tempi;
	
	if(sort_size==1)
	{
		tempi=size[i];
		size[i]=size[j];
		size[j]=tempi;
	}
	if(m_t==1)
	{
		tmp=time_mt[i];
		time_mt[i]=time_mt[j];
		time_mt[j]=tmp;
	}
	return;
}
		
void sort()
	{
	int k,j;
	int c;
	char *p1,*p2;
	
	for(k=0;k<count;k++)
		for(j=0;j<(count-k-1);j++)
		{
			if(names[j][0]=='.')
				p1=names[j]+1;
			else
				p1=names[j];
			
			if(names[j+1][0]=='.')
				p2=names[j+1]+1;
			else
				p2=names[j+1];

			if(strcasecmp(p1,p2)>0)
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
	struct stat sb;
	for(k=0;k<count;k++)
	{
		stat(names[k],&sb);
		size[k]=sb.st_size;
	}

        for(k=0;k<count;k++)
                for(j=0;j<(count-k-1);j++)
                {
                        if(size[j]>size[j+1])
                        {
                                swap(j,j+1);
                        }
                }
        return;
}
	
void sort_by_mtime()
{
	int i,j,k;
	struct stat sb,sb1;
	for(i=0;i<count;i++)
	{	
        	stat(names[i],&sb);
	        time_mt[i]=sb.st_mtime;
	}
	for(k=0;k<count;k++)
	{
		for(j=0;j<(count-k-1);j++)
		{
			stat(names[j],&sb);
			stat(names[j+1],&sb1);
			if(difftime(sb.st_mtime,sb1.st_mtime)>0)
				swap(j,j+1);

		}
	}
	
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
						case 'a':
							hidd_file=1;
							break;
						case 't':
							m_t=1;
							break;
						case 's':
							bs=1;
							break;
						case 'R':
							R=1;
							break;
						case 'd':
							d=1;
							break;
			
	//					default:
	//						ls(dir);
					}
			}
	if(R==1)
	{
		printf("\n.\n..");
		opt_R(".");
		exit(0);
	}
	directory(dir);
    	if(sort_size==1)
		sort_by_size();
	else if(m_t==1)
		sort_by_mtime();
	else
		sort();
	
	if(l)
	{
		opt_l();
	}
	else if(r)
	{
		for(c=count-1;c>=0;c--)
		{
			if(inode_flag)
				printf("\n%7ld  ",inode[c]);
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
	else if(sort_size)
	{
		opt_S();
	}
	else if(hidd_file==1)
	{
		opt_a();
	}
	else if(m_t==1)
	{
		
		opt_t();
	}
	else if(bs==1)
	{
		opt_bs();
	}
	else if(d==1)
	{
		opt_d();
	}
	else
		ls();
	printf("\n");
	return 0;
}
opt_d()
{
	int i;
	struct stat s;
	for(i=0;i<count;i++)
	{
		stat(names[i],&s);
		if(S_ISDIR(s.st_mode))
        	        {
				printf("%s  ", names[i]);
	                }
	}
}
ls()
{
	int i;	
	for(i=0;i<count;i++)
		printf("%s  ",names[i]);
	
}

opt_R(char dir_name[20])
{
	DIR *dir;
	struct stat s;
        struct dirent *dirname;
	char dirs[50][30];
        char temp[20];
	int i,dir_count=0,nxt_dir=0;
	count=0;
        char path[80]; 
        char spath[80]; 
	char npath[80];
//	printf("\n\n%s\n",dir_name);
	strcpy(path,dir_name);
        dir=opendir(dir_name);

        if(dir==NULL)
        {
                printf("File can not be opened\n");
                exit(1);
        }

        do
        {
                dirname=readdir(dir);

                if(dirname==NULL)
                        break;

                strcpy(temp,dirname->d_name);
                if(hidd_file==0)
                {
                        if(temp[0]=='.')
                                continue;
                }
                strcpy(names[count],dirname->d_name);
		count++;
	}while(1);
	sort();
	printf("\n");
	for(i=0;i<count;i++)
	{
		strcpy(npath,"");
		strcat(npath,path);
		strcat(npath,"/");
		strcat(npath,names[i]);
		stat(npath,&s);
                if(S_ISDIR(s.st_mode))
                {
			strcpy(dirs[dir_count],names[i]);
                        dir_count++;
                }
		printf("%s  ",names[i]);
	}
	printf("\n\n");
   
	for(i=0;i<dir_count;i++)
 	{
		strcpy(spath,"");
		strcat(spath,path);
		strcat(spath,"/");
		strcat(spath,dirs[i]);
		printf("\n%s:",spath);
		opt_R(spath);
	}
}
opt_a()
{
	int i;
	for(i=0;i<count;i++)
	{
		printf("%s  ",names[i]);
	}
}
opt_S()
{
	int i;
	
	for(i=count-1;i>=0;i--)
	{
		printf("%s  ",names[i]);
	}
	
}
opt_bs()
{
	int i;
	struct stat sb;
	for(i=0;i<count;i++)
	{
		stat(names[i],&sb);
		printf("%-4d%s\n",sb.st_blocks/2,names[i]);
	}	
}
opt_t()
{
	int i;
	for(i=count;i>=0;i--)
		printf("%s  ",names[i]);
}

opt_l()
{
	int i;	
	if(r!=1 && sort_size==1)
	{
		for(i=count-1;i>=0;i--)
			display_l(i);
	}
	else if(r==1 && sort_size==1)
	{
		for(i=0;i<count;i++)
			display_l(i);
	}
	else if(bs==1 && r==1)
        {
                struct stat sb;
                for(i=count-1;i>=0;i--)
                {
                        stat(names[i],&sb);
                        printf("%-3d",sb.st_blocks/2);
                        display_l(i);
                }

        }
	else if(r==1)
	{
		for(i=count-1;i>=0;i--)
			display_l(i);
	}
	else if(m_t==1)
	{
		for(i=count-1;i>=0;i--)
			display_l(i);
	}
	else if(inode_flag==1)
	{
		for(i=0;i<count;i++)
		{
			printf("%ld ",inode[i]);
			display_l(i);
		}
	}
	else if(bs==1)
	{
		struct stat sb;
	        for(i=0;i<count;i++)
        	{
                	stat(names[i],&sb);
	                printf("%-3d",sb.st_blocks/2);
			display_l(i);
        	}
	}
	else
	{
		for(i=0;i<count;i++)
			display_l(i);
	}

}

void display_l(int i)
{
	char ch;
        char mode[10],time[27];
        struct stat sb;
        struct tm *t;
        struct passwd *pwd;
        struct group *grp;

        stat(names[i],&sb);
        t=gmtime(&sb.st_mtime);
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
        printf("%c%-s %ld %5s %5s %5lld %d-%2d-%2d %2d:%2d %-32s \n",ch,mode,(long) sb.st_nlink,pwd->pw_name,grp->gr_name,(long long) sb.st_size,1900+t->tm_year,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,names[i]);

}
