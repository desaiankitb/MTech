#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

int process_fork(int nproc)
{
    int j;
    for(j=1;j<nproc;j++)
       {
            if(fork()==0)
                 return(j);
       }
    return(0);
}

void process_join(int nproc, int id)
  {
      int i;
      if(id==0)
        {
           for(i=1;i<nproc;i++)
                 wait(0);
        }
      else
         exit(0); 
   }

char *shared(int size,int *shmid)
  {
      
      *shmid=shmget(IPC_PRIVATE,size,0666|IPC_CREAT);
      printf("\nshmid=%d\n",*shmid);
      return(shmat(*shmid,0,0));
  }

void spin_lock_init(int *lock,int *condition)
  {
     int control;
    
     *lock= semget(IPC_PRIVATE,1,0666|IPC_CREAT);
     if(*condition==1)
         control=0;
     else
       control=1; 
    
     semctl(*lock,0,SETVAL,control);
  }


void spin_lock(int *lock)
   {
      struct sembuf operations;
      operations.sem_num=0;
      operations.sem_op=-1;
      operations.sem_flg=0;
      semop(*lock,&operations,1);
   }

void spin_unlock(int *lock)
    {
    	
      struct sembuf operations;
      operations.sem_num=0;
      operations.sem_op=1;
      operations.sem_flg=0;
      semop(*lock,&operations,1);
} 

void barrier_init(int *bar1,int bnum)
   {
       int c=0;
       	*(bar1+0)=bnum;
	*(bar1+1)=0;
	*(bar1+2)=0;
	spin_lock_init((bar1+3),&c);
    }	

void barrier(int *bar)
  {
     int incr=0;
 
     while(1)
      { 
	     spin_lock((bar+3));
             if(incr==0 && *(bar+2)>0)
	          {
		    spin_unlock((bar+3));
                    continue;
		  }  
            //////////////////////////trapping phase
	     if(incr==0)
        	{
		  *(bar+1)=*(bar+1)+1;
		  incr=1;
		}

     	    if(*(bar+1) < *(bar+0) && (*(bar+2) ==0))
		{
        	   spin_unlock((bar+3));		
        	   continue;
	         }
           else
                {
		 //////////////////////release phase
	 	   if(*(bar+2)==0)  //release first process
		    {
                	*(bar+2)=*(bar+0)-1;
			*(bar+1)=0;
			spin_unlock((bar+3));
			return;
		     }
	           else  //release rest of processes
        	     {
			*(bar+2)= *(bar+2)-1;
			spin_unlock((bar+3));
			return;
		      }
        	 }

	     spin_unlock((bar+3));
	     printf("\nError in barrier");
	     return;
	  }
  } 	
	


