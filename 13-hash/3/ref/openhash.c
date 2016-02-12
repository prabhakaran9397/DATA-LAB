#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "openhash.h"

void create(struct OpenHashTable *h, int siz)
{
	h->size = siz;
	h->arr = (struct entry **) malloc(siz *sizeof(struct entry*));
}


int insert(struct OpenHashTable *h, struct entry *e)
{
	int i, slot;
	struct entry *temp;

	slot = (e->key * e->key) % h->size;

	temp = (struct entry*) malloc(sizeof(struct entry));
	memcpy(temp, e, sizeof(*e));

	temp->next = h->arr[slot];
	h->arr[slot] = temp;

	return 1;
}

int search(struct OpenHashTable *h, int key, int *val, int *nops)
{
	int i, slot;
	struct entry *temp = NULL;

	*nops = 0;
	*val = 0;

	slot = (key * key) % h->size;
	temp = h->arr[slot];

	while (temp) {

		(*nops)++;

		if (temp->key == key)
			break;
		temp = temp->next;
	}

	if(temp != NULL)
		*val = temp->val;

	return (temp != NULL);
}
