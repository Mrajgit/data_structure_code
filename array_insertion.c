#include <stdio.h>
void traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int arrinsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main()
{
    int arr[10] = {3, 5, 7, 9, 10};
    int size = 5;
    int element = 8;
    int index = 3;
    traversal(arr, size);
    arrinsertion(arr, size, element, 10, index);
    size += 1;
    traversal(arr, size);
    return 0;
}