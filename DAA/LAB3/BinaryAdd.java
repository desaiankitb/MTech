class BinaryAdd
{
	static int A[] = {1,0,1,0};
	static int B[] = {1,1,1,1};
	public static void main(String args[])
	{
		int iCarry=0;
		int actCarry=0;
		int flag = 0;
		for(int i=A.length-1;i>=0;i--)
		{
			if(iCarry == 0 && flag == 1)
				A[i] = A[i] + actCarry;
			iCarry = A[i] + B[i];
			if(iCarry == 2)
			{
				flag = 1;
				iCarry = 0;
				actCarry = 1;
			}
			if(iCarry == 3)
			{
				flag = 1;
				iCarry = 1;
				actCarry = 1;
			}
			A[i] = iCarry;
		}
		for(int i=0;i<A.length; i++)
		{
			System.out.println(A[i]);
		}
		System.out.println(actCarry);
	}
}
