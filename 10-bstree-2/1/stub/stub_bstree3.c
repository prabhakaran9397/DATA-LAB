#include <stdio.h>
#include "bstree.h"

int main()
{
	struct BSTree* t;

	printf("testing tree create...");
	if ((t = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");
	
	int arr[10], count, ref[10] = { 1, 3, 2, 5, 7, 6, 4 };
	int i;

	printf("testing add/search...");
	add(t,4);
	add(t,2);
	add(t,6);
	add(t,1);
	add(t,3);
	add(t,5);
	add(t,7);
	if (!search(t, 1) || !search(t, 2) || !search(t, 3) ||
	    !search(t, 4) || !search(t, 5) || !search(t, 6) || !search(t, 7))
		goto fail;
	if (search(t, 8) || search(t, 9))
		goto fail;
	printf("[ok]\n");

	printf("testing remove_node...");
	remove_node(t, 3);
	if (search(t, 3) || !search(t, 1))
		goto fail;
	remove_node(t, 5);
	if (search(t, 5) || !search(t, 1))
		goto fail;
	remove_node(t, 2);
	if (search(t, 2) || !search(t, 1))
		goto fail;
	remove_node(t, 6);
	if (search(t, 6) || !search(t, 1))
		goto fail;
	remove_node(t, 4);
	if (search(t, 4) || !search(t, 1))
		goto fail;
	remove_node(t, 1);
	if (search(t, 1))
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
