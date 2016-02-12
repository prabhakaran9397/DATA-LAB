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
void do_inorder(struct BSTreeNode *p, int *arr, int *count);
int do_get_height(struct BSTreeNode *p);
void do_remove_node(struct BSTreeNode *p, struct BSTreeNode *parent);


struct BSTree * tree_create(void);
void add(struct BSTree *t, int val);
int search(struct BSTree *t, int val);
void get_inorder(struct BSTree *t, int *arr, int *count);
int get_height(struct BSTree *t);
void remove_node(struct BSTree *t, int val);