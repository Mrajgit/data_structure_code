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
void bstinsert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("cannot insert %d , already in BST\n", key);
            return;
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
    struct node *new = createnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
struct node *inorderpredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *bstdeletion(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("cannot delete %d , because node is not present in BST\n", key);
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    //search for the node deleted
    if (key < root->data)
    {
        root->left = bstdeletion(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = bstdeletion(root->right, key);
    }
    // deleted node method
    else
    {
        struct node *ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = bstdeletion(root->left, ipre->data);
    }
    return root;
}
int main()
{
    // tree diagram [binary search tree]
    /*        9
             / \
            5   14
           / \   \
          3   6   16
         / \       \
        2   4       19
    */
    struct node *p = createnode(9);
    struct node *p1 = createnode(5);
    struct node *p2 = createnode(14);
    struct node *p3 = createnode(3);
    struct node *p4 = createnode(6);
    struct node *p5 = createnode(16);
    struct node *p6 = createnode(2);
    struct node *p7 = createnode(4);
    struct node *p8 = createnode(19);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p5->right = p8;
    inorder(p);
    printf("\nafter insertion a node inorder traversal\n");
    int key = 15;
    bstinsert(p, key);
    inorder(p);
    printf("\nafter delete a node inorder traversal\n");
    bstdeletion(p, key);
    inorder(p);
    return 0;
}