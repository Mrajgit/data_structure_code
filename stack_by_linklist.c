#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
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
// struct node *pop(struct node **top)
// {
//     if (isempty(*top))
//     {
//         printf("stack is empty\n");
//     }
//     else
//     {
//         struct node *n = *top;
//         *top = (*top)->next;
//         int a = n->data;
//         free(n);
//         return a;
//     }
// }
                // global variable
struct node *top = NULL;
struct node *pop(struct node *tp)
{
    if (isempty(tp))
    {
        printf("stack is empty\n");
    }
    else
    {
        struct node *n = tp;
        top = tp->next;
        int a = n->data;
        free(n);
        return a;
    }
}
int main()
{
    // struct node *top = NULL;
    top = push(top, 10);
    top = push(top, 110);
    top = push(top, 120);
    top = push(top, 130);
    linkedListTraversal(top);
    // printf("pop element is %d\n", pop(&top));
    printf("pop element is %d\n", pop(top));
    linkedListTraversal(top);
    return 0;
}