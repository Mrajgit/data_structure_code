#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int maximum(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void countsort(int *a, int n)
{
    int i, j;
    int max = maximum(a, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <=max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int a[] = {10, 12, 34, 23, 6, 7};
    // int a[] = {9, 14, 4, 8, 7, 5, 6};
    int n = 6;
    printarray(a, n);
    printf("running countsort------\n");
    countsort(a, n);
    printarray(a, n);
    return 0;
}