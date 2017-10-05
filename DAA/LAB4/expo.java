class expo
{
	static int number=0;
	static int power=0;
	static int exponetial(int inum,int ipower)
	{
		if(ipower == 1 )
		{
			return 1;
		}
		else if(ipower%2 == 0)
		{
			return ((exponetial(inum,ipower/2))*(exponetial(inum,ipower/2)));
		}
		else
		{
			return ((exponetial(inum,ipower/2)*inum)*(exponetial(inum,ipower/2)*inum));
		}
	}
	public static void main(String args[])
	{
		number = Integer.parseInt(args[0]);
		power =  Integer.parseInt(args[1]);
		int ans = exponetial(number,power);
		System.out.print("ans = "+ans);
	}
}
