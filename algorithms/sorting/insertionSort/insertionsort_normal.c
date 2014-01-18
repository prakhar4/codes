#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

void ins_sort(int a[], int n)
{
	int i,j,k;
	
	for(i=n-2;i>-1;i--)
		{
			k=a[i];
			j=i+1;
			
			while(k>a[j] && j<n)
			{
				a[j-1]=a[j];
				j++;
			}
			
			a[j-1]=k;
			
			
		}
}

main()
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
		
	//getch();


}
