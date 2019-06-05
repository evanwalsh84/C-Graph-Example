// CSCI 3300
// Assignment: 5A
// Author:     Evan Walsh
// File:       graph.cpp
// Tab stops:  2

/* **,**
*/
#include <cstdio>
#include "equiv.h"
//=============================================================
//								Edge
//=============================================================
struct Edge
{
	int vertexloc;
	int vertexdest;
	double vertexweight;
	Edge* next;

	Edge(int vloc, int vdest, double vweight, Edge* e)
	{
		vertexloc = vloc;
		vertexdest = vdest;
		vertexweight = vweight;
		next = e;
	}
}; 
//=============================================================
//								Vertex
//=============================================================
struct Vertex
{
	double distance;
	int nextVertex;
	bool signaled; 
	Edge* edge;
}; 
//=============================================================
//								Graph
//=============================================================
struct Graph
  {
    int     numVertices;
    Vertex* vertexInfo;

    Graph(int n)
    {
      numVertices = n;
      vertexInfo  = new Vertex[n+1];
      for(int i = 1; i <= n; i++)
      {
        vertexInfo[i].signaled = false;
	vertexInfo[i].distance = -1;
	vertexInfo[i].nextVertex = -1;
	vertexInfo[i].edge = NULL;
      }
    }
  };
//=============================================================
//								vertinput
//=============================================================
int vertinput()
{
	int vertices;
	vertices = 0;
	printf("Enter the number of vertices");
	scanf("%i", &vertices);
	return vertices;
}

//=============================================================
//							insertedge
//=============================================================
void insertedge(int loc, int dest, double weight, Edge*& x)
{
   if(x == NULL)
   {  
   x = new Edge(loc, dest, weight, NULL);
   }
   else
   {
    insertedge(loc, dest, weight, x -> next);
   }
}
//=============================================================
//								input
//=============================================================
void input(Graph* g)
{
	int loc, dest;
	double weight;
	printf("Enter the location of the edge");
	scanf("%i" , &loc);
	if(loc != 0)

	{
		printf("Enter the destination of the vertex.");
		scanf("%i", &dest);
		printf("Enter the weight of the vertex.");
		scanf("%lf", &weight);

		insertedge(loc, dest, weight, g -> vertexInfo[loc].edge);
		insertedge(dest, loc, weight, g -> vertexInfo[dest].edge);

		input(g);
	}
}
//=============================================================
//							printvert
//=============================================================
void printvert(Graph* g, int size)
{
	for (int i = 1; i <= size; i++)
	{

		for (Edge* count = g -> vertexInfo[i].edge; count != NULL; count = count -> next)
		{// CSCI 3300
// Assignment: 5A
// Author:     Evan Walsh
// File:       graph.cpp
// Tab stops:  2

/* **,**
*/
#include <cstdio>
//=============================================================
//								Edge
//=============================================================
struct Edge
{
	int vertexloc;
	int vertexdest;
	double vertexweight;
	Edge* next;

	Edge(int vloc, int vdest, double vweight, Edge* e)
	{
		vertexloc = vloc;
		vertexdest = vdest;
		vertexweight = vweight;
		next = e;
	}
}; 
//=============================================================
//								Vertex
//=============================================================
struct Vertex
{
	double distance;
	int nextVertex;
	bool signaled; 
	Edge* edge;
}; 
//=============================================================
//								Graph
//=============================================================
struct Graph
  {
    int     numVertices;
    Vertex* vertexInfo;

    Graph(int n)
    {
      numVertices = n;
      vertexInfo  = new Vertex[n+1];
      for(int i = 1; i <= n; i++)
      {
        vertexInfo[i].signaled = false;
	vertexInfo[i].distance = -1;
	vertexInfo[i].nextVertex = -1;
	vertexInfo[i].edge = NULL;
      }
    }
  };
//=============================================================
//								vertinput
//=============================================================
int vertinput()
{
	int vertices;
	vertices = 0;
	printf("Enter the number of vertices");
	scanf("%i", &vertices);
	return vertices;
}

//=============================================================
//							insertedge
//=============================================================
void insertedge(int loc, int dest, double weight, Edge*& x)
{
   if(x == NULL)
   {  
   x = new Edge(loc, dest, weight, NULL);
   }
   else
   {
    insertedge(loc, dest, weight, x -> next);
   }
}
//=============================================================
//								input
//=============================================================
void input(Graph* g)
{
	int loc, dest;
	double weight;
	printf("Enter the location of the edge");
	scanf("%i" , &loc);
	if(loc != 0)

	{
		printf("Enter the destination of the vertex.");
		scanf("%i", &dest);
		printf("Enter the weight of the vertex.");
		scanf("%lf", &weight);

		insertedge(loc, dest, weight, g -> vertexInfo[loc].edge);
		insertedge(dest, loc, weight, g -> vertexInfo[dest].edge);

		input(g);
	}
}
//=============================================================
//							printvert
//=============================================================
void printvert(Graph* g, int size)
{
	for (int i = 1; i <= size; i++)
	{

		for (Edge* count = g -> vertexInfo[i].edge; count != NULL; count = count -> next)
		{

			if (count -> vertexloc < count -> vertexdest)
			{
				printf("(%i, %i) weight %5.2lf\n", count -> vertexloc, count -> vertexdest, count-> vertexweight);
			}
		}
	}
}


//=============================================================
//							Main							
//=============================================================
int main()
{
	int x = vertinput();
	Graph* g = new Graph(x);
	input(g);
	//start = journeystart();
	//stop = journeyend();
	printvert(g, x);
	return 0;
}

			if (count -> vertexloc < count -> vertexdest)
			{
				printf("(%i, %i) weight %5.2lf\n", count -> vertexloc, count -> vertexdest, count-> vertexweight);
			}
		}
	}
}


//=============================================================
//							Main							
//=============================================================
int main()
{
	int x = vertinput();
	Graph* g = new Graph(x);
	input(g);
	//start = journeystart();
	//stop = journeyend();
	printvert(g, x);
	return 0;
}
