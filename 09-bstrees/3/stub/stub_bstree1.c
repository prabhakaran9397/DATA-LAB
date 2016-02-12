#include<stdio.h>
#include"bstree.h"
int main()
{
	struct BSTree* b;

	printf("testing tree create...");
	if ((b = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing add...");
	add(b,1);
	add(b,2);
	add(b,3);
	add(b,4);
	if(search(b,4) == 0)
		goto fail;
	add(b,5);
	add(b,6);
	add(b,8);
	add(b,7);
	add(b,9);
	if(search(b,8) == 0)
		goto fail;
	if(search(b,7) == 0)
		goto fail;
	if(search(b,9) == 0)
		goto fail;
	printf("[ok]\n");
	
	printf("testing remove...");
	remove_node(b,4);
	if(search(b,4) == 1)
		goto fail;
	printf("[ok]\n");
	
	printf("testing search...");
	if(search(b,0) == 1)
		goto fail;
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
