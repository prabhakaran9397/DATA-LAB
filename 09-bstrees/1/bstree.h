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