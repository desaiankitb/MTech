class LCS
{
	public static void main(String args[])
	{
		char x[] = {'x','A','B','C','B','D','A','B'};
		char y[] = {'x','B','D','C','A','B','A'};
		int m=x.length;
		int n=y.length;
		int c[][] = new int[m][n];
		for(int i=0; i<n; i++)
		{
			c[0][i] = 0;
		}
		for(int j=0; j<m; j++)
		{
			c[j][0] = 0;
		}
		for(int i=1;i<m;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(x[i] == y[j])
				{
					c[i][j] = c[i-1][j-1] + 1;
				}
				else
				{
					if(c[i-1][j] >= c[i][j-1])
						c[i][j] = c[i-1][j];	
					else
						c[i][j] = c[i][j-1];
				}
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				System.out.print(c[i][j]);
			}
			System.out.println();
		}
		System.out.println(c[m-1][n-1]);
	}
}
