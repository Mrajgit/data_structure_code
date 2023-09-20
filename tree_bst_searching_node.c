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
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int bst(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!bst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return bst(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *bstsearch(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return bstsearch(root->left, key);
    }
    else
    {
        return bstsearch(root->right, key);
    }
}
struct node *bstiterativesearch(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
int main()
{
    // tree diagram [binary search tree]
    /*        7
             / \
            5   8
           / \   \
          3   6   9
         / \       \
        2   4       11
    */
    struct node *p = createnode(7);
    struct node *p1 = createnode(5);
    struct node *p2 = createnode(8);
    struct node *p3 = createnode(3);
    struct node *p4 = createnode(6);
    struct node *p5 = createnode(9);
    struct node *p6 = createnode(2);
    struct node *p7 = createnode(4);
    struct node *p8 = createnode(11);
    int key = 11;
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p5->right = p8;
    inorder(p);
    printf("\n");
    // printf("1 for BST 0 for not BST\n%d", bst(p));
    if (bst(p))
    {
        printf("\nthis is bst\n");
    }
    else
    {
        printf("this is not bst\n");
    }
    printf("\nrecursive method");
    struct node *n = bstsearch(p, key);
    // printf("\n%d is present in the bst ", n->data);
    if (n != NULL)
    {
        printf("\n %d is present in the bst", n->data);
    }
    else
    {
        printf("\n %d is not present in the bst", key);
    }

    printf("\n\niterative method");
    struct node *z = bstiterativesearch(p, key);
    if (z != NULL)
    {
        printf("\n %d is present in the bst", z->data);
    }
    else
    {
        printf("\n %d is not present in the bst", key);
    }
    return 0;
}