#include <stdio.h>
void recursiveInsertionSort(int arr[], int n)
	{
	if (n <= 1)
	return;
	recursiveInsertionSort( arr, n-1 );
	int nth = arr[n-1];
	int j = n-2;
	while (j >= 0 && arr[j] > nth)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = nth;
}
int main()
{
	int array[] = {100,50,10,90,30,20,80,40,60,70};
	int n = sizeof(array)/sizeof(array[0]);
	printf("Unsorted Array:\t");
	for (int i=0; i < n; i++)
	printf("%d ",array[i]);
	recursiveInsertionSort(array, n);
	printf("\n\nSorted Array:\t");
	for (int i=0; i < n; i++)
	printf("%d ",array[i]);
	return 0;
}
