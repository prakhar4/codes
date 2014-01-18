/*
	implement stable merge sort
	piggy backing inversions -- to count the number of inversions
*/

#include<stdio.h>
#define MAXS 100
#define INFI 999999
#define NINFI -9999

static int inc=0;
static double invC1=0;
static  int invC2=0;  //to count number of inverse

merge(int *arr, int p, int q, int r)
{
/*	int one[MAXS], two[MAXS];*/
	int one[q-p+1], two[r-q];
	int i,j=0, t1=0, t2=0, en1;
	
	for(i=p;i<=q;i++)
		one[j++]=arr[i];
	one[j]=INFI;
	en1=j;
			
	j=0;	
	for(i=q+1;i<=r;i++)
		two[j++]=arr[i];
	two[j]=INFI;
	
	for(i=p;i<=r;i++)
	{
		if(one[t1]<=two[t2])
			arr[i]=one[t1++];
		else
		{
			if(t1<en1)
			{	
				if((inc++)%2)
					invC1+=(en1-t1);
				/*else
					invC2+=(en1-t1);
			*/}
			arr[i]=two[t2++];
			
		}
	}	
	return;
}

mSort(int arr[], int st, int en)
{
	if(st>=en)
		return;
		
	int q=(st+en)/2;
	mSort(arr,st,q);
	mSort(arr,q+1,en);
	
	merge(arr,st,q,en);
	return;

}


void main()
{
	int /*arr[MAXS],*/ i, n;
	printf("\nEnter number of elements ");
	scanf("%d",&n);
	
	int arr[n];
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	mSort(arr,0,n-1);

	printf("\n");
	for(i=0;i<n;i++)
		printf("\n%d  ",arr[i]);
	
	printf("\nNumber of inv is %d ",invC1);
	printf("\nNumber of inv is %d ",invC2);
	
	printf("\n");
}
