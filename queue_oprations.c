#include <stdio.h>
#include <stdlib.h>
struct queue
{
	int size;
	int f;
	int r;
	int *arr;
};
int isFull(struct queue *q)
{
	if (q->r == q->size - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty(struct queue *q)
{
	if (q->r == q->f)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(struct queue *q, int val)
{
	if (isFull(q))
	{
		printf("queue is full");
	}
	else
	{
		q->r++;
		q->arr[q->r] = val;
		printf("enqueue element %d \n", val);
	}
}
int dequeue(struct queue *q)
{
	int a = -1;
	if (isEmpty(q))
	{
		printf("queue is empty");
	}
	else
	{
		q->f++;
		a = q->arr[q->f];
	}
	return a;
}
int main()
{
	struct queue q;
	q.size = 10;
	q.f = q.r = -1;
	q.arr = (int *)malloc(q.size * sizeof(int));

	// enqueue element
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	enqueue(&q, 60);
	enqueue(&q, 70);
	enqueue(&q, 80);
	enqueue(&q, 90);
	enqueue(&q, 100);
	printf("\n");
	//dequeue element
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	// check empty
	if (isEmpty(&q))
	{
		printf("queue is empty\n");
	}
	// check full
	if (isFull(&q))
	{
		printf("queue is full\n");
	}
	return 0;
}
