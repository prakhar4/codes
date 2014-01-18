/*
	linear sorting using the counting sort 
	where the range in which the values lie is known
	have a temp array to store the number of occurances
Stable- this sorting technique is stable i.e it will preserve the order
	of occurances in the final output in case of tie in decision making
*/

#include<stdio.h>

countingSort(int a[], int n, int ran)
{
	int tem[ran],i,out[n];
	
	for(i=0;i<ran;i++)
		tem[i]=0;
		
	for(i=0;i<n;i++)
		tem[a[i]]++;
	
	for(i=1;i<ran;i++)
		tem[i]+=tem[i-1];
		
	for(i=n-1;i>=0;i--)
	{
		out[tem[a[i]]-1]=a[i];
		(tem[a[i]])-=1;
	}

	for(i=0;i<n;i++)
		a[i]=out[i];
	
}

void main()
{
	int a[50], size, i, range;
	printf("\nEnter the size of the array ");
	scanf("%d",&size);
	printf("\nEnter the range of elements ");
	scanf("%d",&range);
	
	
	
	for(i=0;i<size;i++)
		scanf("%d",&a[i]);
		
	countingSort(a,size,range);
	
	printf("\nSorted array is \n");
	for(i=0;i<size;i++)
		printf("\t%d  ",a[i]);
}

