/*
	to partition the array as done in quick sort
	so that on left of pivot there are lesser
	and to the right we have greater values
*/

#include<stdlib.h>
#include<stdio.h>

int partition(int *a, int p, int r)
{
	int i=p-1, j, k, temp;
	
	for(j=p;j<r;j++)
	{
		if(a[j]<=a[r])
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	i++;
	temp=a[i];
	a[i]=a[r];
	a[r]=temp;
	
	return i;
	
	
}

int randPart(int *a, int st, int en)
{
	if(st==en)
		return st;
		
	int temp,q, i=((rand())%(en-st))+1;
	
	//printf("\nRandom no is %d ",i);
	
	temp=a[st+i];
	a[st+i]=a[en];
	a[en]=temp;
	
	q=partition(a,st,en);
	
	//printf("\nq is %d  st is %d  en is %d\n ",q,st,en);
	
/*	for(i=st;i<=en;i++)*/
/*		printf("  %d  ",a[i]);*/
	return q;
}
