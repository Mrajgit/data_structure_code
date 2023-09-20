#include<stdio.h>
int binarysearch();
int main(){
	int arr[]={10,20,30,40,50,60,70,80,90,100};
	int size,element,searchindex;
	size =sizeof(arr)/sizeof(int);
	element=70;
	searchindex=binarysearch(arr,0,size-1,element);
	if(searchindex== -1)
	{
		printf("element not found in array");
	}
	else
	{
		printf("element %d found at index : %d",element,searchindex);
	}
	return 0;
}
int binarysearch(int arr[], int start, int last, int element)
{
	int middle;
	while(start<=last)
	{	
		middle=start+(last-start)/2;
		if(arr[middle]==element)
		return middle;
		if(arr[middle]<element)
		start=middle+1;
		else
		last=middle-1;
	}
	return -1;
}
