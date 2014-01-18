/* PROGRAM TO INOUT TWO SORTED ARRAYS AND MAKE A SINGLE SORTED ARRAY WITHOUT USING THE SENTINEL NUMBER AT LAST*/


#include<stdio.h>
#include<conio.h>

merge_sorted(int a[],int n1, int b[],int n2, int c[])
{
	int i,top1=0,top2=0;
	
	/*a[n1+1]=9999;			WITHOUT USING THESE
	b[n2+1]=9999;*/
	
	for(i=0;i<(n1+n2),(top1!=n1),(top2!=n2);i++)
	{
		if(a[top1]>b[top2])
		{
			c[i]=b[top2];
			top2++;			
		}
		else
		{
			c[i]=a[top1];
			top1++;
		}
	}
	
	
	 if(top1==n1)
	 {
		while(top2<n2)
		{
			c[i]==b[top2];
			top2++;
			i++;
		}
	 }
	  if(top2==n2)
	 {
		while(top1<n1)
		{
			c[i]==a[top1];
			top1++;
			i++;
		}
	 }
	 
	
	
}

main()
{
	int i, a[100], b[100], c[100], n1, n2;
	
	printf("\nHow many memebers in first array ");
	scanf("%d",&n1);
	
	printf("\nEnter the sorted array");
	for(i=0;i<n1;i++)
		scanf("%d",&a[i]);
		
	printf("\nHow many memebers in second array ");
	scanf("%d",&n2);
	
	printf("\nEnter the sorted array");
	for(i=0;i<n2;i++)
		scanf("%d",&b[i]);
		
	merge_sorted(a,n1,b,n2,c);
	
	
	printf("\nThe merged sorted array is \n\t");
	for(i=0;i<(n1+n2);i++)
		printf(" %d ",c[i]);
		
	getch();


}
