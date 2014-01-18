/*
	to implement the rod cutting by dynamic prog
	using top-down recurssion
	storing the results in additional array
	which stores the optimal cost already
*/

#include<stdio.h>

#define MAXIM(a,b) (((a)>=(b))?(a):(b))

int cutRod(int *p, int *r, int *s, int n)
{
	if(n==0)
		return 0;
	int i,j,q=-9999;
	
	for(i=1;i<=n;i++)
	{
		if(r[n-i]>=0)
		{
			if(q < p[i]+r[n-i])
			{
				q = p[i]+r[n-i];
				s[n]=i;
			}			
		}
		else
		{
			if(q < p[i]+cutRod(p,r,s,n-i))
			{
				q = p[i]+cutRod(p,r,s,n-i);
				s[n]=i;
			}
		}
	}
	r[n]=q;
	return q;
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


int initCutRod(int *p, int n)
{
	int i;
	int r[]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int s[]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	i= cutRod(p,r,s,n);
	dispSplit(s,n);
	return i;
}

void main()
{
	int i,price[]={0,1,5,8,9,10,17,17,20,24,30};
	
	
	printf("\nEnter number ");
	scanf("%d",&i);
	i=initCutRod(price,i);

/*	printf("\narray is %d",sizeof(price)/sizeof(*price));*/

	printf("\n %d is optimal ",i);

	printf("\n");

}

