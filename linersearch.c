#include<stdio.h>	
int linearsearch();
int main(){
	int arr[] = {10,12,31,43,46,57,89};
	int size,element,searchindex;
//	int arr[10];
//  element enter by user
//	for(int i=0;i<10;i++)
//	{
//		printf("enter the element %d  = ",i+1);
//		scanf("%d",&arr[i]);
//	}
//  search element enter by the user
//	printf("enter the element you can found =");
//	scanf("%d",&element);
	
	element =46;
	size =sizeof(arr)/sizeof(int);  //sizeof(arr)=elements*4      sizeof(int)=4
//	printf("size =%d",size);


	searchindex = linearsearch (arr,size,element);
	printf("the element is %d was found at index : %d \n",element,searchindex); 
	
	return 0;
}
int linearsearch(int arr[],int size,int element){
	for(int i=0; i<size; i++)
	{
		if(arr[i]==element){
			return i;		
		}
	}
	return -1;
}
