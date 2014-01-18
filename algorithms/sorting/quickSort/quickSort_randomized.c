//randomised quick sort
#include<stdio.h>
#include<stdlib.h>

int randGen(int min, int max)
{
	int *b,a;
	long l;
	b=(int*)malloc(sizeof(int));
		
	l=(long)b;
	a=(int)l;
	a/=896;
		
	a%=(max-min);
	a+=min;
	return a;
}
                                                                                                                                            
int partition(int a[], int st, int en)
{
	int i, j, rnd;
	
	rnd=randGen(st,en);
	iSwap(a, rnd, en);

	for(i=j=st; j<en; j++)
	{
		if(a[j] < a[en])
		{
			iSwap(a, j, i);
			i++;
		}	
	}

	iSwap(a, en, i);	
	return (i);
}


void randQsort(int a[], int st, int en)
{
	int part;
	
	if(st<en)
	{
		part=partition(a, st, en);
		randQsort(a, st, part-1);
		randQsort(a, part+1, en);
	}
}


int main()
{
	int i, a[100], n;
	
	printf("\nEnter the limits  ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	randQsort(a, 1, n);
	
	printf("\n");
	for(i=1;i<=n;i++)
		printf("  %d  ",a[i]);
		
	printf("\n");
	
return 0;
} 
