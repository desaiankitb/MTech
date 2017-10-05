class CrossBridge
{
	static int findminindex(int timming[])
	{
		int minindex = timming[0];
		for(int i=1;i<timming.length-1;i++)
		{
			if(timming[i] < timming[minindex])
			{
				minindex = i; 
			}
		}
		System.out.println("min index:"+minindex);
		return minindex;
	}

	public static void main(String args[])
	{
		int count=5;
		int timming[]={2,1,5,10,12};
		int maxtime=0;
		int i=3;
		int minindex = findminindex(timming);
		while(count!=(timming.length-2))
		{
			if(i-1 == minindex)
			{
				i--;
				continue;
			}
			maxtime = maxtime + timming[i-1] + timming[minindex];
			count--;
			System.out.println(i-1+":is on the other bank");
			i--;
		}
		maxtime = maxtime + timming[timming.length-1];
		System.out.println((timming.length-1)+":is on the other bank");
		System.out.println("time taken is:"+(maxtime-1));
	}
}
