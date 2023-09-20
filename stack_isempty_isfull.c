#include <stdio.h>
#include <stdlib.h>
struct stack
{
	int size;
	int top;
	int *arr;
};
// stack empty
int isEmpty(struct stack *ptr)
{
	if (ptr->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//stack full
int isFull(struct stack *ptr)
{
	if (ptr->top == ptr->size - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	//	struct stack s;
	//	s.size=80;
	//	s.top=-1;
	//	s.arr=(int *)malloc(s.size *sizeof(int));
	struct stack *s;
	s->size = 80;
	s->top = -1;
	s->arr = (int *)malloc(s->size * sizeof(int));

	// push element
	s->arr[0] = 10;
	s->top++;
	// check stack is empty
	if (isEmpty(s))
	{
		printf("the stack is empty");
	}
	else
	{
		printf("the stack is not empty");
	}
	return 0;
}
