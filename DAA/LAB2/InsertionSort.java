class InsertionSort
{
	public static int arr[]={1,5,4,3,2,6};
	public static void main(String args[])
	{
		InsrSort();
		for(int i=0;i<arr.length;i++)
		{
			System.out.println("arr["+i+"]="+arr[i]);
		}
	}
	static void InsrSort()
	{
		int key = arr[0];
		int i,p;
		for(p=1;p<arr.length;p++)
		{
			i = p;
			key = arr[i];
			while(key < arr[i-1] && i > 1)
			{
				arr[i] = arr[i-1];
				i=i-1;
			}
			arr[i] = key;
		}
	}
}
