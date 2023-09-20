#include <stdio.h>
#include <stdlib.h>
struct node *f = NULL;
struct node *r = NULL;
struct node
{
	int data;
	struct node *next;
};
void linkedListTraversal(struct node *ptr)
{
	printf("printing the element\n");
	while (ptr != NULL)
	{
		printf("elements : %d\n", ptr->data);
		ptr = ptr->next;
	}
}
void enqueue(int val)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	if (n == NULL)
	{
		printf("queue is full");
	}
	else
	{
		n->data = val;
		n->next = NULL;
		printf("enqueue elements %d\n", val);
		if (f == NULL)
		{
			f = r = n;
		}
		else
		{
			r->next = n;
			r = n;
		}
	}
}
int dequeue()
{
	int val = -1;
	struct node *ptr = f;
	if (f == NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		f = f->next;
		val = ptr->data;
		free(ptr);
	}
	return val;
}
int main()
{
	linkedListTraversal(f);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	printf("\n");
	printf("dequeueing the element\n");
	printf("dequeuing element %d\n", dequeue());
	printf("dequeuing element %d\n", dequeue());
	printf("dequeuing element %d\n", dequeue());
	printf("dequeuing element %d\n", dequeue());
	return 0;
}
