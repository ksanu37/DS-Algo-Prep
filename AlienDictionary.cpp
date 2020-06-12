/* https://practice.geeksforgeeks.org/problems/alien-dictionary/1

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N and k denoting the size of the dictionary. Then in the next line are sorted space separated values of the alien dictionary.

Output:
For each test case in a new line output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findOrder() which takes the string array dict[], its size N and the integer K as inputs and returns a string denoting the order of characters in the alien language.

Expected Time Complexity: O(N + K).
Expected Auxiliary Space: O(K).

Constraints:
1 <= T <= 1000
1 <= N <= 300
1 <= k <= 26
1 <= Length of words <= 50

Example:
Input:
2
5 4
baa abcd abca cab cad
3 3
caa aaa aab

Output:
1
1

Explanation:
Test Case 1:
Input:  Dict[ ] = { "baa", "abcd", "abca", "cab", "cad" }, k = 4
Output: Function returns "bdac"
Here order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa"
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Test Case 2:
Input: Dict[] = { "caa", "aaa", "aab" }, k = 3
Output: Function returns "cab"



THE SOLUTION:  The idea is to traverse the string array and make a graph adjacency list on the basis of the letters that appear in an order. 

This creates a Directed Acyclic Graph. The Topological Sort of this DAG will yield the required result

*/


#include<bits/stdc++.h>
using namespace std;

void getAlphaOrder(int x, vector<int>adj[], vector<bool>&visited, stack<int>&s){
	visited[x] = true;
	for(int i=0; i<adj[x].size(); i++){
		if(!visited[adj[x][i]]){
			getAlphaOrder(adj[x][i], adj, visited,s);
		}
	}
	
	s.push(x);
}

string findOrder(string dict[], int N, int K) {
    vector<int>adj[26];
    vector<bool>isPresent(26,false);
    for(int i=0; i<N-1; i++){
        for(int j = 0 ; j<min(dict[i].length(), dict[i+1].length()); j++){
            if(dict[i][j]!=dict[i+1][j]){
                //cout<<dict[i][j]<<" "<<dict[i+1][j]<<'\n';
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                isPresent[dict[i][j]-'a'] = true;
                isPresent[dict[i+1][j] - 'a'] = true;
                break;
            }
        }
    }
    vector<bool>visited(26, false);
    stack<int>s;
    for(int i=0; i<26; i++){
    	if(!visited[i] && isPresent[i])
	    	getAlphaOrder(i, adj, visited, s);
	}
	string temp = "";
	while(!s.empty()){
		int x = s.top();
		
		temp += char(x+'a');
		s.pop();
	}
    
    cout<<temp;
    return temp;
    
}


int main(){
	
	int n=3, k = 3;
	
	string dict[] = {"caa", "aaa", "aab"};
	
	findOrder(dict, n, k);
	
}


