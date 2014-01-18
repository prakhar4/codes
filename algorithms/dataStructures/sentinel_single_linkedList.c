/*
	using SENTINELS
	implement stack operations using 
	singly LL and the push pop in O(1)
*/



#include<stdio.h>
#include<stdlib.h>

struct list
{
	int info;
	struct list *next;
};
typedef struct list node;

node senti;

void push()
{
	int n;
	node *ptr=NULL;
	printf("\nEnter value ");
	scanf("%d",&n);
	
	ptr=(node*)malloc(sizeof(node));
	ptr->info=n;
	ptr->next=NULL;
	
	
	ptr->next=senti.next;
	senti.next=ptr;
}

void pop()
{
	if(senti.next==&senti)
		return;
	senti.next=senti.next->next;
	return;
}


node* search(int key)
{
	senti.info=key;
	node *tem=senti.next;
	
	while(tem->info!=key)
		tem=tem->next;
		
	if(tem==&senti)
		return NULL;
	else
		return tem;
}


int main()
{
	int i,j,n;
	int ch,tem,temp;
	
	node *ptr=NULL;
	senti.next=&senti;
	printf("\nthe key for senti %d",senti.info);
	
	
	printf("\n1.PUSH\n2.POP\n3.View\n4.Search \n5.Exit");
	
	while(1)
	{
		printf("\nEnter chioce  ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	
				push();
				break;
				
			case 3:
				for(ptr=senti.next;ptr!=&senti;ptr=ptr->next)
				{	printf("\n");
					printf("  %d ",ptr->info);
				}	break;
					
			case 2:
				pop();	
				break;

			default:
				printf("\nInvalid!!!");

			case 5:
				printf("\nABORTING!!");
				exit(0);
				
			case 4:
				printf("\nEnter the key to search ");
				scanf("%d",&n);
				ptr=search(n);
				if(ptr==NULL)
					printf("\nnot found ");
				else
					printf("\nfound %d ",ptr->info);
				break;		
		}
	}
}

