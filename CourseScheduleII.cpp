//   https://leetcode.com/problems/course-schedule-ii/

/* There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
             
             
The idea is to simply check if it forms a Directed Acyclic Grapgh (DAG)  --> If it does, return one of its topological sorting.

If it doesn't return an empty vector
             
 */
 
 
 class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int>adj[V];
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        return topologicalSort(adj, V);
    }
    
    
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
        vector<int>temp;
        return temp;
    }


    bool topologicalSortUtil(int x, vector<int>adj[], vector<bool>&isVisiting, vector<bool>&visited, vector<int>&s){
        
        visited[x] = true;
        isVisiting[x] = true;

        for(int i=0; i<adj[x].size(); i++){
            if(!visited[adj[x][i]])
                if(!topologicalSortUtil(adj[x][i], adj, isVisiting, visited, s))
                    return false;

            if(isVisiting[adj[x][i]])
                    return false;
        }

        isVisiting[x]=false;
        s.push_back(x);
        return true;
    }
};
