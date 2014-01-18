/*
	to implement a basic queue in arrays 
	to allow the circular usage of free memory	

	IMP - array of size n would store only n-1
		  elements
*/
#include<stdlib.h>
#include<stdio.h>
#define MAXS 5

int que[MAXS], front=0, rear=0;

void enque(int in)
{
	if(((rear+1)%MAXS)==front)
	{
		printf("\nQue Full");
		return;
	}
	else
	{
		que[rear]=in;
		rear++;
		rear%=MAXS;
		return;
	}
}

int deque()
{
	int i=que[front];
	if(front==rear)
	{
		printf("\nQue empty");
		return -1;
	}
	else
	{
		front++;
		front%=MAXS;
		return i;
	}
}

void view()
{
	int i;
	printf("\n");
	for(i=front;i!=rear;i=((i+1)%MAXS))
		printf("  %d ",que[i]);

}

void main()
{
	int ch;
	printf("\n1.Enque\n2.Deque\n3.View\n4.Exit");
	while(1)
	{
		printf("\nEnter choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			default:
				printf("\nEnter again ");
				break;
			
			case 2:
				printf("\ndeleted %d ",deque());
				break;
			
			case 4:
				printf("\nAborting");
				exit(0);			
				
			case 1:
				printf("\nEnter value ");
				scanf("%d",&ch);
				enque(ch);
				break;
		
			case 3:
				view();
		}
	}
}
