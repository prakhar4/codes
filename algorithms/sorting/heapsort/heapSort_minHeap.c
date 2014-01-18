#include<stdio.h>

void minHeapify(int a[], int hSize, int pos)
{
	int left, right, i, j, sm=pos;
	
	left=2*pos;
	right=(2*pos)+1;
	
	if(a[left] < a[sm] && left<=hSize)
		sm=left;
	if(a[right] < a[sm] && right<=hSize)
		sm=right;
		
	if(sm != pos)
	{
		i=a[sm];
		a[sm]=a[pos];
		a[pos]=i;
		
		minHeapify(a, hSize, sm);		
	}
}


void buildMinHeap(int a[], int aSize)
{
	int i, j, leaf;
	
	leaf=(aSize)/2;
	
	for(i=leaf; i>=1; i--)
		minHeapify(a, aSize, i);
}

void swap(int a[], int pos1, int pos2)
{
	int t;
	t=a[pos1];
	a[pos1]=a[pos2];
	a[pos2]=t;

}


void hSort(int a[], int aSize)
{
	int i,j;
	buildMinHeap(a, aSize);
	swap(a, 1, aSize);
	
	for(i=1; i<aSize-1; i++)
	{
		minHeapify(a, (aSize-i), 1);
		swap(a, 1, (aSize-i));
	}
}


int main()
{
	int a[100], n, i;
	
	printf("\nEnter the limit of array  ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	hSort(a, n);
	
	printf("\n");
	for(i=1;i<=n;i++)
		printf("  %d  ",a[i]);
		
}

