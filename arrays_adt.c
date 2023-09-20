#include <stdio.h>
#include <stdlib.h>
struct array
{
    int size;
    int usize;
    int *ptr;
};
void createarr(struct array *a, int tsize, int ussize)
{
    a->size = tsize;
    a->usize = ussize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}
void show(struct array *a)
{
    for (int i = 0; i < a->usize; i++)
    {
        printf("element %d is : %d\n", i + 1, (a->ptr)[i]);
    }
}
void setval(struct array *a)
{
    int b;
    for (int i = 0; i < a->usize; i++)
    {
        printf("enter the element %d :", i + 1);
        scanf("%d", &b);
        (a->ptr)[i] = b;
    }
}
int main()
{
    struct array arr;
    createarr(&arr, 100, 5);
    setval(&arr);
    show(&arr);
    return 0;
}