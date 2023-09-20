#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("elements : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isempty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *push(struct node *top, int x)
{
    if (isfull(top))
    {
        printf("stack is full\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int peek(int data)
{
    struct node *ptr = top;
    for (int i = 1; (i < data - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int main()
{
    top = push(top, 10);
    top = push(top, 110);
    top = push(top, 120);
    top = push(top, 130);
    linkedListTraversal(top);
    for (int i = 1; i <= 4; i++)
    {
        printf("value at position %d is : %d\n", i, peek(i));
    }

    return 0;
}