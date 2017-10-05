/*
	dlinked1.c
	using head and tail pointers.
	header files, ADT
	memory on demand: malloc(), free()
*/
#include <stdio.h>

#include "listd.h"


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
		t->prev->next = n;
	n->prev = t->prev;	
	t->prev = n;
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
        n->prev = p;
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
		t->prev = NULL; /* list is becoming empty */
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
	if(m->next != NULL) m->next->prev = p;
	if(m->next == NULL)
		t->prev = p;
	if(h->next == NULL)
		t->prev = NULL;
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
	np->prev  = NULL;
	return np;
}
/*--------------------------------------------------*/
/*------------------- menu -------------------------*/
int menu(){
	int r = 0;
	
	printf("1. add a node\n");
	printf("2. remove a node\n");
	printf("0. Quit\n");
	do{
		printf("type[1-2 or 0]");
		scanf("%d", &r);
	} while(r < 0 || r > 2);
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
				traverse(&head);
				break;
			case 2: remove_node(&head, &tail);
				traverse(&head);
				break;
			default: exit(0);
		}
		i = menu();
	}
	exit(0);
}
