//PROGRAM TO USE INSERTION SORT RECURSIVELY


#include<stdio.h>
#include<conio.h>

ins_sort(int a[], int n)
{
	int p,q;
	
	if(n>=1)
	{
		p=n-1;
		ins_sort(a,p);
		insert(a,n);
	}


}

insert(int a[], int n)
{
	int i,j,k;
	k=a[n];
	j=n-1;
	while(k<a[j] && j>-1)
	{
		a[j+1]=a[j];
		j--;
	}
	
	a[j+1]=k;
}





main ()
{
	int i, a[100], n;
	
	printf("\nHow many memebers in array ");
	scanf("%d",&n);
	
	printf("\nEnter the array");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	ins_sort(a,n);
	
	printf("\nThe sorted array is \n\t");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
		
	getch();




}
