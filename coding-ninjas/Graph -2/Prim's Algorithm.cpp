/*Code : Prim's Algorithm
Send Feedback
ID: 1724

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5*/

#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int *weight, bool *isVisited, int n){
    int minVertex = -1;
    for(int i = 0; i < n; i++){
        if(!isVisited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}
int main(){
    int n, e;
    cin >> n >> e;
    int **input = new int*[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[n];
        for(int j = 0; j < n; j++) input[i][j] = -1;
    }
    for(int i = 0; i < e; i++){
        int ei, ej, w;
        cin >> ei >> ej >> w;
        input[ei][ej] = w;
        input[ej][ei] = w;
    }
    int *parent = new int[n];
    int *weight = new int[n];
    bool *isVisited = new bool[n];
    for(int i = 0; i < n; i++){
        weight[i] = INT_MAX;
        isVisited[i] = false;
    }
    parent[0] = -1;
    weight[0] = 0;
    for(int i = 0; i < n; i++){
        int minVertex = findMinVertex(weight, isVisited, n);
        isVisited[minVertex] = true;
        for(int j = 0; j < n; j++){
            if(input[minVertex][j] > 0 && !isVisited[j]){
                if(input[minVertex][j] < weight[j]){
                    weight[j] = input[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        int ei = i;
        int ej = parent[i];
        int w = weight[i];
        if(ei < ej) cout << ei << " " << ej << " " << w << endl;
        else cout << ej << " " << ei << " " << w << endl;
    }
}
