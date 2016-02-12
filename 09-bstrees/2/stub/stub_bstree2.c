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
	add(b,1);
	add(b,2);
	add(b,3);
	add(b,4);
	add(b,5);
	add(b,6);
	add(b,8);
	add(b,7);
	add(b,9);
	printf("[ok]\n");
	printf("Chenking count_leaf_nodes...");	
	if(count_leaf_nodes(b) != 2)
		goto fail;
	printf("[ok]\n");
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
