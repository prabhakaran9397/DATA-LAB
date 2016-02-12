#include <stdio.h>
#include "bstree.h"

int main()
{
	struct BSTree* t;

	printf("testing tree create...");
	if ((t = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing add/search...");
	add(t,4);
	if (!search(t,4))
		goto fail;
	add(t,2);
	if (!search(t,2))
		goto fail;
	add(t,6);
	if (!search(t,6))
		goto fail;
	add(t,1);
	if (!search(t,1))
		goto fail;
	add(t,3);
	if (!search(t,3))
		goto fail;
	add(t,5);
	if (!search(t,5))
		goto fail;
	add(t,7);
	if (!search(t,7))
		goto fail;
	if (search(t,8) || search(t,9))
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
