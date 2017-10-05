	#include <stdio.h>

	struct node
	{
		char * name[3];
		char ** address;
		char ptype;
		char *phno;
		struct node * next;
	};
	struct node head = { NULL , NULL , NULL , NULL , 0  }; 
	
	
	struct node * add_node(struct node * h,struct node * n)
	{
		n->next = NULL;
		if(head->next == NULL)
		{
			head->next = n;
			return n;
		}
		
		/*while( n->next != NULL )
		{
			if
			{
				n->next = n->next + 1;
			}
		}*/
		
	}
		
	void display(void);/*to display the o/p screen*/

	int main()
	{
		display();
		return 0;
	}
	
	void display(void)
	{
		int choice = 4;
		char cnt,temp;
		
		printf("\n\n\t Telephone Directory");
		printf("\n\t ===================");
		
		do
		{
			printf("\n\t Menu");
			printf("\n\t 1. Add Subscriber");
			printf("\n\t 2. Search Suscriber");
			printf("\n\t 3. Remove Suscriber");
			printf("\n\t 4. Exit\n");
			
			printf("\n\n\t ::Enter Your Choice::");
			scanf("%d",&choice);
		

			switch(choice)
			{
				case 1: add_node(); break;
				case 2: break;
				case 3: break;
				case 4: exit(0);
				default: continue;
			}
			
			printf("\n\n\t Would you like to continue:::(y/n)");
			scanf("%c%c",&temp,&cnt);

		}while(cnt != 'n' || cnt != 'N');
	}
