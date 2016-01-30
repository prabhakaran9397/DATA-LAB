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

	printf("testing search...");
	if (!search(t,1) || !search(t,2) || !search(t,3) ||
	    !search(t,4) || !search(t,5) || !search(t,6) || !search(t,7))
		goto fail;
	if (search(t,8) || search(t,9))
		goto fail;
	printf("[ok]\n");

	printf("testing remove_node...");
	remove_node(t,3);
	if (search(t,3) || !search(t,1))
		goto fail;
	remove_node(t,5);
	if (search(t,5) || !search(t,1))
		goto fail;
	remove_node(t,2);
	if (search(t,2) || !search(t,1))
		goto fail;
	remove_node(t,6);
	if (search(t,6) || !search(t,1))
		goto fail;
	remove_node(t,4);
	if (search(t,4) || !search(t,1))
		goto fail;
	remove_node(t,1);
	if (search(t,1))
		goto fail;
	printf("[ok]\n");

	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
