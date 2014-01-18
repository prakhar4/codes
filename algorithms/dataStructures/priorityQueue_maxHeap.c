/**** IMPLEMENT THE PRIORITY QUEUES *****************/

#include<stdio.h>

int number=0;		//to keep count of number of elements in heap

void maxHeapify(int a[], int hSize, int pos)
{
	int left=(2*pos), right=(2*pos+1), max=pos;
	
	if(a[max] < a[left])
		max=left;
	if(a[max] < a[right])
		max=right;
		
	if(max != pos)
	{
		iSwap(a, max, pos);
		maxHeapify(a, hSize, max);
	}
}

void upFloat(int a[], int pos)
{
	int par=pos/2;
	
	if(a[pos] > a[par] && (par >=1))
	{	
		iSwap(a, pos, par);
		upFloat(a, par);
	}
}


void buildMaxheap(int a[], int aSize)
{
	int i, j, k;
	
	for(i=2; i<=aSize; i++)
	{
		upFloat(a, i);
	}
}


int showMax(int a[])
{
	return a[1];
}

int extractMax(int a[])
{
	if (number <1) 
	{
		printf("\nUnderflow ");
		return -1;
	}
	int temp;
	temp=a[1];
	iSwap(a, number, 1);
	a[number]=-9999;
	number--;
	maxHeapify(a, number, 1);
	return temp;
}


void insert(int a[], int info)
{
	number++;
	a[number]=info;
	upFloat(a, number);
	
}


updateKey(int a[], int pos, int inf)
{
	if(a[pos]> inf)
	{
		a[pos]=inf;
		maxHeapify(a, number, pos);
	}
	else
	{
		a[pos]=inf;
		upFloat(a,pos);
	}
}


void disp(int a[])
{
	int i;
	printf("\n\n");
	for(i=1; i<=number; i++)
		printf("  %d  ",a[i]);
}




int main()
{
	int a[200], n, i, m, key;
	
	printf("\nEnter the number of elements ");
	scanf("%d",&n);
	number=n;
	
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	buildMaxheap(a, n);
	
	printf("\nEnter choice \n1.see max\n2.extract max\n3.insert\n4.Show\n5.update\n6.Exit   ");
	while(1)
	{
		printf("\nEnter  ");
		scanf("%d",&i);
		
		switch(i)
		{
			case 1:
				printf("\n Max is %d \n ",showMax(a));
				break;
			case 2:
				printf("\nMax extracted %d \n",extractMax(a));
				break;
			case 3:
				printf("\nEnter the node to insert ");
				scanf("%d",&m);
				insert(a, m);
				break;
			case 4:
				disp(a);
				break;
			case 5:
				printf("\nEnter which node to update ");
				scanf("%d",&m);
				printf("\nEnter what key to update with ");
				scanf("%d",&key);
				updateKey(a, m, key);
				break;
			case 6:
				return(0);
		}
	}
}

