#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *s, int val)
{
    if (isfull(s))
    {
        printf("not insert element = %d\nbecause ", val);
        printf("stack is full\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
        printf("push element = %d\n", val);
    }
}
int pop(struct stack *s)
{
    int a = -1;
    if (isempty(s))
    {
        printf("stack is empty\n");
    }
    else
    {
        a = s->arr[s->top];
        printf("top element %d\n", a);
        printf("pop element = %d\n", a);
        s->top--;
        return a;
    }
}
int peek(struct stack *s, int i)
{
    int top = s->top - i + 1;
    if (top < 0)
    {
        printf("invaled position \n");
        return -1;
    }
    else
    {
        return s->arr[top];
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 150);
    push(s, 320);
    push(s, 304);
    push(s, 140);
    push(s, 260);
    push(s, 130);
    push(s, 330);
    for (int i = 1; i < s->top + 1; i++)
    {
        printf("the value at position %d is %d \n", i, peek(s, i));
    }

    return 0;
}