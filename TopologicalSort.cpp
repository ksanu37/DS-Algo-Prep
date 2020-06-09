/* https://practice.geeksforgeeks.org/problems/topological-sort/1

https://www.geeksforgeeks.org/topological-sorting/ 

Topological sorting : Applicable to DAG -- Directed Acyclic Graphs

It represents the vertices of a graph in a linear order such that in a directed edge u->v   u comes before v. 
There can me more than one Topological sorting of a graph


The topological sort of a graph can be achieved using DFS, while traversing, maintain a stack

for a vertex, push all its adjacent vertices in the stack before pushing this vertex in the stack. 
Print the stack from top to bottom

*/

// Solution:      Graph representation --> Adjacency list   vector<int>adj[V]


vector<int> topologicalSort(vector<int>adj[], int V){
	
	vector<bool>visited(V, false);
	vector<bool>isVisiting(V, false);
	vector<int>s;
	bool flag = true;
	for(int i=0; i<V; i++){
		if(!visited[i]){
			if(topologicalSortUtil(i, adj, isVisiting, visited,s)==false){
				cout<<"The graph is not acyclic, hence can't find a topological sorting\n";
				flag = false;
			}
		}
	}
	
	if(flag){
		 return s;
		}
	
	return vector<int>temp;
}


bool topologicalSortUtil(int x, vector<int>adj[], vector<bool>&isVisiting, vector<bool>&visited, vector<int>&s){
	visited[x] = true;
	isVisiting[x] = true;
	
	for(int i=0; i<adj[x].size(); i++){
		if(!visited[adj[x][i]] && !topologicalSortUtil(adj[x][i], adj, isVisiting, visited, s))
			return false;
		
		if(isVisiting[adj[x][i]]])
				return false;
	}
	
	isVisiting[x]=false;
	s.push_back(x);
	return true;
}
