/*
	to implement a stack operations by 2 queues

	RESULTS N CONCLU-
		CANNOT DIRECTLY COMPARE TWO STRUCTURES
		LIKE q1==q2
		
	we can also not just try assigning q=*head
	this does not work
	
	USE POINTERS when want to work with
	references n try avoiding with the variable
	names like q1 q2 rather use head=&q1 

*/

#include<stdlib.h>
#include<stdio.h>
#define MAXS 10

struct queue
{
	int que[MAXS];
	int front;
	int rear;
};
typedef struct queue Q;

static Q q1,q2;
static Q* head;

void enque(int in, Q* q)
{
	if(((q->rear+1)%MAXS)==q->front)
	{
		printf("\nStk Full");
		return;
	}
	else
	{
		q->que[q->rear]=in;
		q->rear++;
		printf("\nfront %d  end  %d ",q->front,q->rear);
		q->rear%=MAXS;
		return;
	}
}

int deque(Q* q)
{
	int i=q->que[q->front];
	if(q->front==q->rear)
	{
		printf("\nQue empty");
		return -1;
	}
	else
	{
		q->front++;
		q->front%=MAXS;
		return i;
	}
}

void view(Q* q)
{
	int i;
	printf("\n");
	for(i=q->front;i!=q->rear;i=((i+1)%MAXS))
		printf("  %d ",q->que[i]);
}


swapQ()
{
	if(head==(&q1))
		head=&q2;
	else
		head=&q1;
}

push()
{
	int ch;
	printf("\nEnter value ");
	scanf("%d",&ch);
	enque(ch,head);		
}

pop()
{
	int tem,temp=0;
	temp=deque(head);
	while((tem=deque(head))!=-1)
	{
		swapQ();
		enque(temp,head);
		swapQ();
		temp=tem;		
	}
	swapQ();
	return temp;
}


void main()
{
	head=&q1;
	int ch;
	printf("\n1.PUSH\n2.POP\n3.View\n4.Exit");
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
				printf("\ndeleted %d ",pop());
				break;
			
			case 4:
				printf("\nAborting");
				exit(0);			
				
			case 1:
				push();
				break;
		
			case 3:
				view(head);
		}
	}
}
