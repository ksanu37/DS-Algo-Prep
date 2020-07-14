/* 

Shortest Path Algorithms: Dijkstra's algorithm

An algorithm to get the shortest path from a source vertex to all the other vertices in the graph
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

The idea:  Greedy Approach

Maintain an included and a distance array/vector

Initially, all vertices are not included and all distances are set to Max

Now, we set the source distance to 0

In a loop, until all the vertices are not included, we 
1. extract the vertex with the least distance
2. Include it in the included vector
3. Update all the distances (of not included nodes) relative to this vertex

Time Complexity: Adjacency Matrix Representation O(V^2)

1. This does not work for negative weights
2. This finds all shortest paths from a source to all the vertices
3. To print the Shortest Path, we maintain a parent array. parent of the source is set to -1

*/





#include<bits/stdc++.h>
using namespace std;

#define V 9

void printPath(vector<int>&parent, int src){
	if(parent[src]==-1){
	    cout<<src<<" ";
		return;
	}
	
	printPath(parent, parent[src]);
	
	cout<<src<<" ";
}

int getMinDistance(vector<int>&distance, vector<int>&included){
	
	int minDist = INT_MAX;
	int minIndex;
	
	for(int i=0; i<V; i++){
		if(!included[i] && distance[i]<= minDist){
			minDist = distance[i];
			minIndex = i;
		}
	}
	
	return minIndex;
}


void dijkstra(int graph[V][V], int src){
	
	vector<int>included(V, false);
	vector<int>distance(V, INT_MAX);
	vector<int>parent(V);
	parent[src] = -1;
	
	distance[src] = 0;
	int count = 0;
	while(count<V){
		int nodeToInclude = getMinDistance(distance, included);
		included[nodeToInclude] = true;
		
		/* Update Distances */
		
		for(int i=0; i<V; i++){
			if(!included[i] && graph[nodeToInclude][i] !=0 && distance[nodeToInclude] + graph[nodeToInclude][i] < distance[i]){
				distance[i] = distance[nodeToInclude] + graph[nodeToInclude][i];
				parent[i] = nodeToInclude;
				cout<<"Parent of "<<i<<" is "<<nodeToInclude<<"\n";
			}
		}
		
		count ++;
	}
	
	/* Printing result */
	
	for(int i=0; i<V; i++){
		cout<<distance[i]<<" ";
		printPath(parent, i);
		cout<<endl;
	}
	
}



int main() 
{ 
   
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
}
