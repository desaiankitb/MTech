class MatrixMul
{
	static int a[][] = {{1,2},{3,4}};
	static int b[][] = {{4,3},{2,1}};
	static int c[][] = {{0,0},{0,0}};
	public static void main(String args[])
	{
		mulMatrix();
		for(int j = 0; j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				System.out.println(c[j][k]);
			}
		}
		
	}
	static void mulMatrix()
	{
		for(int i=0;i<2;i++)
		{
			for(int j = 0; j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
				}
			}
		}
	}
}
