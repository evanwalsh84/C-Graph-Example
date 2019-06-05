/* **,**
*/

const int MAX_EDGES = 100;

//=============================================================
//				Edge
//=============================================================
//Struct Edge creates a structure for an edge that takes in the location
// of the edge and the destination to which it is connected with a weight
// for priority.
//=============================================================
struct Edge
{
	int vertexloc;
	int vertexdest;
	double vertexweight;

	Edge(int vloc, int vdest, double vweight)
	{
		vertexloc = vloc;
		vertexdest = vdest;
		vertexweight = vweight;
	}
	
	Edge()
	{
		vertexloc = -1;
		vertexdest = -1;
		vertexweight = -1;
	}

}; 
//=============================================================
//				Graph
//=============================================================
// Creates a structure for the graph that takes in the number of vertices
// contained in the graph and the number of edges.
//=============================================================
struct Graph
  {
    int     numVertices;
    int     numEdges;
    Edge*   edge;

    Graph(int n)
    {
      numVertices = n;
      numEdges = 1;
      edge = new Edge[MAX_EDGES+1];
    }
  };
  
//=============================================================
//				input
//=============================================================
//Input builds a graph as the input continues to provide a location
//for each edge above the number zero.
//=============================================================
Graph* input();

//=============================================================
//				printvert
//=============================================================
//printvert prints all vertices contained withing the graph
//along with the weight and destination.
//=============================================================
void printvert(Graph* g);

//=============================================================
//				totalweight
//=============================================================
//totalweight adds all theweights of each vertex together and 
//returns the number they equal.
//=============================================================
int totalweight(Graph* g);

//=============================================================
//				krusk
//=============================================================
//krusk implements the Kruskal's algorithm on a currently existing
//graph and returns the finished product.
//=============================================================
Graph* krusk(Graph* g);






