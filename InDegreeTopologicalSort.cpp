/* https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/ 

Kahn's Algorithm for Topological sorting  

The idea is to use the indegree of the vertices  --> In a DAG, there will be at least one vertex with indegree =0 and always be at least one vertex with
outdegree = 0  (Since the grapgh os acyclic, it starts somewhere and ends somewhere)

we take a queue, enque all the vertices with indegree 0 and iterate over their adjacent vertices decreasing their indegree by 1,

the moment their indegree reaches 0, we push them on to the result vector. 

if all  the vertices couldn't be pushed, the graph contains a cycle

*/


int* topoSort(int V, vector<int> adj[]) {
    int* res = new int[V];
    
    vector<int>inDegree(V,0);
    
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            inDegree[adj[i][j]]++;
        }
    }
    queue<int>q;
    for(int i=0; i<V; i++)
        if(inDegree[i]==0)
            q.push(i);
            
    int count = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        res[count] = x;
        for(int i=0; i<adj[x].size(); i++){
            inDegree[adj[x][i]]--;
            
            if(inDegree[adj[x][i]]==0)
                q.push(adj[x][i]);
        }
        
        count++;
    }
    
    if(count!=V)     // If all the vertices couldn't be pushed
       cout<<"The graph contains a cycle";
    return res;
}
