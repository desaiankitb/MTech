class Margesort
{
	static int A[]={5,2,4,7,1,3,2,6,8};
	static int T[]={5,2,4,7,1,3,2,6,8};
	static int B[]={0,0,0,0};
	static int C[]={0,0,0,0};
	static int k=1,i=1,j=1;
	
	static void Marge(int A[],int p,int q,int r)
	{
		int i=p,j=q;
		for(i=p;i<r;i++)
		{
			if(A[i] <= A[j])
			{
				A[j] = A[i]*A[j];
				A[i] = A[j]/A[i];
				A[j] = A[j]/A[i];
			}
			else
			{
				A[j] = A[i]*A[j];
				A[i] = A[j]/A[i];
				A[j] = A[j]/A[i];
			}				
		}
	}
	static void margeSort(int A[],int p,int r)
	{
		int q;
		if(p<r)
		{
			q = ((p+r)/2);
			margeSort(A,p,q);
			margeSort(A,q+1,r);
			Marge(A,p,q,r);
		}
	}
	public static void main(String args[])
	{
		margeSort(A,0,A.length);
		for(int i=0;i<A.length;i++)
		{
			System.out.println(A[i]);
		}
	}
}







/*while(i < M && j < N)
			{
				if(i > M)
				{
					while(j <= N)
					{
						C[k] = B[j];
						j++;
						k++;
					}
				}
				if(j < N)
				{
					while(j <= M)
					{
						C[k] = A[i];
						j++;
						k++;
					}
				}
			}*/
