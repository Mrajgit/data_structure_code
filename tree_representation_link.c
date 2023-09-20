#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createnode(int data)
{
    struct node *a;
    a = (struct node *)malloc(sizeof(struct node));
    a->data = data;
    a->left = NULL;
    a->right = NULL;
    return a;
}
int main()
{
    struct node *p=createnode(2);
    struct node *p1=createnode(1);
    struct node *p2=createnode(4);
    struct node *p3=createnode(6);
    struct node *p4=createnode(5);
    return 0;
}