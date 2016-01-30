#include<stdio.h>
struct node
{
	char c;
	struct node *next;
};

struct list
{
	struct node *head;
};

struct node * node_create(char c);
struct list * list_create(void);
void list_free(struct list *l);
void list_add_head(struct list *l, struct node *n);
void list_del(struct list *l, struct node *n);
struct node * list_find(struct list *l, char c);
