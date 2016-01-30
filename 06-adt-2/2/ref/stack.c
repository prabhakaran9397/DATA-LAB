#include"list.h"
#include"stack.h"
void * stack_create(void)
{
	struct list* l = list_create();
	return l;	
}

void stack_free(void *stack)
{
	struct list *l = (struct list*) stack;
	list_free(l);
}

int stack_push(void *stack, char c)
{
	struct list *l = (struct list*)stack;
	struct node *new_node = node_create(c);	
	if(new_node)
	{
		list_add_head(l,new_node);
		return 1;
	}
	return 0;
}

int stack_pop(void *stack, char *c)
{
	struct list *l = (struct list*)stack;
	//printf("stack-pop..\n");
	struct node *temp = l->head;
	while ( temp->next )
	{
		temp = temp->next;
	}
	*c = temp->c;
	list_del(l,temp);	
}
	
int stack_empty(void *stack)
{
	struct list *l = (struct list *)stack;
	if(l->head)
		return 0;
	else
		return 1;

}
