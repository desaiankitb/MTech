class MaxEle
{
	static int arr[] = {1,2,3,4,5,6};
	public static void main(String args[])
	{
		maxEle();
	}
	static void maxEle()
	{
		int max=arr[0];
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i] > max)
			{
				max = arr[i];
			}			
		}
		System.out.println("Max = "+max);
	}
}
