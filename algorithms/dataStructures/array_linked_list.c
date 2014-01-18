/*
	to implement a doubly linked list by using 
	3 arrays
	first initialising the array next n prev with
	random values
*/

#include<stdio.h>
#define MAXS 17

int a[MAXS];
int next[MAXS], prev[MAXS], flg[MAXS];

void initialise()
{
	int cc=0;
	int now=0, nxt;
	int nowpre=-1;
	flg[0]=1;
	
	while(cc<MAXS-1)
	{
		nxt=(rand()%MAXS);
		if(flg[nxt])
			continue;
		flg[nxt]=1;
		
		next[now]=nxt;
		prev[now]=nowpre;

		nowpre=now;		
		now=nxt;
		
		cc++;
	}
	next[now]=-1;
	prev[now]=nowpre;
	
}


void main()
{
	int i;
	printf("\n");
	
	initialise();
	
	for(i=0;i<MAXS;i++)
		printf(" %d ",next[i]);

	
	printf("\n");
	
	for(i=0;i<MAXS;i++)
		printf(" %d ",prev[i]);

}
