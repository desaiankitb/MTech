class Sos{
	public static int w[] = {7,11,13,24};
	public static int x[] = {0,0,0,0};
	public static int m = 31;
	public static void main(String args[])
	{
		sos(0,0,55);
	}
	public static void sos(int s,int k,int r)
	{
		x[k] = 1;
		if(s+w[k] == m)
		{
			for(int i=0;i<x.length;i++)
			{
				System.out.println(x[i]);
			}
		}
		else if(s+w[k]+w[k+1] <= m)
		{
			sos(s+w[k],k+1,r-w[k]);
		}
		if(s+r-w[k] >= m && s+w[k+1] <= m)
		{
			x[k] = 0;
			sos(s,k+1,r-w[k]);
		}
	}
}
