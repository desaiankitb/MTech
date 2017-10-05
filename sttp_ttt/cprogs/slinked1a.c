/*
	slinked1.c
	modified: using head and tail pointers.
*/
#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
} node_t;
/*------------------- globals ------------------------*/
node_t  head = {99999, NULL};
node_t  tail = {-99999, NULL};

/*-------------------- add_node ----------------------*/
/*
  pre-condition: a head node and a tail node, with a list 
                 and an incoming node.
  post-condition: a list with added node.
  action: add node to list.
  returns: pointer to added node.
*/
node_t * add_node(node_t *h, node_t *t, node_t *n)
{
	n->next = NULL;
	if(h->next == NULL){
		h->next = n; /* take care of empty list  */
	} else 
		t->next->next = n;
	t->next = n;
	return n;			
}

/*-------------------- traverse list -------------------*/
void traverse(node_t *h)
{
	node_t * p = h;

	printf("\n");
	while(p != NULL){
		printf("[%d](%x)-->", p->value, p->next);
		p = p->next;
	}
}
        node_t n1 = {111, NULL};
	node_t n2 = {222, NULL};
	node_t n3 = {333, NULL};
int main()
{
	add_node(&head, &tail, &n1);
	traverse(&head);
	add_node(&head, &tail, &n2);
	traverse(&head);
	add_node(&head, &tail, &n3);
	traverse(&head);	
}
