#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

using namespace std;


const int   DIM = 3;
const int   num_of_thr = 4;
int         matrix_A[DIM][DIM];
int         matrix_B[DIM][DIM];
int         c[DIM][DIM];



//worker thread
void* matrix_multi(void*)
{    
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            c[i][j] = 0;
            for(int k = 0; k < DIM; k++)
            {
                c[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    pthread_exit(0);
}

int main()
{

    pthread_t thr_id[DIM][DIM];
  



   //Filling the Matrices
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            matrix_A[i][j]=  1;
            matrix_B[i][j] =  1;
        }
    }


    //create the threads
    for(int i = 0; i < num_of_thr/2; i++)
    {
        for(int j = 0; j < num_of_thr/2; j++)
        {
            pthread_create(&thr_id[i][j],NULL,matrix_multi, NULL);
        }
    }

    //joining the threads
    for(int i = 0; i < num_of_thr/2; i++)
    {
        for(int j = 0; j < num_of_thr/2; j++)
        {
        pthread_join(thr_id[i][j],NULL);
        }
    }
 	for(int i = 0; i < DIM; i++)
    	{
        for(int j = 0; j < DIM; j++)
        {
        	printf("%d\t",c[i][j]);
        }
	printf("\n");
    }
     return 0;
}

