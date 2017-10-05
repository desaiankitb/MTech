class BinarySearch
{
	static int arr[] = {1,2,3,4,5,6};
	public static void main(String args[])
	{
		
		int index = binarySearch(Integer.parseInt(args[0]));
		System.out.println("index of"+Integer.parseInt(args[0])+"="+index);
		
	}
	static int binarySearch(int key)
	{
		int l=0;
		int n = arr.length;
		int r=n-1;
		int mid;
		while(l<=r)
		{
			mid = (l+r)/2;
			if(arr[mid] == key)
				return key;
			else if(arr[mid] < key)
				l = mid + 1;
			else
				r = mid -1;
		}
		return -1;
	}
}
