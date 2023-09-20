#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void bubblesort(int *a, int n)
{
    int i, j, swap;
    int issorted = 0;
    printf("running bubblesort-------\n");
    for (i = 0; i < n - 1; i++)
    {
        // printf("pass no %d\n", i + 1);
        issorted = 1;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}
int main()
{
    int a[] = {10, 12, 34, 23, 6, 7};
    // int a[] = {1,2,3,4,5,6,7,8};
    int n = 6;
    printarray(a, n);
    bubblesort(a, n);
    printarray(a, n);
    return 0;
}