#include<stdio.h>

int top1=0,top2=0;//mid,i,
int a[100], x[50], y[50];

void merge(int p, int q, int r)			//to sort two already sorted sub-arrays p to q and q+1 to r
{
	int i,top1=0,top2=0;
	
	top1=top2=0;
	
	printf("\n merge called ");
	
	for(i=0;i<(q-p+1);i++)
	{
		x[i]=a[p+i];
	}
	x[i]=9999;
	
	
	for(i=0;i<(r-q);i++)
	{
		y[i]=a[q+1+i];
	}
	y[i]=9999;
	
	for(i=p;i<=r;i++)
	{
		if(x[top1]>y[top2])
		{
			a[i]=y[top2];
			top2++;		
			
		}
		else
		{
			a[i]=x[top1];
			top1++;		
			
		}
	}
}

void m_sort(int m, int n)
{
	int mid;
	
	printf("\n m_sort called ");
	
	if(m<n)
	{
	mid=(m+n)/2;
	
	m_sort(m,mid);
	m_sort(mid+1,n);
	merge(m,mid,n);
	}

}



main()
{
	int i,n;
	printf("\nEnter the limit for the array ");
	scanf("%d",&n);
	
	printf("\nEnter the array ");
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	m_sort(0,n-1);
	
	printf("\nThe sorted array is now  ");
	
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
}
