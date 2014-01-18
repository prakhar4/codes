/*
	to create a binary tree with insertion
*/

#include<stdio.h>
#include<stdlib.h>
struct nodes
{
	int info;
	struct nodes *parent;
	struct nodes *right;
	struct nodes *left; 
};
typedef struct nodes node;

node *root=NULL;

static int cc;

insert(node *now)
{
	node *le, *ri;

	int in;
	
	printf("\nEnter left info for %d node ",cc+1);
	scanf("%d",&in);
	if(in==-1)
		now->left=NULL;
	else
	{	
		now->left=(node*)malloc(sizeof(node));
		cc++;
		now->left->info=in;
		now->left->parent=now;
		now->left->left=NULL;
		now->left->right=NULL;
		//now->left=le;
	}
	
	printf("\nEnter righ info for %d node ",cc+1);
	scanf("%d",&in);
	if(in==-1)
		now->right=NULL;
	else
	{	
		ri=(node*)malloc(sizeof(node));
		cc++;
		ri->info=in;
		ri->parent=now;
		ri->left=NULL;
		ri->right=NULL;
		now->right=ri;
	}
	
	if(now->left!=NULL)
	{		
		printf("\nEnter left of %d node ",cc);
		insert(now->left);
	}
	if(now->right!=NULL)
	{
		printf("\nEnter right of %d node ",cc);
		insert(now->right);
	}
}

assignRoot()
{
	node* ptr;
	ptr=(node*)malloc(sizeof(node));
	int in;
	cc++;
	root=ptr;
	printf("\nEnter root val ");
	scanf("%d",&in);
	ptr->parent=NULL;
	ptr->info=in;
	insert(root);
}

view(node* now)
{
	if(now==NULL)
		return;
	printf("\n  %d",now->info);
	view(now->left);
	view(now->right);
}



main()
{
	assignRoot();
	view(root);
}

