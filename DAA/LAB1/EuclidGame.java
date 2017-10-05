class EuclidGame
{
	public static void main(String args[])
	{
		int m = Integer.parseInt(args[0]);
		int n = Integer.parseInt(args[1]);
		int temp;		
		int gcd = 0;
		if(m>n)
		{
			temp = m;
			m = n;
			n = temp;
		}
		gcd = euclid(n,m);

		int no_of_moves = n / gcd;

		if(no_of_moves%2 != 0)//odd no. of runs
			System.out.println("player 1 wins the game");
		else
			System.out.println("player 2 wins the game");
	}
	static int euclid(int m,int n)
	{
		int t;
		while(n!=0)
		{
			t = m % n;
			m = n;
			n = t;
		}
		return m;
	}
}