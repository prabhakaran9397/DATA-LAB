#include<stdio.h>
#include"bstree.h"
int main()
{
	struct BSTree* b;

	printf("testing tree create...");
	if ((b = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("\nAdding elements...");
	add(b,10);
	add(b,7);
	add(b,5);
	add(b,14);
	add(b,6);
	add(b,11);
	add(b,15);
	printf("[ok]\n");
	printf("Checking count_non_leaf_nodes...");	
	if(count_non_leaf_nodes(b) != 4)
		goto fail;
	printf("[ok]\n");
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
