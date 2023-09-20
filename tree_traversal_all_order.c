#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *a;
    a = (struct node *)malloc(sizeof(struct node));
    a->data = data;
    a->left = NULL;
    a->right = NULL;
    return a;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *p = createnode(2);
    struct node *p1 = createnode(7);
    struct node *p2 = createnode(5);
    struct node *p3 = createnode(2);
    struct node *p4 = createnode(11);
    struct node *p5 = createnode(9);
    struct node *p6 = createnode(6);
    struct node *p7 = createnode(5);
    struct node *p8 = createnode(4);
    // tree diagram
    /*        2
             / \
            7   5
           / \   \
          2   11  9
         / \       \
        6   5       4
    */
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p5->right = p8;
    printf("\nPREORDER TRAVERSAL\n\n");
    preorder(p);
    printf("\n\n--------------------------------\n");
    printf("\nINORDER TRAVERSAL\n\n");
    inorder(p);
    printf("\n\n--------------------------------\n");
    printf("\nPOSTORDER TRAVERSAL\n\n");
    postorder(p);
    printf("\n\n--------------------------------\n");
    return 0;
}