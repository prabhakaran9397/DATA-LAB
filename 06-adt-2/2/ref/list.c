#include"list.h"
#include<stdlib.h>

struct node * node_create(char c)
{
	struct node *n =(struct node *) malloc(sizeof(struct node));
	if( n )
	{
		n->c=c;
		n->next = NULL;
		return n;
	}
	else
		return NULL; 
}

struct list * list_create(void)
{
	struct list *l =(struct list *) malloc(sizeof(*l));
	if( l )
	{
		l->head = NULL;
		return l;
	}
	else
		return NULL; 
}

void list_free(struct list *l)
{
	struct node *temp = l->head, *temp1;
	while(temp)
	{
		temp1 = temp->next;
		free(temp);
		temp = temp1;
	}
	free(l);
}

void list_add_head(struct list *l, struct node *n)
{
	if(l->head == NULL)
	{
		l->head = n;
		return;
	}
	n->next = l->head;
	l->head = n;
	return;
}

void list_del(struct list *l, struct node *n)
{
	struct node *prev, *cur;
	cur = l->head;
	if(l->head == n)
	{
		l->head = l->head->next;
		return;
	}
	while(cur != n)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur);
}

struct node * list_find(struct list *l, char c)
{
	struct node *temp = l->head;
	while( temp != NULL )
	{
		if( temp->c == c )
			return temp;
		temp = temp->next;
	}
	return NULL;
}
