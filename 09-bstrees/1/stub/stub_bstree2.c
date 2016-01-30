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
	add(t,7);
	printf("[ok]\n");

	printf("testing get_height...");
	if (get_height(t) != 2)
		goto fail;
	remove_node(t,1);
	if (get_height(t) != 2)
		goto fail;
	remove_node(t,3);
	if (get_height(t) != 2)
		goto fail;
	remove_node(t,5);
	if (get_height(t) != 2)
		goto fail;
	remove_node(t,7);
	if (get_height(t) != 1)
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
