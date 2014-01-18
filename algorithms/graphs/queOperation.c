#define MAXS 50

#include <stdio.h>

static int que[MAXS], front=0, rear=0;

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

