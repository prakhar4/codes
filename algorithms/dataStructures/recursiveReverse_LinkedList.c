/*
	to reverse a singly linked list recursively
*/

#include<stdio.h>
#include<stdlib.h>

struct list
{
	int info;
	struct list *next;
};
typedef struct list node;

node* top=NULL;

node* rev(node *this)
{
	node* ret=NULL;
	if(this->next==NULL)
	{
		top=this;
		return this;
	}
		
	ret=rev(this->next);
	ret->next=this;
	return this;
}

int main()
{
	int i,j,n;
	int ch,tem,temp;
	
	node  *ptr=NULL;
	
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
				for(ptr=top;ptr!=NULL;ptr=ptr->next)
				{	printf("\n");
					printf("  %d ",ptr->info);
				}	break;
					
			case 3:
				ptr=rev(top);
				ptr->next=NULL;
				printf("\nReversed ");
				break;
		
			
						
			case 4:
				printf("\nABORTING!!");
				exit(0);		
				
			default:
				printf("\nInvalid!!!");
				break;
		}
	}
	return 0;
}
