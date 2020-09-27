int xdir[4] = {1,-1,0,0};
int ydir[4] = {0,0,1,-1};
int visited[MAXN][MAXN];

bool eligible(char board[][MAXN], int n, int m, int i, int j, char curr){
    if(i>=0 && j>=0 && i<n && j<m && board[i][j]==curr)
        return true;
    return false;
}

int path_helper(char board[][MAXN], int n, int m, int i, int j, int fromx, int fromy, char curr){
    if(i>n || j>m)
        return 0;
    if(visited[i][j] == 1)
        return 1;
    if(board[i][j] != curr)
        return 0;

    visited[i][j] = 1;
    for(int k = 0 ; k < 4 ; k++){
        int dx = i + xdir[k];
        int dy = j + ydir[k];
        if(eligible(board,n,m,dx,dy,curr) && (dx!=fromx || dy!=fromy)){
            if(path_helper(board, n, m, dx, dy, i, j, curr) == 1)
                return 1;
        }
    }
    return 0;
}

int solve(char board[][MAXN],int n, int m)
{
    int ans = 0;
    memset(visited,0,sizeof(visited));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(visited[i][j] != 1){
                char curr = board[i][j];
                ans = path_helper(board, n, m, i, j, -1, -1, curr);
                if(ans==1)
                    return 1;
            }
        }
    }
    return ans;
}

we'll make a 'visited' matrix which will mark 1 for an index if it has already been looked into.
Then, I'll traverse for each element and pass it to a new function which will work recursively and return 1 if the cycle exists. 3.I'll pass the visited matrix, dimensions of original matrix(will be same for visited matrix),int i, int j(i and j are the original indices passes to this function by our original function and does not change during recursive calls), int p, int q(p and q keep on changing to alternate eligible indices), count(if count>=4 and p and q becomes adjacent to i and j) return 1;
I'll also create an iseligible function to check if the given index is not out of bounds.
