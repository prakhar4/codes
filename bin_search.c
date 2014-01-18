#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

bin_search(int a[], int st, int en, int item)
{
	int i,j,k;
	if(st<=en)
	{
	
	i=en-st+1;
		
	if(i%2==0)
		j=i/2;
	else
		j=(i+1)/2;
		
	if(a[j]==item)
		{
		printf("\nItem found !!");
		getch();
		exit(0);
		}
	else if(a[j]>item)
		bin_search(a,0,j,item);
	else 
		bin_search(a,j+1,en-1,item);
	
	
	
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
		
	printf("\nEnter the number to be searched");
	scanf("%d",&i);
		
	bin_search(a,0,n-1,i);
		

    getch();


}
