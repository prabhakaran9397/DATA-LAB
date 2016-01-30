#include <stdio.h>
struct BSTreeNode
{
	int val;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
};

struct BSTree
{
	struct BSTreeNode *root;
};

struct BSTree * tree_create(void);
void add(struct BSTree *t, int val);
int search(struct BSTree *t, int val);
void remove_node(struct BSTree *t, int val);	
void get_postorder(struct BSTree *t, int *arr, int *count);
int get_height(struct BSTree *t);

int main()
{
	int arr[10], count, ref[10] = { 1, 3, 2, 5, 6, 4 };
	int i;
	struct BSTree *t;

	printf("testing tree create...");
	if ((t = tree_create()) == NULL)
		goto fail;
	printf("[ok]\n");

	printf("testing add...");
	add(t,4);
	add(t,2);
	add(t,6);
	add(t,1);
	add(t,3);
	add(t,5);
	printf("[ok]\n");

	printf("testing postorder...");
	get_postorder(t,arr, &count);
	if (count != 6)
		goto fail;
	for (i = 0; i < 6; i++) {
		if (arr[i] != ref[i])
			goto fail;
	}
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
