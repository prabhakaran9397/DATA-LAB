#include<stdio.h>
#include"bstree.h"
int main()
{
	struct BSTree* b;

	printf("testing tree create...");
	if ((b = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	int arr[9], count, i;
	int arr1[9]={1,2,3,4,5,6,8,7,9};
	add(b,1);
	add(b,2);
	add(b,3);
	add(b,4);
	add(b,5);
	add(b,6);
	add(b,8);
	add(b,7);
	add(b,9);
	
	printf("testing get_preorder...\n");
	get_preorder(b, arr, &count);

	printf("\tarr check : ");
	for( i=0; i<9; i++)
	{
		if(arr[i] != arr1[i])
			goto fail;
	}
	printf("[ok]\n");
	
	printf("\tcount check : ");
	if(count != 9)
		goto fail;
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
