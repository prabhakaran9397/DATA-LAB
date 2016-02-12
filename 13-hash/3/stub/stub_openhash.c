#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry
{
        int key;
        int val;
		struct entry *next;
};

struct OpenHashTable
{

        int size;
        struct entry **arr;
};

void create(struct OpenHashTable *h, int size);
int insert(struct OpenHashTable *h, struct entry *e);
int search(struct OpenHashTable *h, int key, int *val, int *nops);

int main()
{
	struct OpenHashTable *ht;
	ht = (struct OpenHashTable *)malloc(sizeof(struct OpenHashTable));
	create(ht,10);
	
	struct entry arr[] = {
		{ 1, 12 }, { 2, 14 }, { 11, 39 }, { 12, 47 }, { 5, 8 },
		{ 6, 23 }, { 7, 33 }, { 8, 19 }, { 9, 76 }, { 22, 20 }
	};
	int i, val, nops, expected_nops[] = { 3, 4, 2, 3, 1, 1, 1, 2, 1, 1 };

	printf("testing insert...");
	for (i = 0; i < 10; i++) {
		if (!insert(ht, &arr[i]))
			goto fail;
	}
	printf("[ok]\n");

	printf("testing search...");
	for (i = 0; i < 10; i++) {
		if (!search(ht, arr[i].key, &val, &nops))
			goto fail;
		if (val != arr[i].val || nops != expected_nops[i])
			goto fail;
	}
	if (search(ht, 99, &val, &nops))
		goto fail;
	printf("[ok]\n");

	return 0;

fail:
	printf("[failed]\n");
	return -1;
}
