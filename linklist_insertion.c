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
struct node *insertatfirst(struct node *head, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->next = head;
	ptr->data = data;
	return ptr;
}
// insertion in between nodes
struct node *insertatbetween(struct node *head, int data, int index)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	struct node *p = head;
	int i = 0;
	while (i != index - 1)
	{
		p = p->next;
		i++;
	}
	ptr->data = data;
	ptr->next = p->next;
	p->next = ptr;
	return head;
}
// insert at end
struct node *insertatend(struct node *head, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	struct node *p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = ptr;
	ptr->next = NULL;
	return head;
}
// insert at after node
struct node *insertatafter(struct node *head, struct node *prevnode, int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;

	ptr->next = prevnode->next;
	prevnode->next = ptr;
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

	printf("linklist before insertion \n");
	linkedListTraversal(head);
	printf("linklist after insertion \n");
	//	head=insertatfirst(head, 80);
	//	head=insertatbetween(head, 80, 1);
	//	head=insertatend(head, 80);
	head = insertatafter(head, second, 80);
	linkedListTraversal(head);
	return 0;
}
