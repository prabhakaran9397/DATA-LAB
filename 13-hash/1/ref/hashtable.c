#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashtable.h"

void create(struct HashTable *h, int siz)
{
	h->size = siz;
	h->arr = (struct entry *)malloc(siz *sizeof(struct entry));
}


int insert(struct HashTable *h, struct entry *e)
{
	int i, slot, found = 0;

	for (i = 0; i < h->size; i++) {
		slot = ((e->key * e->key) + i) % h->size;
		if (h->arr[slot].key == 0) {
			h->arr[slot].key = e->key;
			h->arr[slot].val = e->val;
			found = 1;
			break;
		}
	}

	return found;
}

int search(struct HashTable *h, int key, int *val, int *nops)
{
	int i, slot, found = 0;

	*nops = 0;
	*val = 0;

	for (i = 0; i < h->size; i++) {

		(*nops)++;

		slot = ((key * key) + i) % h->size;

		if (h->arr[slot].key == key) {
			*val = h->arr[slot].val;
			found = 1;
			break;
		}
	}

	return found;

}
