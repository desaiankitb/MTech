class MCM
{
	static int P[] = {3,3,3,3,3,3};
	static int s[][] = new int[P.length][P.length];
	public static void main(String args[])
	{
		int n = P.length-1;//6-1=5
		int j = 0;
		int m[][] = new int[P.length][P.length];
		int i=0,k=0,l=0,t=0,ans=0;
		for(i=0;i<n;i++)
		{
			m[i][i] = 0;
		}

		for(l=1;l<=n-1;l++)
		{
			//System.out.println("l="+l+"  ");
			for(i=0;i<=(n-(l+2)+1);i++)
			{
				//System.out.print("i="+i+"   ");
				j=(l+1)+i-1; m[i][j] = 999999;
				//System.out.print("j="+j+"   ");
				for(k=i;k<=j-1;k++)
				{
					t = m[i][k] + m[k+1][j] + (P[i]*P[k+1]*P[j+1]);
					//System.out.print((P[i]*P[k+1]*P[j+1]));
				
					//System.out.print("m["+i+"]"+"["+k+"]="+m[i][k]+"+");
					//System.out.print("m["+(k+1)+"]"+"["+j+"]="+m[k+1][j]);
					//System.out.print("\t"+"m["+i+"]"+"["+j+"]="+t+"\t");
					//System.out.print("k="+k+"   ");
					ans = t;
					if(t < m[i][j])
					{
						m[i][j] = t;
						s[i][j] = k;
					}
				}
				//System.out.println();
			}
			//System.out.println();
		}
		System.out.println(" "+m[0][4]);
		for(i=1;i<P.length;i++)
		{
			for(j=1;j<P.length;j++)
			{
				if(i<=j)
				System.out.print(" "+s[i][j]);
			}
			System.out.println();
		}
	}
}
