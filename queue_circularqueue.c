#include <stdio.h>
#include <stdlib.h>
struct circularqueue
{
	int size;
	int f;
	int r;
	int *arr;
};
int isFull(struct circularqueue *q)
{
	if ((q->r + 1) % q->size == q->f)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isEmpty(struct circularqueue *q)
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
void enqueue(struct circularqueue *q, int val)
{
	if (isFull(q))
	{
		printf("circularqueue is full\n");
	}
	else
	{
		q->r = (q->r + 1) % q->size;
		q->arr[q->r] = val;
		printf("enqueue elements : %d\n", val);
	}
}
int dequeue(struct circularqueue *q)
{
	int a = -1;
	if (isEmpty(q))
	{
		printf("circularqueue is empty\n");
	}
	else
	{
		q->f = (q->f + 1) % q->size;
		a = q->arr[q->f];
	}
	return a;
}
int main()
{
	struct circularqueue q;
	q.size = 11;
	q.f = q.r = 0;
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
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	printf("dequeue element %d\n", dequeue(&q));
	//	printf("dequeue element %d\n", dequeue(&q));
	//	printf("dequeue element %d\n", dequeue(&q));
	//	printf("dequeue element %d\n", dequeue(&q));
	//	printf("dequeue element %d\n", dequeue(&q));
	//	printf("dequeue element %d\n", dequeue(&q));
	printf("\n");
	// after dequeueing element
	enqueue(&q, 100);
	enqueue(&q, 200);
	enqueue(&q, 300);
	enqueue(&q, 400);
	enqueue(&q, 500);
	//	enqueue(&q, 600);
	//	enqueue(&q, 700);
	//	enqueue(&q, 800);
	// 	enqueue(&q, 900);
	//	enqueue(&q, 1000);

	if (isEmpty(&q))
	{
		printf("circularqueue is empty\n");
	}
	// check full
	if (isFull(&q))
	{
		printf("circularqueue is full\n");
	}
	return 0;
}
