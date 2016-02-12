#include<stdio.h>
#include"bstree.h"
int main()
{
	struct BSTree* b;

	printf("testing tree create...");
	if ((b = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	int arr[7], count, i;
	int arr1[7]={5,6,7,10,11,14,15};
	add(b,10);
	add(b,7);
	add(b,5);
	add(b,14);
	add(b,6);
	add(b,11);
	add(b,15);
	
	printf("testing get_inorder...\n");
	get_inorder(b, arr, &count);
	
	printf("\tarr check : ");
	for(i=0; i<7; i++)
	{
		if(arr[i] != arr1[i])
			goto fail;
	}
	printf("[ok]\n");
	
	printf("\tcount check : ");
	if(count != 7)
		goto fail;
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
