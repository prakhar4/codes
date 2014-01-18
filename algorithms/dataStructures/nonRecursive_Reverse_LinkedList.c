/*
	to reverse a singly linked list in time order - n 
	where n is number of elements
	without recurrsions
	using only a constant amount of memory
*/

#include<stdio.h>
#include<stdlib.h>

struct list
{
	int info;
	struct list *next;
};
typedef struct list node;


node* rev(node *top)
{
	node *now=top, *pre=NULL, *post=top->next;
	
	while(now!=NULL)
	{
		now->next=pre;
		pre=now;
		now=post;
		if(post!=NULL)
			post=post->next;
	}	
	return pre;
}

main()
{
	int i,j,n;
	int ch,tem,temp;
	
	node *top=NULL, *ptr=NULL, *tptr=NULL;
	
	printf("\n1.Insert \n2.View \n3.Reverse  \n4.Exit");
	
	while(1)
	{
		printf("\nEnter chioce  ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	
				printf("\nEnter value ");
				scanf("%d",&n);
				
				ptr=(node*)malloc(sizeof(node));
				ptr->info=n;
				ptr->next=NULL;
				
				ptr->next=top;
				top=ptr;
				break;
				
			case 2:
				for(tptr=top; tptr!=NULL; tptr=tptr->next)
				{	printf("\n");
					printf("   %d  ",tptr->info);
				}	break;
					
			case 3:
				top=rev(top);
				printf("\nReversed ");
				break;
		
			default:
				printf("\nInvalid!!!");
		
			case 4:
				printf("\nABORTING!!");
				exit(0);		
		}
	}
}
