/*Largest Piece
Send Feedback
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3*/



#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &cake, vector<vector<bool>> &visited, int x, int y, int n){
    if(visited[x][y]){
        return 0;
    }
    visited[x][y] = true;
    int count = 1;int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    
    for(int i  = 0; i < 4; i++){
        int X = x + dx[i];
        int Y = y + dy[i];
        if(X >= 0 && X < n && Y >= 0 && Y < n && cake[X][Y] == 1){
            count += dfs(cake, visited, X, Y, n);
        }
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n){
    int biggestPieceSize = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] == 1 && !visited[i][j]){
                biggestPieceSize = max(biggestPieceSize, dfs(cake, visited, i, j, n));
            }
        }
    }
    
    return biggestPieceSize;
}
