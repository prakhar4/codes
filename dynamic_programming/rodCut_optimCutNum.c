/*
	to cut the rod most optimised
	with minimum number of cuts

	WRONG APPROACH	
	we donot compare it with 
	p[i] all the times, we compare it 
	with the new optised value in 'r' array

	TRIAL APPROACH  --WORKS
	we create another array and store the 
	minimum no of cuts needed for it
	MAINTAIN AN ARRAY WHICH HAS - NO OF CUTS
	REQUIRED FOR OPTIMALLY CUTTING GIVEN ROD
	LENGTH
	--COMPARE IT WHEN CHANGING VALUE

*/


#include<stdio.h>

int cutRod(int *p, int *r, int *s, int *cut, int n)
{
	int i,j,q;
	
	for(i=1;i<=n;i++)
	{
		q=-9999;
		for(j=1;j<=i;j++)
			if(q <= p[j]+r[i-j])		
			{
				if(q!=p[j]+r[i-j])
				{
					q=p[j]+r[i-j];
					s[i]=j;
					cut[i]=cut[i-j]+1;
					printf("\ni %d   j %d   q %d",i,j,q);		
				}
				else
				{
					if((cut[i-j]+1) < cut[i]) 	//THIS IS CONDITION TO CHK FOR MIN CUTS
					{
						s[i]=j;
						cut[i]=cut[i-j]+1;
						printf("\nchg i %d   j %d   q %d",i,j,q);		
					}
				
				}
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
	int i,price[]={0,1,5,8,9,10,17,17,20,24,30};
	int r[]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int s[]={0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int cut[]={-1,999,999,999,999,999,999,999,999,999};
	
	//necessary to have cut[0] to be -1
	
	printf("\nEnter number ");
	scanf("%d",&i);
	i=cutRod(price,r,s,cut,i);
	printf("\n %d is optimal ",i);
	
	printf("\n");
	for(i=0;i<11;i++)
		printf("  %d  ",cut[i]);
	
	printf("\n");
}
