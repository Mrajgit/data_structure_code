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

	linkedListTraversal(head);
	return 0;
}
