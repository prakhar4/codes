/*
	to print the split of rod cut
*/

#include<stdio.h>

int cutRod(int *p, int *r, int *s, int n)
{
	int i,j,q;
	
	for(i=1;i<=n;i++)
	{
		q=-9999;
		for(j=1;j<=i;j++)
			if(q <= p[j]+r[i-j])		
			{
				q=p[j]+r[i-j];
				s[i]=j;
				printf("\ni %d   j %d   q %d",i,j,q);
			}
		r[i]=q;
	}
	dispSplit(s,n);
	return r[n];
}

dispSplit(int *s, int n)
{
	int i;
	printf("\n");
	while(s[n]>0)
	{
		printf("  %d  ",s[n]);
		n-=s[n];
	}
}


void main()
{
	int i,price[]={0,1,2,3,4,5,16,17,20,24,30};
	int r[]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int s[]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
	printf("\nEnter number ");
	scanf("%d",&i);
	i=cutRod(price,r,s,i);
	printf("\n %d is optimal ",i);
	printf("\n");
}
