/*
	to define the basic structure of a vertex in 
	the graph, and have all its attributes
*/

#ifndef _vertex_

#define _vertex_  

struct nodes
{
	int u;		//vertex no
	int clr;	//color flag
	int dis;	//distance from src
	struct nodes *next;
	struct nodes *par;		//parent
};

typedef struct nodes node;

#endif  		//end vertex.h file
