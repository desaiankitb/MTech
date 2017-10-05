/*
	btree1.c
	ADT
	memory on demand
*/
#include <stdio.h>

//#include "btree.h"


/*------------------- insert ---------------------------*/
void insert_node(node_t **r, node_t *n)
{
	if(*r == NULL){
		*r = n;
		(*r)->lp = NULL;
		(*r)->rp = NULL;
		return; /* tree was empty */
	}
	if(comp(n->value, (*r)->value) < 0)
		insert_node(&((*r)->lp), n);
	else	insert_node(&((*r)->rp), n);
	return; 	
}
/*------------------ delete -----------------------------*/
/* returns 1 if deleted, 0 if not found                  */
int delete_node(node_t **r, node_t *n)
{
	if(*r == NULL) return 0;
	if(comp(n->value, (*r)->value) < 0)
		return delete_node(&((*r)->lp), n);
	else if(comp(n->value, (*r)->value) > 0)
		return delete_node(&((*r)->rp), n);
	else /* delete node found, test for leaf */
		if((*r)->lp == NULL){
			n = *r;
			*r = (*r)->rp;
			free(n);
			return 1;
		} else if((*r)->rp == NULL){
			n = *r;
			*r = (*r)->lp;
			free(n);
			return 1;
		} else { /* not a leaf, find largest on Left */
			n = (*r)->lp;
			while(n->rp != NULL)
				n = n->rp;
			(*r)->value = n->value;
			return delete_node(&((*r)->lp), n);
		}
}
/*------------------- search ---------------------------*/
node_t * search_node(node_t *r, node_t *n)
{
	if(r == NULL) return NULL;
	if(comp(n->value, r->value) < 0)
		return search_node(r->lp, n);
	else if(comp(n->value, r->value) > 0)
		return search_node(r->rp, n);
	else return r;
}
/*-------------------- traverse list -------------------*/
/* need to do in-order traversal                        */
void traverse(node_t *r)
{
	if(r == NULL) return;
	traverse(r->lp);
	display_value(r->value);
	traverse(r->rp);
}
/*--------------------------------------------------*/
node_t * get_node()
{
	node_t *np;
	
	np = (node_t *) malloc(sizeof(node_t));
	np->value = get_value();
	np->lp  = NULL;
	np->rp  = NULL;
	return np;
}
/*--------------------------------------------------*/
/*------------------- menu -------------------------*/
int menu(){
	int r = 0;
	
	printf("----- Menu -------\n");
	printf("1. insert a node\n");
	printf("2. delete a node\n");
	printf("3. search a node\n");
	printf("0. Quit\n");
	printf("------------------\n");
	do{
		printf("type[1-3 or 0]");
		scanf("%d", &r);
	} while(r < 0 || r > 3);
	return r;
}
int main()
{
	node_t *n1, *n2;
	int i;

	root = NULL;
        i = menu();
	while(i){
		switch(i){			
			case 1: n1 = get_node();
				insert_node(&root, n1);
				traverse(root);
				break;
			case 2: n1 = get_node();
				delete_node(&root, n1);
				traverse(root);
				break;
			case 3: n1 = get_node();
				n2 = search_node(root, n1);
				printf("\tNode %s present.\n", (n2==NULL)?"not":"");
				break;
			
			default: exit(0);
		}
		i = menu();
	}
	exit(0);
}
