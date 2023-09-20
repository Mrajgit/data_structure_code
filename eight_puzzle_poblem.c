#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define BOARD_SIZE 3
typedef struct Node
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int f, g, h;
    struct Node *parent;
} Node;
int goal_board[BOARD_SIZE][BOARD_SIZE] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}};
int find_zero_row(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                return i;
            }
        }
    }
    return -1;
}
int find_zero_col(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                return j;
            }
        }
    }
    return -1;
}
int manhattan_distance(int board[BOARD_SIZE][BOARD_SIZE])
{
    int distance = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            int value = board[i][j];
            if (value != 0)
            {
                int goal_row = (value - 1) / BOARD_SIZE;
                int goal_col = (value - 1) % BOARD_SIZE;
                distance += abs(i - goal_row) + abs(j - goal_col);
            }
        }
    }
    return distance;
}
bool is_goal(Node *node)
{
    return memcmp(node->board, goal_board, sizeof(node->board)) == 0;
}
bool is_valid(int row, int col)
{
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    printf("----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
Node *create_node(int board[BOARD_SIZE][BOARD_SIZE], Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    memcpy(node->board, board, sizeof(node->board));
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = parent;
    return node;
}
void free_node(Node *node)
{
    free(node);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
Node *get_successor(Node *node, int row, int col)
{
    int zero_row = find_zero_row(node->board);
    int zero_col = find_zero_col(node->board);
    if (!is_valid(row, col) || !is_valid(zero_row, zero_col))
    {
        return NULL;
    }
    int new_board[BOARD_SIZE][BOARD_SIZE];
    memcpy(new_board, node->board, sizeof(new_board));
    swap(&new_board[row][col], &new_board[zero_row][zero_col]);
    Node *successor = create_node(new_board, node);
    successor->g = node->g + 1;
    successor->h = manhattan_distance(successor->board);
    successor->f = successor->g + successor->h;
    return successor;
}
void print_solution(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    print_solution(node->parent);
    print_board(node->board);
    printf("\n");
}
void astar(int board[BOARD_SIZE][BOARD_SIZE])
{
    Node *start_node = create_node(board, NULL);
    start_node->h = manhattan_distance(start_node->board);
    start_node->f = start_node->h;
    Node *open_list = start_node;
    Node *closed_list = NULL;
    while (open_list != NULL)
    {
        Node *current_node = open_list;
        if (is_goal(current_node))
        {
            printf("Solution found!\n");
            print_solution(current_node);
            return;
        }
        open_list = current_node->parent;
        closed_list = current_node;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    Node *successor = get_successor(current_node, i, j);
                    if (successor != NULL)
                    {
                        Node *temp_node = open_list;
                        bool is_in_open_list = false;
                        while (temp_node != NULL)
                        {
                            if (memcmp(temp_node->board, successor->board, sizeof(temp_node->board)) == 0)
                            {
                                is_in_open_list = true;
                                break;
                            }
                            temp_node = temp_node->parent;
                        }
                        temp_node = closed_list;
                        bool is_in_closed_list = false;
                        while (temp_node != NULL)
                        {
                            if (memcmp(temp_node->board, successor->board, sizeof(temp_node->board)) == 0)
                            {
                                is_in_closed_list = true;
                                break;
                            }
                            temp_node = temp_node->parent;
                        }
                        if (!is_in_open_list && !is_in_closed_list)
                        {
                            successor->parent = current_node;
                            successor->g = current_node->g + 1;
                            successor->h = manhattan_distance(successor->board);
                            successor->f = successor->g + successor->h;
                            open_list = successor;
                        }
                        else
                        {
                            free_node(successor);
                        }
                    }
                }
            }
        }
    }
    printf("No solution found!\n");
}
int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {0, 7, 8}};
    astar(board);
    return 0;
}
