#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define int long long

#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif

#define maxn 500055
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using namespace std;

int cid, n, m, k, d, f[1005][1005], val[1005][1005];

void work() {
    cin >> n >> m >> k >> d;
    if(n <= 1000) {
        memset(f, 0xbf, sizeof(f));
        memset(val, 0, sizeof(val));
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            val[u][v] += w;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                val[i][j] += val[i][j - 1];
            }
        }
        f[0][0] = 0;
        for(int i = 1; i <= n; i++) f[i][0] = 0;
        for(int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], f[i][0]);
            for(int j = 1; j <= k; j++) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] - d + val[i][j]);
                f[i][0] = max(f[i][0], f[i - 1][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i <= k; i++) ans = max(ans, f[n][i]);
        cout << ans << '\n';
    }
}

signed main() {
    fopen("run")
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> cid; int _; cin >> _; while(_--) work();
}