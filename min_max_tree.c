#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_CHILDREN 20

typedef struct Node
{
    int value;
    struct Node *children[MAX_CHILDREN];
    int num_children;
} Node;
Node *create_node(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->num_children = 0;
    return node;
}
void add_child(Node *parent, Node *child)
{
    parent->children[parent->num_children++] = child;
}
int max_value(Node *node);
int min_value(Node *node)
{
    if (node->num_children == 0)
    {
        return node->value;
    }
    int min = INT_MAX;
    for (int i = 0; i < node->num_children; i++)
    {
        int value = max_value(node->children[i]);
        if (value < min)
        {
            min = value;
        }
    }
    return min;
}
int max_value(Node *node)
{
    if (node->num_children == 0)
    {
        return node->value;
    }
    int max = INT_MIN;
    for (int i = 0; i < node->num_children; i++)
    {
        int value = min_value(node->children[i]);
        if (value > max)
        {
            max = value;
        }
    }
    return max;
}
int main()
{
    Node *root = create_node(1);
    Node *child1 = create_node(2);
    Node *child2 = create_node(3);
    Node *grandchild1 = create_node(4);
    Node *grandchild2 = create_node(5);
    Node *grandchild3 = create_node(6);
    Node *grandchild4 = create_node(7);
    add_child(root, child1);
    add_child(root, child2);
    add_child(child1, grandchild1);
    add_child(child1, grandchild2);
    add_child(child2, grandchild3);
    add_child(child2, grandchild4);
    int min = min_value(root);
    int max = max_value(root);
    printf("Min value: %d\n", min);
    printf("Max value: %d\n", max);
    return 0;
}
