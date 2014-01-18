/*
	to implement bfs for a graph input in 2d matrix
	each vertex is depicted as an integer
	alg-
		shift matrix - to start with 1
		convert it to adjList
		use Enque Deque
*/

#include <stdio.h>
#include "vertex.h"
#include "univInclude.h"

#define INFI 99999
#define MAXS 100

#define WHITE 0
#define BLACK 1

node* convMat2List(int mat[][MAXS], int n);

/*static int srcDis=0;*/

//traversal Adj List completely
int disp_adjList(node* adjList, int vSize)
{
	int i;
	node *tem;
	for(i=1;i<=vSize;i++)
	{
		printf("vertex -%d->   ",adjList[i].u);
		
	 	for(tem=adjList[i].next;tem!=NULL;tem=tem->next)
			printf("\t%d",tem->u);
		
		printf("\n");
	}
	return 0;
}




void intialiseBFS(node *adjList, int vSize)
{
	int i;
	for(i=1;i<=vSize;i++)
	{
		adjList[i].clr=WHITE;
		adjList[i].par=NULL;
		adjList[i].dis=INFI;
	}
	return;
}


node* bfs(int mat[][MAXS], int vSize)
{
	shiftMatrix(mat,vSize);
	node *adjList=convMat2List(mat,vSize);
	node *temp=NULL;
	disp_adjList(adjList,vSize);
	
	int src;
	int cr;		//current
	printf("\nEnter the source vertex ");
	scanf("%d",&src);
	
	intialiseBFS(adjList,vSize);
	disp_adjList(adjList,vSize);
	
	enque(src);
	adjList[src].clr=BLACK;
	adjList[src].par=NULL;
	adjList[src].dis=0;
		
		
	while((cr=deque())!=-1)
	{
		printf("\nDequed %d ",cr);
		printf("\nDequed %d ",cr);
		//for each adjacent
		temp=adjList[cr].next;
		for(;temp!=NULL;temp=temp->next)
		{
			printf("\nRunning for loop %d",temp->u);
			printf("\nRunning for loop %d",temp->u);
			
			if(adjList[temp->u].clr==WHITE)
			{
				enque(temp->u);
				adjList[temp->u].clr=BLACK;
				adjList[temp->u].par=&adjList[cr];
				adjList[temp->u].dis=adjList[cr].dis+1;
				printf("\nEnqued %d ",temp->u);
				printf("\nEnqued %d ",temp->u);	
			}
		}
	}
	return adjList;
}

/*
dispBFS(node* adjList)
{
	enque(adjList->u);
	node *temp;
	int i;
	
	while((i=deque())!=-1)
	{
		printf("\n");
		
		temp=adjList->
	}
}*/

int dispPath(int u, int v, node* adjList)
{
	if(u==v)
		printf("\n %d ",u);
	else if(adjList[v].par==NULL)
		printf("\nNo path exists ");
	else 
		dispPath(u,(adjList[v].par)->u,adjList);
	
	printf("\n %d ",v);
	return 0;
}

int main()
{
	int adjMat[MAXS][MAXS]={{1,0,0,0,0,0,0,0,0,0},
							{0,0,1,0,0,1,0,0,0,0},
							{0,1,0,0,0,0,1,0,0,0},
							{0,0,0,0,1,0,1,1,0,0},
							{0,0,0,1,0,0,0,1,1,0},
							{0,1,0,0,0,0,0,0,0,0},
							{0,0,1,1,0,0,0,1,0,0},
							{0,0,0,1,1,0,1,0,1,0},
							{0,0,0,0,1,0,0,0,1,0}};

	int vSize;
	
	printf("\nEnter the vertex number ");
	scanf("%d",&vSize);
	
	node* adjList=bfs(adjMat,vSize);
	
	int u,v;
	
	while(1)
	{
		printf("\nEnter both vertices ");
		scanf("%d %d",&u,&v);
		dispPath(u,v,adjList);
	}
}

/*   1,2,3,4,5,6,7,8,9*/
/*1 {1,0,0,0,0,0,0,0,0,0},*/
/*2 {0,0,1,0,0,1,0,0,0,0},*/
/*3 {0,1,0,0,0,0,1,0,0,0},*/
/*4 {0,0,0,0,1,0,1,1,0,0},*/
/*5 {0,0,0,1,0,0,0,1,1,0},*/
/*6 {0,1,0,0,0,0,0,0,0,0},*/
/*7 {0,0,1,1,0,0,0,1,0,0},*/
/*8 {0,0,0,1,1,0,1,0,1,0},*/
/*9 {0,0,0,0,1,0,0,0,1,0}*/




