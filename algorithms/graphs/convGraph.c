#define MAXS 100

#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"

//n is number of vertices in matrix
//matrix starts from 1...n not from 0..

node* convMat2List(int mat[][MAXS], int n)
{
	node *adj;
	adj=(node*)calloc(n,sizeof(node));	//array
	node *ptr=NULL;
	int i,j;
	
	
	for(i=1;i<=n;i++)
	{
/*		adj[i]=(node*)malloc(sizeof(node));	*/
		adj[i].u=i;
		adj[i].next=NULL;
		
		for(j=1;j<=n;j++)
		{
			if(mat[i][j]==1)
			{
				ptr=(node*)malloc(sizeof(node));
				ptr->u=j;
				ptr->next=adj[i].next;
				adj[i].next=ptr;
			}
		}
	}
	return adj;
}
