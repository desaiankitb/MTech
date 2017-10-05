class Inversion
{
	static int A[] = {2,3,8,6,1};
	public static void main(String args[])
	{
		for(int i=0;i<A.length;i++)
		{
			for(int j=0;j<A.length;j++)
			{
				if(i<j && A[i] > A[j])
				{
					System.out.println("("+(i+1)+","+(j+1)+")");
				}
			}
		}
	}
}
