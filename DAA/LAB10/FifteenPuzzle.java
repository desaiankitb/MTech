class Node
{
	public int parent;//# of parent of the node
	public int cost;//cost of node
	public int state; //0=Live 1=Expanded
	public int node[][] = new int[4][4];
	Node()
	{
		
	}
	Node(int init[]) {
	int k=0;
	// Constructor
    	node = new int[4][4];      // Create array for tiles
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			node[i][j] = init[k];
			k++;
		}
	}
  }
}
public class FifteenPuzzle
{
	static int goalint[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	public static Node goal = new Node(goalint);//goal state
	public static Node child[] = new Node[4];
	public static int g_x(int x[][])//find how many tiles are not in proper position
	{
		int misplace = 0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(goal.node[i][j] == x[i][j])//if matching continue and check next
				{}
				else
					misplace++;
			}
		}
		return misplace;
	}
	public static void main(String args[])
	{

		int initint[] = {1,2,3,4,5,6,0,8,9,10,7,11,13,14,15,12};
		Node t = new Node(initint);
		t.parent = 0;
		t.cost = t.parent + g_x(t.node);
		t.state = 0;
		LC_search(t);
		
		System.out.println("cost = "+t.cost);
	}
	public static void LC_search(Node t)
	{
		int compairResult = g_x(t.node);
		if(compairResult == 0)
			return;
		t.state = 1;
		while(true)
		{
			child[0].node = t.node;
			child[1].node = t.node;
			child[2].node = t.node;
			child[3].node = t.node;
			createChildren(t);
			for(int i=0;i<4;i++)
			{
				if(g_x(child[i].node) == 0)
				{
					return;
				}
				//add(child[i]);
				child[i].parent = t.parent+1;
			}
			/*if()
			{
				return;
			}*/
			int temp = least();//0left 1right 2up 3down
			System.out.println(temp);
		}
	}
	public static int least()
	{
		int min = 999;
		int i=0;
		for(i=0;i<4;i++)
		{
			if(child[i].cost < min)
			{
				min = i;
			}
		}
		return i;
	}
	public static void createChildren(Node t)
	{
		int temp = 0;
		int i=0;
		int j=0;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(t.node[i][j] == 0)
				break;
			}
		}

		//left
			temp = child[0].node[i][j];//0 ne temp ma
			child[0].node[i][j-1] = temp;//0 ne 6 ni jagya e
			child[0].node[i][j] = child[0].node[i][j-1];
			child[0].cost = g_x(child[0].node);
		//right
			temp = child[1].node[i][j];//0 ne temp ma
			child[1].node[i][j+1] = temp;//0 ne 6 ni jagya e
			child[1].node[i][j] = child[1].node[i][j+1];
			child[1].cost = g_x(child[1].node);
		//up
			temp = child[2].node[i][j];//0 ne temp ma
			child[2].node[i-1][j] = temp;//0 ne 6 ni jagya e
			child[2].node[i][j] = child[2].node[i-1][j];
			child[2].cost = g_x(child[2].node);
		//down
			temp = child[3].node[i][j];//0 ne temp ma
			child[3].node[i+1][j] = temp;//0 ne 6 ni jagya e
			child[3].node[i][j] = child[3].node[i+1][j];
			child[3].cost = g_x(child[3].node);
	}
}
