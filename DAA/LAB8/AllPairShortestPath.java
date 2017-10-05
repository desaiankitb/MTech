class AllPairShortestPath
{
	static int D0[][] = { {0,5,999,999},
			    {50,0,15,5},
		   	    {30,999,0,15}, 
		   	    {15,999,5,0} };
	static int p[][] = new int[4][4];
	public static void main(String args[])
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				p[i][j] = 0;
			}
		}
		for(int k=0;k<4;k++)
		{
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					if(D0[i][j] > (D0[i][k] + D0[k][j]) )
					{
						D0[i][j] = D0[i][k] + D0[k][j];
						p[i][j] = k+1;
					}
				}
			}
		}
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				System.out.print(" "+D0[i][j]);
			}
			System.out.println();
		}
		System.out.println();
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				System.out.print(" "+p[i][j]);
			}
			System.out.println();
		}
	}
}
