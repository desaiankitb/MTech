/*
	slinked4.c
	modified: using head and tail pointers.
	          header files, ADT
	          memory on demand: malloc(), free()
*/
#include <stdio.h>

#include "list.h"


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
		if(p->value->phone == n->value->phone) break;
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
		display_value(p->value);
		p = p->next;
	}
	printf("\n");
}
/*--------------------------------------------------*/
node_t * get_node()
{
	node_t *np;
	
	np = (node_t *) malloc(sizeof(node_t));
	np->value = get_value();
	np->next  = NULL;
	return np;
}
/*--------------------------------------------------*/
int main()
{
	node_t *p;
        node_t *n4; 
	value_t *v4;
	node_t *n1;
	int i;
	
        n4 = (node_t *) malloc(sizeof(node_t));
        v4 = (value_t *) malloc(sizeof(value_t));
	strcpy(v4->name,"HBdave4"); 
	v4->phone = 12345;
	n4->value = v4; 
	n4->next = NULL;
	
	for(i=0; i<3; i++){
		n1 = get_node();
		add_node(&head, &tail, n1);
		traverse(&head);
	}
/*	p = insert_node(&head, &tail, n4, p);
	printf("n4: Node %s inserted. \n", (p==NULL)?"not":"");
*/
}
