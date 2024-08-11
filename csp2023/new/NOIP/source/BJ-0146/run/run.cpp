# include <bits/stdc++.h>
# define int long long
# define inf 4e18
# define maxn 1005
using namespace std;
int n, k, m, d, c, t, ans;
int dp[maxn][maxn];
int a[maxn][maxn];
void sol()
{
    cin >> n >> m >> k >> d;
    ans = 0;
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= m; i++){
        int x, y, v;
        cin >> x >> y >> v;
        for(int j = y; j <= min(x, k); j++) a[x][j] += v;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= min(i - 1, k); j++)
            dp[i][0] = max(dp[i][0], dp[i - 1][j] + a[i][0]);
        for(int j = 1; j <= min(i, k); j++)
            dp[i][j] = a[i][j] + dp[i - 1][j - 1] - d;
    }
    for(int i = 0; i <= k; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}
signed main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> c >> t;
    while(t--) sol();
    return 0;
}
/*
hyfcabbyblue afoed!
hyfcabbyblue afoed!
hyfcabbyblue afoed!
*/
