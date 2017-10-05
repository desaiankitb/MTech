/*
	hash1.c
*/
#include <stdio.h>
#include <string.h>

#include "hash.h"

static hlist_t *hashtab[HASHSIZE];

/*------------------------- hash ------------------------*/
/* form a hash value from a string                       */
unsigned hash(char *s){
	unsigned hashval;
	
	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31*hashval;
	return hashval % HASHSIZE;
}

/*---------------------- lookup ------------------------*/
hlist_t * lookup(char *s){
	hlist_t *np;
	
	for(np = hashtab[hash(s)]; np != NULL; np = np->next)
		if(strcmp(s, np->data->name) == 0)
			return np;
	return NULL;
}	

/*--------------------- install ------------------------*/
hlist_t * install(hdata_t *data){
	hlist_t *np;
	unsigned hashval;
	
	if((np = lookup(data->name)) == NULL){ 
		np = (hlist_t *) malloc(sizeof(*np));
		np->data = (hdata_t *) malloc(sizeof(hdata_t));
		if(np == NULL || np->data == NULL ||
		   (np->data->name = strdup(data->name)) == NULL)
		   	return NULL;
		   	
		hashval = hash(data->name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else  /* already there */
		free((void *) np->data->defn);
	if((np->data->defn = strdup(data->defn)) == NULL)
		return NULL;
	return np;
}

int main(){
	hdata_t x = {"hbd","professor"};
	hlist_t *np;
	
	install(&x);
	np = lookup("hbd");
	printf("Found %s %s\n", np->data->name, np->data->defn);
}
