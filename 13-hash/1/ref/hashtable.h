struct entry
{
    int key;
    int val;
};

struct HashTable
{
    int size;
    struct entry *arr;
};
void create(struct HashTable *ht, int size);
int insert(struct HashTable *ht, struct entry *e);
int search(struct HashTable *ht, int key, int *val, int *nops);
    