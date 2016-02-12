struct entry
{
        int key;
        int val;
		struct entry *next;
};

struct OpenHashTable
{

        int size;
        struct entry **arr;
};

void create(struct OpenHashTable *h, int size);
int insert(struct OpenHashTable *h, struct entry *e);
int search(struct OpenHashTable *h, int key, int *val, int *nops);
