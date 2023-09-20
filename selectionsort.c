#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void selectionsort(int *a, int n)
{
    int indexofmin, swap, i, j;
    printf("running selectionsort-------\n");
    for (i = 0; i < n - 1; i++)
    {
        indexofmin = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofmin])
            {
                indexofmin = j;
            }
        }
        swap = a[i];
        a[i] = a[indexofmin];
        a[indexofmin] = swap;
    }
}
int main()
{
    int a[] = {10, 12, 34, 23, 6, 7};
    // int a[] = {1,2,3,4,5,6,7,8};
    int n = 6;
    printarray(a, n);
    selectionsort(a, n);
    printarray(a, n);
    return 0;
}