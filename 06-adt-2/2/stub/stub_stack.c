#include <stdio.h>

void *stack_create(void);
void stack_free(void *stack);
int stack_push(void *stack, char c);
int stack_pop(void *stack, char *c);
int stack_empty(void *stack);

int main()
{
	void *ls; 
	int x = 0;
	char c;
	printf("\ntesting stack_create...");
	ls = stack_create();
	if(ls)
		printf("[ok]\n");
	else
		goto fail;
//	printf("test..\n");
	printf("testing stack_push/pop...");
	if (!stack_push(ls, 'a'))
		goto fail;
	if (!stack_push(ls, 'b'))
		goto fail;
	if (!stack_push(ls, 'c'))
		goto fail;
	if (!stack_pop(ls, &c) || c != 'c')
		goto fail;
	if (!stack_pop(ls, &c) || c != 'b')
		goto fail;
	if (!stack_pop(ls, &c) || c != 'a')
		goto fail;
	printf("[ok]\n");
	
	printf("testing stack_empty...");
	if (!stack_empty(ls))
		goto fail;
	if (!stack_push(ls, 'a'))
		goto fail;
	if (stack_empty(ls))
		goto fail;
	printf("[ok]\n");

	printf("testing stack_free...");
	stack_free(ls);
	printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}	
