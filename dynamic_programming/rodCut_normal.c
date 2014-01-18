/*
	to find the optimal rod cutting
	using the recurssion normally
*/

#include<stdio.h>
#include<stdlib.h>

#define MAXS 10  
#define MAXIM(a,b) (((a)>=(b))?(a):(b))

int recRod(int *p, int n)
{
	if(n==0)
		return 0;
	int i,j,q=-9999;
	
	for(i=1;i<=n;i++)
		q=MAXIM(q,(p[i]+recRod(p,n-i)));
	
/*	printf("\nfor %d opt is %d ",n,q);*/
	return q;	
}


void main()
{
	int i,price[]={0,1,5,8,9,10,17,17,20,24,30};
	
	
	printf("\nEnter number ");
	scanf("%d",&i);
	i=recRod(price,i);
	printf("\n %d is optimal ",i);

	printf("\n");

}


