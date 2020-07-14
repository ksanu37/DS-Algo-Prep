/* Union Find algorithm --> To detect cycle in an undirected graph with no self-loop 

Using disjoing set data structure --> Disjoint set Data structure --> Keeps track of a set of elements partitioned into a number of disjoint
or non-overlapping subsets 

Here we take a 1D array named parent to keep track of elements in subsets */

#include<bits/stdc++.h>
using namespace std;


/* A class to represent edge in a graph */
class Edge{
	public:
	int src, dest;
};

class Graph{
	public:
		int V;  // Number of vertices
		int E;  // Number of Edges
		Edge* edge;  // An array pointer to maintain the list of edges
};

Graph* createGraph(int V, int E){
	Graph *graph = new Graph();
	graph->V = V;
	graph->E = E;
	graph->	edge = new Edge[E*sizeof(Edge)];
	
	return graph;
}

/* A method to find the parent of the node i i.e: the subset which i belongs to */
int find(int parent[], int i){
	if(parent[i]==-1)
		return i;
		
		return find(parent, parent[i]);
}

/* A function to do union of two subsets, if two nodes have an edge between them but they are found in two different subsets, these subsets are to be joined */
void union(int parent[], int x, int y){
	int xset = find(parent,x);
	int yset = find(parent,y);
	
	if(xset != yset){
		parent[xset] = yset;
	}
}
/* The main function to check whether a graph is cyclic or not */
bool isCyclic(Graph * graph){
	int *parent = new int[graph->V* sizeof(int)];
	memset(parent,-1,sizeof(int)*graph->V);   // Initially all the nodes are assumed to be in different subsets
	
	for(int i=0; i<graph->E; i++){
		/* Find the parents(subsets) of the two nodes in the edge */
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);
		
		if(x==y)
			return true;
		union(parent, x, y);
	}
	
	return false;
}


int main(){
	int V = 3, E = 3;
	Grapgh* graph = createGraph(V,E);
	
	// add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
  
    // add edge 1-2  
    graph->edge[1].src = 1;  
    graph->edge[1].dest = 2;  
  
    // add edge 0-2  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 2;  
  
    if (isCyclic(graph))  
        cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";  
  
    return 0; 	
	
}
