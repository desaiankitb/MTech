/*
	slinked2.c
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
/*------------------- insert ---------------------------*/
node_t * insert_node(node_t *h, node_t *t, node_t *n, node_t *m)
{
	node_t * p = h;

	if(h->next == NULL || m == NULL)
		return NULL; /* list is empty */
	while(p != NULL){
		if(p->next == m) break;
		p = p->next;
	}
	if(p == NULL)
		return NULL; /* m is not present in the list */
	n->next = m;
	p->next = n;
	return p;
	
}
/*------------------- remove ---------------------------*/
/* remove the first node                                */
node_t *remove_node(node_t *h, node_t *t)
{
	node_t * p = h;
	
	if(h->next == NULL)
		return NULL; /* list is empty */
	p = h->next;
	h->next = h->next->next;
	if(h->next == NULL)
		t->next = NULL; /* list is becoming empty */
	return p;	
}
/*------------------ delete -----------------------------*/
node_t * delete_node(node_t *h, node_t *t, node_t *m)
{
	node_t * p = h;

	if(h->next == NULL || m == NULL)
		return NULL; /* list is empty */
	while(p != NULL){
		if(p->next == m) break;
		p = p->next;
	}
	if(p == NULL)
		return NULL; /* m is not present in the list */
	p->next = m->next;
	if(m->next == NULL)
		t->next = p;
	if(h->next == NULL)
		t->next = NULL;
	return p;	
}
/*------------------- search ---------------------------*/
node_t * search_node(node_t *h, node_t *n)
{
	node_t * p = h;

	while(p != NULL){
		if(p->value == n->value) break;
		p = p->next;
	}
	return p;
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
	printf("\n");
}
        node_t n1 = {111, NULL};
	node_t n2 = {222, NULL};
	node_t n3 = {333, NULL};
int main()
{
	node_t *p;
	node_t n4 = {999, NULL};
	
	add_node(&head, &tail, &n1);
	traverse(&head);
	add_node(&head, &tail, &n2);
	traverse(&head);
	add_node(&head, &tail, &n3);
	traverse(&head);	
	p = search_node(&head, &n1);
	printf("n2: Node %s present. \n", (p==NULL)?"not":"");
	p = insert_node(&head, &tail, &n4, p);
	printf("n4: Node %s inserted. \n", (p==NULL)?"not":"");
	delete_node(&head, &tail, &n3);
	traverse(&head);
	remove_node(&head, &tail);
	traverse(&head);
	remove_node(&head, &tail);
	traverse(&head);
	remove_node(&head, &tail);
	traverse(&head);
	remove_node(&head, &tail);
	traverse(&head);
}
