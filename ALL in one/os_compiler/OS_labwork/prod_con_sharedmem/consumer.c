#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/ipc.h>
int main()
{
        int seg_id,key=77;
        char *shm;
        const int size= 4096;
        seg_id=shmget(key,size,S_IRUSR);
        shm=(char*)shmat(seg_id,NULL,0);
	
	printf("%d",seg_id);
        printf("%s",shm);
	sprintf(shm,"completed");
	shmdt(shm);
	//shmctl(seg_id,IPC_RMID,NULL);

	return 0;
       

}

                             
