/*
        dlinked1.c
        using head and tail pointers.
        header files, ADT
        memory on demand: malloc(), free()
*/
#include <stdio.h>
#include <string.h>

#include "listd.h"




/*--------------------------------------------------*/
/*------------------- menu -------------------------*/
int menu(){
        int r = 0;

        printf("1. add a node\n");
        printf("2. remove a node\n");
	printf("3. display\n");
	printf("4. search\n");
        printf("0. Quit\n");
        do{
                printf("type[1-2-3-4 or 0]");
                scanf("%d", &r);
        } while(r < 0 || r > 4);
        return r;
}
int main()
{
        node_t *p;
        node_t *n1;
        int i;

        i = menu();
        while(i){
                switch(i){
                        case 1: n1 = get_node();
                                add_node(&head, &tail, n1);
                                break;
                        case 2: remove_node(&head, &tail);
                                traverse(&head);
                                break;
			case 3: traverse(&head);break;
			case 4: n1 = get_search();
				p = search_node(&head,n1);
				printf("search done");
				display_value(p->value);
                        default: exit(0);
                }
  		i = menu();
        }
        exit(0);
}

