#include"list.h"
#include"queue.h"

int main()
{
	struct list *lq; 
	int x = 0;
	printf("\ntesting queue_create...");
	lq = queue_create();
	if(lq)
		printf("[ok]\n");
	else
		goto fail;
	
	printf("testing queue_insert...");
	x = queue_insert(lq, 'a');	
	if(x)
	{
		x = queue_insert(lq, 'b');
		x = queue_insert(lq, 'c');
		printf("[ok]");
	}
	else
		goto fail;
	
	printf("testing queue_remove...");
	printf("testing queue_empty...");
	printf("testing queue_free...");
	queue_free(lq);
	if(lq)
		goto fail;
	else
		printf("[ok]\n");
	
	return 0;
fail:
	printf("[failed]\n");
	return -1;
}	
