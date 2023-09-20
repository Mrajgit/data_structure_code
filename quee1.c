#include<stdio.h>
#include<stdbool.h>
#define MAX 10
int arr[MAX];
int front=0;
int rear= -1;
int itemcount=0;
int peek()
{
	return arr[front];
}
bool isempty()
{
	return itemcount==0;
}
bool isfull()
{
	return itemcount==MAX;
}
int size()
{
	return itemcount;
}
void equeue(int data)
{
	if(!isfull())
	{
		if(rear==MAX-1)
		{
			rear=-1;
		}
		arr[++rear]=data;
		itemcount++;
	}
}
int dequeue()
{
	int data=arr[front++];
	if(front==MAX)
	{
		front=0;
	}
	itemcount--;
	return data;
}
int main()
{
	equeue(10);
	equeue(20);
	equeue(30);
	equeue(40);
	equeue(50);
	equeue(60);
	equeue(70);
	equeue(80);
	equeue(90);
	equeue(100);
	if(isfull())
	{
		printf("queue is full\n");
	}
	if(isempty())
	{
		printf("queue is empty\n");
	}
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("dequeue element : %d\n",dequeue());
	printf("element at front : %d\n",peek());
	printf("queue : ");
	while(!isempty())
	{
		int n=dequeue();
		printf("%d ",n);
	}
}
