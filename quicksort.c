#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int partition(int a[], int l, int h)
{
    int pivot, i, j, swap;
    pivot = a[l];
    i = l + 1;
    j = h;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap = a[i];
            a[i] = a[j];
            a[j] = swap;
        }
    } while (i < j);
    swap = a[l];
    a[l] = a[j];
    a[j] = swap;
    return j;
}
void quicksort(int *a, int l, int h)
{
    int partitionIndex;
    if (l < h)
    {
        partitionIndex = partition(a, l, h);
        quicksort(a, l, partitionIndex - 1); //sort left subarray
        quicksort(a, partitionIndex + 1, h); //sort right subarray
    }
}
int main()
{
    int a[] = {10, 12, 34, 23, 6, 7};
    // int a[] = {1,2,3,4,5,6,7,8};
    int n = 6;
    printarray(a, n);
    printf("running quicksort------\n");
    quicksort(a, 0, n - 1);
    printarray(a, n);
    return 0;
}