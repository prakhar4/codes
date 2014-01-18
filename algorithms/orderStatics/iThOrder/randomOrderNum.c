/*
	to find the i-th order statistics for a given
	set i.e given a set of numbers we can find 
	out the i-th smallest number of the group
*/

#include<stdio.h>
int partition(int *a, int p, int r);
int randPart(int *a, int st, int en);


orderStat(int *a, int k, int p, int r)
{
	if(p>=r)
		return p;
	
	int q=randPart(a,p,r);
	
	if(q==k)
		return q;
	else if(q>k)
		orderStat(a,k,p,q-1);
	else
		orderStat(a,k,q+1,r);	

}



int main()
{
	int n,k,a[100],pos, i;
	
	printf("\nEnter the no of elements ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	printf("\nEnter the position ");
	scanf("%d",&k);
		
	pos=orderStat(a,k,1,n);
	//printf("\npos ret is %d ",pos);	
	printf("\norder stat is %d \n",a[pos]);
	return 0;
}
