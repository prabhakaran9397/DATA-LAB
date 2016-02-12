#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

struct BSTree * tree_create()
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

void preorder(struct BSTreeNode *, int *,int *,int *);

int count_leaf_nodes(struct BSTree *t)
{
	int leafCnt=0;
	struct BSTreeNode* temp = t->root;
	printf("callin preorder..\n");
	preorder(temp, NULL, NULL, &leafCnt);
	printf("returned from preorder..\n");
	return leafCnt;
}

void preorder(struct BSTreeNode* root, int *arr, int *count, int *leafCnt)
{
//printf("root\n");
	if (root)
	{
//
		//if(leafCnt)
	//printf("hi...\n");
		if(leafCnt)
		{	
			//printf("leafcnt..\n");
			
			if((root->right == NULL))//
			{
				//printf("left..\n");
				if(root->left == NULL)
				{			
				//printf("hiiii..\n");
				(*leafCnt) += 1;
				return;
				}
			}
		}
		else
			arr[(*count)++] = root->val;
		//printf("%d - ",arr[*count]-1);		
		preorder(root->left, arr, count, leafCnt);
		preorder(root->right, arr, count, leafCnt);
	}
}
void get_preorder(struct BSTree *t, int *arr, int *count)
{
	struct BSTreeNode* temp = t->root;
	preorder(temp, arr, count, NULL);
}

