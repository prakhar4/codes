/*
	to insert into binary search trees
*/

#include<stdio.h>
#include<stdlib.h>
//void inorderNonRec(node*);
#define MAXS 50
struct trees 
{
	int key;
	char flg;
	struct trees *parent, *left, *right;
};
typedef struct trees node;


//obsolete recursive 
/*
insert(node* now, int k)
{
	int i,j,n;
	
	if(k<=now->key && now->left==NULL)
	{
		now->left=(node*)malloc(sizeof(node));
		now->left->key=k;
		now->left->flg='n';
		now->left->parent=now;
		now->left->right=NULL;
		now->left->left=NULL;
		return;
	}
	else if(k>now->key && now->right==NULL)
	{
		now->right=(node*)malloc(sizeof(node));
		now->right->key=k;
		now->right->flg='n';
		now->right->parent=now;
		now->right->right=NULL;
		now->right->left=NULL;
		return;
	}
	
	if(k<=now->key)
		insert(now->left,k);
	else
		insert(now->right,k);

}
*/


view(node* now)
{
	if(now==NULL)
		return;
	view(now->left);
	printf("\n %d  ",now->key);
	view(now->right);
}

node* treeMin(node *ptr)
{
	while(ptr->left!=NULL)
		ptr=ptr->left;
	return ptr;			//->key;
}


int treeMax(node* ptr)
{
	while(ptr->right !=NULL)
		ptr=ptr->right;
	return ptr->key;
}

int recMax(node* now)	//recursive max
{
	if(now->right==NULL)
		return now->key;
	
	return recMax(now->right);
}

node* successor(node *ptr, int k)
{
	while(ptr!=NULL && ptr->key!=k)
	{
		if(k<ptr->key)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}

	if(ptr==NULL)
		return NULL;				//-1;

	if(ptr->right!=NULL)
		return treeMin(ptr->right);
	else
	{
		node *tem=ptr->parent;
		while(tem!=NULL && tem->left!=ptr)
		{
			ptr=tem;
			tem=tem->parent;
		}
		//if(tem!=NULL)
			return tem;      //->key;		
	}
	//return -1;
}


int predecesor(node* ptr, int k)
{
	while(ptr!=NULL && ptr->key!=k)
	{
		if(ptr->key<k)
			ptr=ptr->right;
		else
			ptr=ptr->left;
	}	
	if(ptr==NULL)
	{
		printf("\nINVALID KEY!");
		return -1;
	}
	else
	{
		if(ptr->left!=NULL)
			return treeMax(ptr->left);
		else
		{
			node* tem=ptr->parent;
			while(tem!=NULL && tem->right!=ptr)
			{
				ptr=tem;
				tem=ptr->parent;
			}
			if(tem!=NULL)
				return tem->key;
		}
	}	
	return -1;	
}



/*******************************************
********************************************

FOR NON RECURSIVE INORDER TRAVERSAL
*/
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



//FIXME TODO 
// try to remove the flg from each node
//as only execution once is working

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
			printf("\nNC  %d  ",ptr->key);
			continue;
		}
		ptr->flg='y';
		push(ptr->right);
		push(ptr);
		push(ptr->left);	
	
	}

}


/*
*******************************************
******************************************/


/////////////////////////////////////////
//	INSERT FUNC WITHOUT RECURRSION
/*
insert(node* now, node** root)
{
	node* ptr= (*root);
	node *tem=NULL;
	if(ptr==NULL)
	{
		*root=now;
		return;
	}
	
	while(ptr!=NULL)
	{
		tem=ptr;
		if(now->key <= ptr->key)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}
	now->parent=tem;     		//IMP
	if(now->key <= tem->key)
		tem->left=now;
	else
		tem->right=now;
}
*/


//BETTER RECURSIVE PROCEDURE

insert(node *now, node *pre, node **par)
{
	if(*par==NULL)
	{
		*par=now;
		now->parent=pre;
	}
	else if(now->key <= (*par)->key)
		insert(now,*par,&((*par)->left));
	else
		insert(now,*par,&((*par)->right));
	return;
}


node* search(int k, node* root)
{
	while(root!=NULL && root->key!=k)
		if(root->key < k)
			root=root->right;
		else
			root=root->left;

	return root;
}



//transplants subtree rooted at u with 
//subtree rooted at v

transplant(node **root, node *u, node *v)
{
	if(u->parent==NULL)
		*root=v;	
	else if(u->parent->left==u)
		u->parent->left=v;
	else
		u->parent->right=v;
	
	if(v!=NULL)
		v->parent=u->parent;
}






node* delete(int k, node** root)
{
	node *ptr=search(k,*root);
	if(ptr==NULL)
	{
		printf("\nInvalid input!");
		return *root ;
	}
	if(ptr->left==NULL)
		transplant(root, ptr, ptr->right);
	else if(ptr->right==NULL)
		transplant(root, ptr, ptr->left);
	else
	{
		node *tem=successor(ptr,(ptr->key));
		if(tem!=ptr->right)
		{
			transplant(root,tem,tem->right);
			tem->right=ptr->right;
			tem->right->parent=tem;
		}
		transplant(root,ptr,tem);
		tem->left=ptr->left;
		tem->left->parent=tem;
	}
	
	
	return ptr;
}







void main()
{
	node *root=NULL, *ptr=NULL, *tem=NULL;
	int i,j,n,ch;
	printf("\n1.Insert\n2.View\n3.Max\n4.Min\n5.Successor\n6.Predecesor\n7.Delete ");
	while(1)
	{
		printf(" Enter choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter Key ");
				scanf("%d",&ch);
				node *ptr=(node*)malloc(sizeof(node));
				ptr->key=ch;
				ptr->parent=NULL;
				ptr->left=NULL;
				ptr->right=NULL;
				ptr->flg='n';
				//insert(ptr,&root); FOR NON-REC
				insert(ptr,root,&root);
				break;
			case 2:	
				view(root);
				//inorderNonRec(root);
				break;
			case 3:
				printf("\nThe max value %d  ",recMax(root));
				break;
				
			case 4:
				printf("\nThe min value %d  ",treeMin(root)->key);
				break;
			
			case 5:
				printf("\nEnter key for sucr ");
				scanf("%d",&ch);
				printf("\nits %d ",(successor(root,ch))->key);
				break;

			case 6:
				printf("\nEnter key for pred ");
				scanf("%d",&ch);
				printf("\npre is %d ",predecesor(root,ch));
				break;
				
			case 7:
				printf("\nKey to delete ");
				scanf("%d",&ch);
				printf("\nDeleted  %d",(delete(ch,&root))->key);
				break;
		}
	}

	printf("\n");
}
