/*6.5-3
Write pseudocode for the procedures H EAP -M INIMUM, H EAP -E XTRACT-M IN,
H EAP -D ECREASE -K EY, and M IN -H EAP -I NSERT that implement a min-priority
queue with a min-heap.*/


#include<stdio.h>

int numm=0;		//number of elements in queue now

void minHeapify(int a[], int hSize, int pos)
{
	int sm=pos,i,j, left=(2*pos), right=(2*pos+1);
	
	if(a[left]<a[pos] && (left<=hSize))
		sm=left;
	if(a[right]<a[sm] && (right<=hSize))
		sm=right;
		
	if(sm!=pos)
	{
		iSwap(a, pos, sm);
		minHeapify(a, hSize, sm);
	}
}

void buildMinHeap(int a[], int aSize)
{
	int i;
	for(i=(aSize/2); i>=1; i--)
		minHeapify(a, aSize, i);
}


void see(int a[], int aSize)
{
	int i;
	printf("\n");
	for(i=1; i<=aSize; i++)
		printf("  %d  ",a[i]);
		
	printf("\n");
}


int extractMin(int a[])
{
	if(numm==0) 
	{
		printf("underfl0w  ");
		return -1;
	}
	
	iSwap(a,1,numm);
	minHeapify(a, numm-1, 1);
	return (a[numm--]);
}


void chkUp(int a[], int pos)
{
	if(pos<=1)  return;
	
	if(a[pos]<a[(int)pos/2])
	{
		iSwap(a, pos, (int)pos/2);
		chkUp(a, (int)pos/2);
	}
}


void insert(int a[],int info)
{
	a[++numm]=info;
	chkUp(a, numm);
}


void update(int a[], int pos, int info)
{
	if(pos>numm || pos<1 || a[pos]==info)  return;
	
	if(info < a[pos])
	{
		a[pos]=info;
		chkUp(a, pos);
	}
	else
	{
		a[pos]=info;
		minHeapify(a,numm,pos);
	}

}




int main()
{
	int ch,a[100], p, n, i, pos;
	
	printf("\nEnter the number of elements  ");
	scanf("%d",&n);
	numm=n;
	
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	buildMinHeap(a, numm);	
	
	printf("\n1.See\n2.extract\n3.insert\n4.update\n5.exit  ");

	while(1)
	{
		printf("\nEnter ur choice  ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				see(a, numm);
				break;
			case 2:
				printf("\nthe min element was %d \n",extractMin(a));
				break;
			case 3:
				printf("\nEnter node to insert  ");
				scanf("%d",&i);
				insert(a,i);
				break;
			case 4:
				printf("\nEnter the index to update ");
				scanf("%d",&p);
				printf("nEnter the node key value ");
				scanf("%d",&i);
				update(a, p, i);
				break;
			case 5:
				return (0);
		}
	}
	return 0;
}
