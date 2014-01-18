/*
	to find the minimum n second minimum in 3(n/2) comparisons
*/

#include<stdio.h>

#define MAXSIZE 100
#define MAXM(a,b) ((a>=b)?(a):(b))


int calcPairs(int n,int *a,int *ans,int smin, int min)
{
	int i,sum,top,bot,flg=0;
	for(i=0;i<n;i+=2)
	{
		sum=a[i]+a[i+1];
		top=MAXM(a[i],a[i+1]);
		bot=sum-top;
		if(min>bot)
		{
			printf("\nin loop %d",i);
			smin=min;
			min=bot;	
		}
		else if(smin> bot && flg)
		{
			printf("\nout loop %d",i);
			smin=bot;
		}		
		flg++;
	}	

	(ans[0])=min;
	(ans[1])=smin;
	return 0 ;
}
			
int minMax(int n, int *a, int *ans)
{
	int min,max;

	if(n%2!=0)
	{
		min=a[1];
		max=a[1]+9999;
		calcPairs(n-1,&a[2],ans,max,min);
	}
	else
	{
		min=a[1];
		max=a[1]+9999;
		calcPairs(n,&a[1],ans,max,min);
	}
	return 0 ;
}

int main()
{
	int n,a[MAXSIZE],ans[2], i;
	
	printf("\nEnter the no of elements ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	minMax(n,a,ans);
	
	printf("\nMinimum is %d \nSec Min is %d\n",ans[0],ans[1]);
	return 0;
}
