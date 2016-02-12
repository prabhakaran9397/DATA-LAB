#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry
{
	int key;
	int val;
};
struct HashTable
{
	int size;
	struct entry *arr;
};

void create(struct HashTable *h, int siz);
int insert(struct HashTable *h, struct entry *e);
int search(struct HashTable *h, int key, int *val, int *nops);

int main()
{
	struct HashTable *ht;
	ht = (struct HashTable *)malloc(sizeof(struct HashTable));
	create(ht,10);
	struct entry arr[] = {
		{ 1, 12 }, { 2, 14 }, { 3, 39 }, { 4, 47 }, { 5, 8 },
		{ 6, 23 }, { 7, 33 }, { 8, 19 }, { 9, 76 }, { 10, 20 }
	};
	int i, val, nops, expected_nops[] = { 1, 1, 1, 1, 1, 2, 2, 5, 2, 4 };

	printf("testing insert...");
	for (i = 0; i < 10; i++) {
		if (!insert(ht,&arr[i]))
			goto fail;
	}
	if (insert(ht,&arr[0]))
		goto fail;
	printf("[ok]\n");

	printf("testing search...");
	for (i = 0; i < 10; i++) {
		if (!search(ht,arr[i].key, &val, &nops))
			goto fail;
		if (val != arr[i].val || nops != expected_nops[i])
			goto fail;
	}
	if (search(ht,99, &val, &nops))
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
	
}

