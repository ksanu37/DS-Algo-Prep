/* https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/ 

Backtracking algorithm paradigm:  An incremental solution to solve a problem which requires trying out all the combinations.

Start solving for a combination and if as some stage it looks like it violates the problem statement, take a step back and start
trying a different combination from there.

Knight's tour problem:

The knight is placed on the first block of an empty board and, moving according to the rules of chess, must visit each square exactly once.

*/

#include<bits/stdc++.h>
using namespace std;
#define N 8

int solveKTUtil(int sol[N][N], int i, int j, int moveNo, int xMove[], int yMove[]);
bool isSafe(int nextX, int nextY, int sol[N][N]);
void solveKT(){
	
	int sol[N][N];   /* Building the solution Matrix */
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			sol[i][j] = -1 ;    // This cell has not been visited yet
	}
	
	int xMove[] = {-2, -2, -1, -1, 2, 2, 1, 1};
	int yMove[] = {1, -1, 2, -2, 1, -1, 2, -2};
	sol[0][0] = 0;
	int result = solveKTUtil(sol, 0,0, 1, xMove, yMove);
	if(result == 1){
		cout<<"Solution Exists\n";
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++)
				cout<<sol[i][j]<<" ";
			cout<<endl;
		}
	}
	
	else{
		cout<<"Solution Not Possible";
	}
}

int main(){
	solveKT();
	return 0;
}



int solveKTUtil(int sol[N][N], int i, int j, int moveNo, int xMove[], int yMove[]){
	//cout<<moveNo<<" ";
	if(moveNo == N*N)
		return 1;
		
	int k, nextX, nextY;
	for(k=0; k<8; k++){
		nextX = i + xMove[k];
		nextY = j + yMove[k];
		
		if(isSafe(nextX, nextY, sol)){
			sol[nextX][nextY] = moveNo;
			if(solveKTUtil(sol, nextX, nextY, moveNo+1, xMove, yMove)==1)
				return 1;
			else
				sol[nextX][nextY] = -1;
		}	
	}
	
	return 0;
}

bool isSafe(int nextX, int nextY, int sol[N][N]){
	return nextX>=0 && nextX<N && nextY>=0 && nextY<N && sol[nextX][nextY]==-1;
}
