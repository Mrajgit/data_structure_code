#include <stdio.h>
void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int arrinsertion(int arr[], int size, int capacity, int index)
{
    if (index >= capacity)
    {
        return -1;
    }
    for (int i = index; i <= size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[10] = {3, 5, 7, 9, 10};
    int size = 5;
    int index = 3;
    traversal(arr, size);
    arrinsertion(arr, size, 10, index);
    size -= 1;
    traversal(arr, size);
    return 0;
}