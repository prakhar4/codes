/*
	CHECK CHECK
	NOT ABLE TO COMPILE TOGETHER WITH OTHER FILE
	NOT ABLE TO USE - * OPERATOR

	using the stk data structure for inorder
	traversal and avoiding recurssion
*/
#include<stdio.h>
#define MAXS 30
//typedef struct trees node;

node* stk[MAXS];
int top;

void push(node* info)
{
	stk[top++]=info;
	return;
}

node* pop()
{
	if(top==0)
		return NULL;
	return stk[--top];
}


void inorderNonRec(node* root)
{
	node *tem=NULL, *ptr=NULL;
	push(root);
	
	while(top!=0)
	{
		ptr=pop();
		if(ptr==NULL)
			continue;
		if(ptr->flg=='y')	
		{
			printf("\n  %d  ",ptr->key);
			continue;
		}
		ptr->flg='y';
		push(ptr->right);
		push(ptr);
		push(ptr->left);	
	
	}

}
