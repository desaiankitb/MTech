class Fibonacii
{
	public static void main(String args[])
	{
		//int i = Integer.parseInt(args[0]);
		int ans=1;
		int f[] = {0,1,0,0,0,0,0,0,0,0,0};
		for(int i=2;i<=Integer.parseInt(args[0])+1;i++)
		{
			f[i] = f[i-1] + f[i-2];
		}
		System.out.println( f[Integer.parseInt(args[0])+1] );
	}
}
