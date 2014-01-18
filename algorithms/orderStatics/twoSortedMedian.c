/*
	given two sorted arrays each n elements
	we need to find the median of both the 
	combined array elements
	in the worst time O(log n)
	
	ALGO- discard half of array each time 
	by comparing the medians - analyse
*/
// we have two median for the combined array 
// as the total number of elements is EVEN


#include<stdio.h>

int med1, med2; //both the medians

static int getMedC=0;
static int first=0;
static int sec=0, lp1=0, lp2=0;

void getMedian(int *a, int *b, int aS, int aE, int bS, int bE)
{
	printf("\nEnter func %d ",getMedC++);

//if(aS==aE && bS==bE)//as aS==aE when bS==bE
	if(aS+1==aE)
	{
		printf("\nEnter first %d ",first++);
		//med1=aS;	
		//med2=bS;
		
		if(a[aS]<b[bS])
		{
			med1=aE;
			med2=bS;
			return;
		}
		else
		{
			med1=aS;
			med2=bE;
			return;
		}
		return;
	}

/*
	if(bS==bE)		
		med2=bS;
*/

	int aM=(aS+aE)/2, bM=(bS+bE)/2;
	if(a[aM]==b[bM])
	{
		printf("\nEnter sec %d ",sec++);
		med1=aM;
		med2=bM;
		return;
	}
	
	if(a[aM]>b[bM])
	{
		printf("\nEnter loop1 %d ",lp1++);
		getMedian(a,b,aS,aM,bM,bE);
		return;
	}
	else
	{
		printf("\nEnter loop2 %d ",lp2++);
		getMedian(a,b,aM,aE,bS,bM);
		return;
	}
	return;
}


main()
{
	int a[]={1,2,3,4,5,11,13};
	int b[]={6,7,8,9,10,12,15};
	int size=7;
	
	getMedian(a,b,0,size-1,0,size-1);

	printf("\nTwo medians are %d  %d \n",a[med1], b[med2]);


}





















