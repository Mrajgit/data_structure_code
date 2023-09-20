#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 6
int arr[max];
int front=0;
int rear=-1;
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
	return itemcount==max;
}
int size()
{
	return itemcount;
}
void insert(int data)
{
	if(!isfull())
	{
		if(rear==max-1)
		{
			rear=-1;
		}
		arr[++rear]=data;
		itemcount++;
	}
}
int removedata()
{
	int data=arr[front++];
	if(front==max)
	{
		front=0;
	}
	itemcount--;
	return data;
}
int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(10);
	if(isfull())
	{
		printf("queue is full\n");
	}
	int num=removedata();
	printf("element removed :%d\n",num);
	insert(11);
	insert(12);
	insert(13);
	printf("element at front :%d\n",peek());
	printf("\n\n");
	printf("index 5 4 3 2 1 0\n");
	printf("\n\n");
	printf("queue : ");
	while (!isempty())
	{
		int n=removedata();
		printf("%d ",n);
	}
}
