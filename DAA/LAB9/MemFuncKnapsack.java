class MemFuncKnapsack
{
	public static int weight = 0;
	public static int wArr[] = {0,2,1,3,2};
	public static int resultArr[] = {0,0,0,0,0};
	public static int proArr[] = {0,12,10,20,15};
	public static int vArr[][] = new int[5][6];//{-1,-1,-1,-1,-1};
	public static int totalWeight = 5;
	public static int totalProfit = 0;
		
	public static void main(String args[])
	{
		for(int k=0;k<5;k++)
		{
			for(int l=0;l<6;l++)
			{
				vArr[k][l] = -1;
			}
		}
		vArr[0][0] = 0;
		vArr[1][0] = 0;
		vArr[2][0] = 0;
		vArr[3][0] = 0;
		vArr[4][0] = 0;
		vArr[0][1] = 0;
		vArr[0][2] = 0;
		vArr[0][3] = 0;
		vArr[0][4] = 0;
		vArr[0][5] = 0;
		
		
		System.out.println(MF_Knapsack(4,5));
		for(int k=0;k<5;k++)
		{
			for(int l=0;l<6;l++)
			{
				System.out.print("\t"+vArr[k][l]+" ");
			}
			System.out.println();
		}
	}
	public static int max(int i,int j)
	{
		if(i>=j)
		{
			return i;
		}
		return j;
	}
	public static int MF_Knapsack(int i,int j)
	{
		if(vArr[i][j] < 0)
		{
			if(j < wArr[i])
			{
				MF_Knapsack(i-1,j);
			}
			else
			{
				System.out.println("i="+i+"j="+j);
				int val = max(MF_Knapsack(i-1,j),(proArr[i]+MF_Knapsack(i-1,j-wArr[i]) ));
				vArr[i][j] = val;
			}
		}
		
		return vArr[i][j];
	}
}
