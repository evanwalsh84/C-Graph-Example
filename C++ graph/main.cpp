// CSCI 3300
// Assignment: 7A
// Author:     Evan Walsh
// File:       main
// Tab stops:  8

#include <cstdio>
#include "graph.h"

int main()
{
  Graph* g = input();
  printf("The input graph has %i vertices, and its edges are as follows.\n", g->numVertices);
  printvert(g);
  
  Graph* r = krusk(g);
  printf("A minimal spanning tree uses the following edges.\n");
  printvert(r);
  
  printf("The total weight of the spanning tree is %i.\n", totalweight(r));
  
  return 0;
}
