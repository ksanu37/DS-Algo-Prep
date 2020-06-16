/* Rat In a Maze Problem 

https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (n-1, n-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).

Input:


The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer N denoting the size of the square matrix. The next line contains N*N space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination. Print -1 if no such path exists.

User Task:
Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible paths which the rat can take to reach the destination at (n-1, n-1). If no such path exists the function should return empty array.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space : O(L*X), L = length of the path, X = number of paths.


Constraints:
1 <= T <= 100
2 <= N <= 5
0 <= matrix[i][j] <= 1

Example
Input:
3
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
2
1 0 1 0 

Output:
DRDDRR
DDRDRR DRDDRR
-1

*/


bool isSafe(int x, int y, bool visited[MAX][MAX], int m[MAX][MAX], int n){
    return x>=0 && x<n && y>=0 && y<n && !visited[x][y] && m[x][y]==1;
}

void printPathUtil(int x, int y, int m[MAX][MAX], int n, bool visited[MAX][MAX], vector<string>&res, string s){
    if(x==n-1 && y==n-1){  // If the End is reached
        res.push_back(s);
        return;
    }
    
    visited[x][y] =  true;
    
    int X[] = {-1,1,0,0};
    int Y[] = {0,0,-1,1};
    
    int k, next_x, next_y;
    
    for(k=0; k<4; k++){
        next_x = x+X[k];
        next_y = y +Y[k];
        
        if(isSafe(next_x, next_y, visited, m, n)){
            switch(k){
                case 0: s = s+'U'; break;
                case 1: s = s+'D'; break;
                case 2: s = s+'L'; break;
                case 3: s = s+'R'; break;
            }
            
            printPathUtil(next_x, next_y, m, n, visited, res, s);
            
            // BackTracking 
            if (s.size () > 0)  s.resize (s.size () - 1);
        }
    }
    
    visited[x][y] = false;
}
vector<string> printPath(int m[MAX][MAX], int n) {
    bool visited[MAX][MAX];
    memset(visited, false, sizeof(visited));
    vector<string>res;
    if(m[0][0]==0)
    return res;
    string s = "";
    
    printPathUtil(0, 0, m,n,visited, res,s);
    sort(res.begin(), res.end());
    return res;
}
