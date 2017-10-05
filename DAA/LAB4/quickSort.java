class quickSort
{
	public static int partition(int A[], int p, int q)
	{
		int x = A[p];
		int i = p;
		for (j = p + 1; j < q; j++)
		{
			if (A[i] <= x)
			{
				i = i + 1;
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		int temp = A[p];
		A[p] = A[i];
		A[
	}
	public static void main(String args[])
	{
			
	}
}