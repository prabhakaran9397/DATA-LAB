#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

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

void do_preorder(struct BSTreeNode *p, int *arr, int *count)
{
	if (p == NULL)
		return;

	arr[*count] = p->val;
	(*count)++;

	do_preorder(p->left, arr, count);
	do_preorder(p->right, arr, count);
}

void get_preorder(struct BSTree *t, int *arr, int *count)
{
	struct BSTreeNode* temp = t->root;
	*count = 0;
	do_preorder(temp, arr, count);
}

int do_count_non_leaf_nodes(struct BSTreeNode *p)
{
	int l, r;

	if (p == NULL)
		return 0;

	if (p->left == NULL && p->right == NULL)
		return 0;

	l = do_count_non_leaf_nodes(p->left);
	r = do_count_non_leaf_nodes(p->right);

	return l + r + 1;
}

int count_non_leaf_nodes(struct BSTree *p)
{
	return do_count_non_leaf_nodes(p->root);
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