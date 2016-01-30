#include<stdlib.h>
#include"list.h"

int main()
{
	struct list *l;
	struct node *n;
	struct node *n1;

	printf("\ntesting node_create...");	
	n = node_create('e');
	n1 = node_create('i');
	if( n == NULL || n->c != 'e' || n->next != NULL )
		goto fail;
	if( n1 == NULL || n1->c != 'i' || n1->next != NULL )
		goto fail;
	printf("[ok]\n");

	printf("\ntesting list_create...");
	l = list_create();
	if(l)
		printf("[ok]\n");
	else
		goto fail;

	printf("testing list_add_head...");
	list_add_head(l,n);
	if (l->head != n)
		goto fail;
	list_add_head(l,n1);
	if(l->head != n1)
		goto fail;
	printf("[ok]\n");
	
	printf("testing list_find...");
	if ( list_find( l, 'e' ) != n || list_find( l, 'i' ) != n1 )
		goto fail;
	printf("[ok]\n");
	
	printf("testing list_del...");
	list_del(l, n);
	if(l->head == n)
		goto fail;
	else
		printf("[ok]\n");

	printf("testing list_find...");
	if ( list_find( l, 'e' ) != NULL || list_find( l, 'i' ) != n1 )
		goto fail;
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}
