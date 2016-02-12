#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
void inorder(struct BSTreeNode *, int *,int *,int *);

struct BSTree * tree_create(void)
{
	struct BSTree *t = (struct BSTree *)malloc(sizeof(*t));
	if (t) {
		t->root = NULL;
	}
	return t; 
}

void add(struct BSTree *t, int val)
{
	struct BSTreeNode *n, *p = t->root, *parent;

	n = (struct BSTreeNode *)malloc(sizeof(*n));

	n->val = val;
	n->left = NULL;
	n->right = NULL;

	if (t->root == NULL) {
		t->root = n;
		return;
	}

	while (p) {
		parent = p;
		if (val < p->val)
			p = p->left;
		else
			p = p->right;
	}

	if (val < parent->val)
		parent->left = n;
	else
		parent->right = n;
}

int search(struct BSTree *t, int val)
{
	struct BSTreeNode *p = t->root;

	while (p) {

		if (val == p->val)
			break;
		else if (val < p->val)
			p = p->left;
		else
			p = p->right;
	}

	return (p != NULL);
}
void do_remove_node(struct BSTree *t, struct BSTreeNode *p, struct BSTreeNode *parent)
{
	struct BSTreeNode *min;
	int tmp;

	if (p->right == NULL) { /* no right subtree */

		if (parent == NULL) /* root */
			t->root = p->left;
		else if (parent->left == p)
			parent->left = p->left;
		else
			parent->right = p->left;

		return;
	}

	/* find min node in the right subtree */
	min = p->right;
	parent = p;
	while (min->left) {
		parent = min;
		min = min->left;
	}

	/* swap values of p and min */
	tmp = p->val;
	p->val = min->val;
	min->val = tmp;

	/* remove the min node now */
	do_remove_node(t, min, parent);
}

void remove_node(struct BSTree *t, int val)
{
	struct BSTreeNode *p = t->root, *parent = NULL;

	while (p) {
		if (val == p->val)
			break;
		else if (val < p->val) {
			parent = p;
			p = p->left;
		} else {
			parent = p;
			p = p->right;
		}
	}

	if (p == NULL) /* not found */
		return;

	do_remove_node(t, p, parent);
}

int count_non_leaf_nodes(struct BSTree *t)
{
	int nonLeafCnt=0;
	struct BSTreeNode* temp = t->root;
	//printf("callin preorder..\n");
	inorder(temp, NULL, NULL, &nonLeafCnt);
	//printf("returned from preorder..\n");
	return nonLeafCnt;
}
void inorder(struct BSTreeNode *root, int *arr, int *count, int *leafCnt)
{
//printf("root\n");
	if (root)
	{
//
		//if(leafCnt)
	//printf("hi...\n");
		inorder(root->left,arr,count,leafCnt);
		if(leafCnt)
		{	
						
			if( (root->right != NULL) || (root->left != NULL) )
			{
				//printf("left..\n");
				//printf("hiiii..\n");
				(*leafCnt) += 1;
			}
		}
		else
			arr[(*count)++] = root->val;
		//printf("%d - ",arr[*count]-1);		
		inorder(root->right, arr, count, leafCnt);
	}
}
void get_inorder(struct BSTree *t, int *arr, int *count)
{
	struct BSTreeNode* temp = t->root;
	*count = 0;
	inorder(temp, arr, count, NULL);
}

