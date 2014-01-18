/*
	to solve rod cutting problem using dynamic
	prg but in bottom-top model
*/

#include<stdio.h>

int cutRod(int *p, int n)
{
	int r[]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int i,j,q;
	
	for(i=1;i<=n;i++)
	{
		q=-9999;
		for(j=1;j<=i;j++)
			if(q < p[j]+r[i-j])		
				q=p[j]+r[i-j];
		r[i]=q;
	}
	return r[n];
}

void main()
{
	int i,price[]={0,1,5,8,9,10,17,17,20,24,30};
	
	
	printf("\nEnter number ");
	scanf("%d",&i);
	i=cutRod(price,i);
	printf("\n %d is optimal ",i);

	printf("\n");
}
