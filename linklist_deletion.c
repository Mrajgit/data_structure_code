// link list all insertion
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
// insertion in first node
struct node *deletefirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// insertion in between nodes
struct node *deletebetween(struct node *head, int index)
{
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct node *n = p->next;
    p->next = n->next;
    free(n);
    return head;
}
// insert at end
struct node *deleteend(struct node *head)
{

    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
// insert at after node
struct node *deleteafter(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    // allocate memory for in the link list
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 9;
    second->next = third;

    // link third and fourth nodes
    third->data = 45;
    third->next = fourth;

    // link fourth and fifth nodes
    fourth->data = 60;
    fourth->next = fifth;

    // terminate the list at the fifth  nodes
    fifth->data = 50;
    fifth->next = NULL;

    printf("linklist before deletion \n");
    linkedListTraversal(head);
    printf("linklist after deletion \n");
    // head = deletefirst(head);
    // head = deletebetween(head, 2);
    // head = deleteend(head);
    head = deleteafter(head, 60);
    linkedListTraversal(head);
    return 0;
}