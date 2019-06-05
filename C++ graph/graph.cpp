// CSCI 3300
// Assignment: 7A
// Author:     Evan Walsh
// File:       graph.cpp
// Tab stops:  8

/* **,**
*/
#include <cstdio>
#include "equiv.h"
#include "graph.h"
#include <cstdlib>

typedef int (*QSORT_COMPARE_TYPE)(const void*, const void*);

//=============================================================
//			insertedge
//=============================================================
//insert edge calls upon the structure of edge and provides the necessary
//information for the location, destination, and weight of the edge.
//=============================================================
void insertedge(Graph* g, int loc, int dest, double weight)
{
	Edge x = Edge(loc, dest, weight);
	//printf("numEdges = %i \n", g -> numEdges);
	g -> edge[g -> numEdges] = x;
	g -> numEdges++;
}

//=============================================================
//			input
//=============================================================

Graph* input()
{
	int loc, dest, numvert;
	double weight;
	printf("Enter the number of the vertices ");
	scanf("%i", &numvert);
	Graph* g = new Graph(numvert);	
	
	scanf("%i" , &loc);
	while(loc != 0)
	{
		scanf("%i", &dest);
		scanf("%lf", &weight);
		insertedge(g, loc, dest, weight);
		//printf("numEdges = %i \n", g -> numEdges);
		scanf("%i" , &loc);
	}
	return g;
}

//=============================================================
//			printvert
//=============================================================

void printvert(Graph* g)
{
	for(int i = 1; i < g -> numEdges; i++)
	{
		printf("%i   %i           %i\n", g->edge[i].vertexloc, g->edge[i].vertexdest, g->edge[i].vertexweight);			
	}
}

//=============================================================
//			totalweight
//=============================================================

int totalweight(Graph* g)
{
	int y = 0;
	for(int x = 1; x < g->numEdges; x++)
	{
		y += g->edge[x].vertexweight;
	}
  return y;
}

//=============================================================
//			compareEdges
//=============================================================

int compareEdges(const Edge* A, const Edge* B)
{
  return A->vertexweight - B->vertexweight;
}
  
//=============================================================
//			krusk
//=============================================================

Graph* krusk(Graph* g)
{
  Equiv e(g->numVertices);
  Graph* r = new Graph(g-> numVertices);	
  qsort((void*) g-> edge, g-> numEdges, sizeof(Edge), (QSORT_COMPARE_TYPE) compareEdges);
  
  for(int i = 1; i < g-> numEdges; i++)
  {
    if(!together(e, g-> edge[i].vertexloc, g-> edge[i].vertexdest))
    {
  	  insertedge(r, g-> edge[i].vertexloc, g-> edge[i].vertexdest, g-> edge[i].vertexweight);
  	  combine(e, g-> edge[i].vertexloc, g-> edge[i].vertexdest);
    }
  }
  return r;
}







