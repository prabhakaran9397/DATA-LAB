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

void do_inorder(struct BSTreeNode *p, int *arr, int *count)
{
	if (p == NULL)
		return;

	do_inorder(p->left, arr, count);

	arr[*count] = p->val;
	(*count)++;

	do_inorder(p->right, arr, count);
}

void get_inorder(struct BSTree *t, int *arr, int *count)
{
	*count = 0;
	do_inorder(t->root, arr, count);
}

int do_get_height(struct BSTreeNode *p)
{
	int l, r;

	if (p == NULL)
		return -1;

	l = do_get_height(p->left);
	r = do_get_height(p->right);

	return (l > r) ? (l + 1) : (r + 1);
}

int get_height(struct BSTree *t)
{
	return do_get_height(t->root);
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