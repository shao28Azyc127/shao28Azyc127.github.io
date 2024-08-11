#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void read(T &x){
    x = 0; bool F = 0; char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
    for (;isdigit(c);c = getchar()) x = x*10+(c^48);
    if (F) x = -x;
}

const int N = 205;
int dp[N][N];
int x[N], y[N];
int cx[N], cy[N]; // copy
int c, nx, ny, q;

inline void solve(){
    // x < y
    memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
    for (int i = 1;i<=nx;i++){
        for (int j = 1;j<=ny;j++){
            // dp[i][j]
            for (int k = j;k>=1;k--){
                if (x[i]>=y[k]) break;
                if (dp[i-1][k] || dp[i-1][k-1]){
                    dp[i][j] = 1; break;
                }
            }
        }
    }
    if (dp[nx][ny]){printf("1"); return;}

    // x > y
    memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
    for (int i = 1;i<=nx;i++){
        for (int j = 1;j<=ny;j++){
            // dp[i][j]
            for (int k = j;k>=1;k--){
                if (x[i]<=y[k]) break;
                if (dp[i-1][k] || dp[i-1][k-1]){
                    dp[i][j] = 1; break;
                }
            }
        }
    }
    printf("%d", dp[nx][ny]);
}

int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    read(c), read(nx), read(ny), read(q);
    for (int i = 1;i<=nx;i++) read(x[i]), cx[i] = x[i];
    for (int i = 1;i<=ny;i++) read(y[i]), cy[i] = y[i];
    solve(); int kx, ky, pos, val;
    while (q--){
        read(kx), read(ky);
        memcpy(x, cx, sizeof(x)); memcpy(y, cy, sizeof(y));
        while (kx--) read(pos), read(val), x[pos] = val;
        while (ky--) read(pos), read(val), y[pos] = val;
        solve();
    }
    return 0;
}
/*
self check:
1. long long
2. size of array
3. code for testing
4. initializing
5. freopen
*/
