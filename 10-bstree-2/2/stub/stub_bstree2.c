#include <stdio.h>
#include "bstree.h"

int main()
{
	struct BSTree* t, *t2;

	printf("testing tree create...");
	if ((t = tree_create()) == NULL)
		goto fail;
	if ((t2 = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	int arr[10], count, ref[10] = { 1, 2, 3, 4, 5, 6 };
	int i;

	printf("testing add/search...");
	add(t,4);
	if (!search(t,4))
		goto fail;
	add(t,2);
	if (!search(t,4))
		goto fail;
	add(t,6);
	if (!search(t,4))
		goto fail;
	add(t,1);
	if (!search(t,4))
		goto fail;
	add(t,3);
	if (!search(t,4))
		goto fail;
	add(t,5);
	if (!search(t,4))
		goto fail;
	printf("[ok]\n");

	printf("testing get_inorder...");
	get_inorder(t, arr, &count);
	if (count != 6)
		goto fail;
	for (i = 0; i < 6; i++) {
		if (arr[i] != ref[i])
			goto fail;
	}
	printf("[ok]\n");

	printf("testing get_height...");
	add(t2,4);
	add(t2,2);
	add(t2,3);
	add(t2,6);
	if (get_height(t2) != 2)
		goto fail;
	printf("[ok]\n");


	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
