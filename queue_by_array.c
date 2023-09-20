#include<stdio.h>
#define N 5
int queue [N];
int rear =-1;
int front =-1;
void enqueue(int x)
{
	if(rear==N-1)
	{
		printf("queue is full\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else
	{
		rear++;
		queue[rear]=x;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("queue is empty\n");
	}
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		printf("dequeue element %d\n",queue[front]);
		front++;
	}
}
void display()
{
	if(front==-1 && rear==-1)
	{
		printf("queue is empty");
	}
	for(int i=front;i<rear+1;i++)
	{
		printf("equeue element %d \n",queue[i]);
	}
}
void peek()
{
	if(front==-1 && rear==-1)
	{
		printf("queue is empty");
	}
	else
	{
		printf("front element %d\n",queue[front]);
	}
}
int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(1);
	enqueue(2);
	enqueue(2);
	display();
	peek();
//	dequeue();
//	peek();
//	display();
	return 0;
}
