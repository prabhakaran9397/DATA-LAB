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
void do_preorder(struct BSTreeNode *p, int *arr, int *count);
int do_count_non_leaf_nodes(struct BSTreeNode *p);
void do_remove_node(struct BSTree *t, struct BSTreeNode *p, struct BSTreeNode *parent);

struct BSTree * tree_create(void);
void add(struct BSTree *t, int val);
int search(struct BSTree *t, int val);
void get_preorder(struct BSTree *t, int *arr, int *count);
int count_non_leaf_nodes(struct BSTree *t);
void remove_node(struct BSTree *t, int val);


