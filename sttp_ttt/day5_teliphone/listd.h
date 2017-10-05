#include "datavalue.h"
typedef struct node {
        value_t    *value;
        struct node *next;
        struct node *prev;
} node_t;

struct node node_t;
/*------------------- globals ------------------------*/
node_t  head = {&NULLVALUE, NULL, NULL};
node_t  tail = {&NULLVALUE, NULL, NULL};

node_t * add_node(node_t *h, node_t *t, node_t *n);
node_t * insert_node(node_t *h, node_t *t, node_t *n, node_t *m);
node_t *remove_node(node_t *h, node_t *t);
node_t * delete_node(node_t *h, node_t *t, node_t *m);
node_t * search_node(node_t *h, node_t *n);
void traverse(node_t *h);
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
}/*------------------ delete -----------------------------*/
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
	int flag = 0;
	int j;
	printf("In Search");
	p=p->next;
        while(p != NULL){
		for( j = 1; j < p->value->phone; j++)
		{
			printf("In For of search node");
                	if( strcmp(p->value->ph[j],n->value->ph[j]) == 0 ) 
			{
				flag = 1;
				break;
			}
			if(flag == 1)
			{	
				break;
			}
		}
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
/*===================================================*/
node_t * get_search()
{
        node_t *np;

        np = (node_t *) malloc(sizeof(node_t));
	//printf("Enter in getsearch");
        np->value = get_value();
        np->next  = NULL;
        np->prev  = NULL;
        return np;
}