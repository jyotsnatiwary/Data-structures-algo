you can't calculate the factorial each time you want because this
will result in Time Limit Exceeded, as each factorial take .

So you should use DP for that:

void pre_calculate(){       // calculating factorial

    factorial[0] = 1;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}
In last:

You should multiply all groups factorials with each other to get the
number of ways for different photographs.

#include <bits/stdc++.h>

using namespace std;

long long n , m , q , x , y, tem1, tem2 , t, sum, mod = 1e9 + 7, ans;

bool vis [1000 + 1][1000 + 1];
bool arr [1000 + 1][1000 + 1];
long long factorial [1000000 + 1];

int dirc [8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };

void pre_calculate(){       // calculating factorial

    factorial[0] = 1;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % mod;
    }
}

void dfs(int x, int y){

    vis[x][y] = true;
    sum++;

    for(int i = 0; i < 8; i++){                     // check for the 8 movements

        int dx = x + dirc[i][0];
        int dy = y + dirc[i][1];

        if(dx <= 0 || dx > n || dy <= 0 || dy > m) continue;        // out of board
        if(vis[dx][dy] || !arr[dx][dy]) continue;                   // check if the cell is visited or doesn't contain a horse
        dfs(dx, dy);

    }

}


int main()
{

    pre_calculate();

    cin >> t;

    while(t--){

        cin >> n >> m >> q;

        ans = 1;

        for(int i = 0; i <= n; i++){                // reset arrays in each test case

            for(int j = 0; j <= m; j++){

                vis[i][j] = false;
                arr[i][j] = false;
            }
        }

        for(int i = 0; i < q; i++){

            cin >> tem1 >> tem2;
            arr[tem1][tem2] = true;
        }

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){

                if(!vis[i][j] && arr[i][j]){

                    sum = 0;
                    dfs(i , j);                             // begin dfs from that unvisited horse (New group of connected horses)
                    ans = (ans * factorial[sum]) % mod;     // number of arrangements
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
