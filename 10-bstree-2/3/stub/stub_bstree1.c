#include <stdio.h>
#include "bstree.h"

int main()
{
	struct BSTree* t;

	printf("testing tree create...");
	if ((t = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing insert...");
	add(t,4);
	add(t,2);
	add(t,6);
	add(t,1);
	add(t,3);
	add(t,5);
	add(t,7);
	printf("[ok]\n");

	printf("testing search...");
	if (!search(t,1) || !search(t,2) || !search(t,3) ||
	    !search(t,4) || !search(t,5) || !search(t,6) || !search(t,7))
		goto fail;
	if (search(t,8) || search(t,9))
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
