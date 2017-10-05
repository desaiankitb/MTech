/*
	slinked1.c
*/
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};
/*------------------- globals ------------------------*/
struct node  head = {99999, NULL};

/*-------------------- add_node ----------------------*/
/*
  pre-condition: a head node with a list and an incoming node.
  post-condition: a list with added node.
  action: add node to list.
  returns: pointer to added node.
*/
struct node * add_node(struct node *h, struct node *n)
{
	struct node p = *h, *pp = &p;
	
	n->next = NULL;
	if(h->next == NULL){
		h->next = n; /* take care of empty list  */
		return n;
	}
	while(pp->next != NULL)
		pp = pp->next;     /* step to end of the list */
	pp->next = n;
	return n;			
}

/*-------------------- traverse list -------------------*/
void traverse(struct node *h)
{
	struct node * p = h;

	printf("\n");
	while(p != NULL){
		printf("[%d](%x)-->", p->value, p->next);
		p = p->next;
	}
}
        struct node n1 = {111, NULL};
	struct node n2 = {222, NULL};
	struct node n3 = {333, NULL};
int main()
{
	add_node(&head, &n1);
	traverse(&head);
	add_node(&head, &n2);
	traverse(&head);
	add_node(&head, &n3);
	traverse(&head);	
}
