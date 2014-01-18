#include<stdio.h>

void maxHeapify(int a[], int hSize, int pos)
{
	
	
	
	int lar=pos, left, right;
	
	left=(2*pos)+1;
	right=(2*pos)+2;
	
	if(a[left] > a[pos] && (left <= hSize))
		lar=left;
	if(a[right] > a[lar] && (right <= hSize))
		lar=right;
			
	if(lar!=pos)
	{
		a[lar]=a[lar]+a[pos];
		a[pos]=a[lar]-a[pos];
		a[lar]=a[lar]-a[pos];
		
		maxHeapify(a, hSize, lar);
	}
}


void buildMaxHeap(int a[], int aSize)
{
	
	int i, leaf=(aSize-1)/2;
	
	for(i=leaf; i>=0; i--)
		maxHeapify(a, aSize-1, i);
}

void swap(int a[], int pos1, int pos2)
{
	int temp;
	temp=a[pos1];
	a[pos1]=a[pos2];
	a[pos2]=temp;
}


void hSort(int a[], int aSize)
{
	int i,j,k;
	
	buildMaxHeap(a, aSize);
	
	aSize--;
	swap(a, 0, aSize);
	
	for(i=1; i<=aSize-1; i++)
	{
		maxHeapify(a, (aSize-i), 0);
		swap(a, 0, (aSize-i));
	}
}


void main()
{
	int a[100], i,j,n;
	
	printf("\nEnter the number of elements  ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	hSort(a, n);
	
	printf("\n");
	
	for(i=0;i<n;i++)
		printf("  %d  ",a[i]);
}



