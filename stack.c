#include<stdio.h>
int maxsize =8;
int stack[8];
int top = -1;
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(top==maxsize)
	return 1;
	else
	return 0;
}
int peek()
{
	return stack[top];
}
int pop()
{
	int data;
	if(!isempty())
	{
		data=stack[top];
		top=top-1;
		return data;
	}
	else
	{
		printf("could not retrieve data, stack is empty, \n");
	}
}
int push(int data)
{
	if(!isfull())
	{
		top=top+1;
		stack[top]=data;
	}
	else
	{
		printf("could not insert data, stack is full. \n");
	}
}
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	printf("element at top of the stack : %d\n",peek());
	printf("element :\n");
	while(!isempty())
	{
		int data=pop();
		printf("%d\n",data);
	}
	printf("stack full : %s\n",isfull()?"true":"false");
	printf("stack empty : %s\n",isempty()?"true":"false");
	return 0;
}
