#include<bits/stdc++.h>
using namespace std;

const int NR = 20;

int n;
int cal[25][25], dp[1 << 20];
long long a[NR + 5], b[NR + 5], c[NR + 5];
bool v[1 << 20];
vector<int> e[NR + 5];

int popcnt(int x) {
    int res = 0;
    while(x) {
        res += x & 1;
        x >>= 1;
    }
    return res;
}

int dfs(int u, int fa, int s) {
    if(!(s >> u - 1 & 1)) {
        return 0;
    }
    int res = 1;
    for(int v : e[u]) {
        if(v != fa) {
            res += dfs(v, u, s);
        }
    }
    return res;
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if(n <= 20) {
        for(int s = 1; s < 1 << n; s++) {
            v[s] = popcnt(s) == dfs(1, 0, s);
        }
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int l = n, r = (int)1e9;
                while(l < r) {
                    int t = l + r >> 1;
                    //cout << t << ' ';
                    bool f = 0;
                    __int128 x = 1;
                    if(c[i] >= 0) {
                        x = x * c[i] * (t + j) * (t + 1 - j) / 2;
                        x = x + b[i] * (t + 1 - j);;
                    }
                    else {
                        int t_ = b[i] / (-c[i]);
                        if(t_ >= j) {
                            x = x * c[i] * (t_ + j) * (t_ + 1 - j) / 2;
                            x = x + b[i] * (t_ + 1 - j);
                            x = x + t - t_;
                        }
                        else {
                            x = t - j + 1;
                        }
                    }
                    if(x >= (__int128)a[i]) {
                        r = t;
                    }
                    else {
                        l = t + 1;
                    }
                }
                cal[i][j] = l;
            }
        }
        dp[1] = cal[1][1];
        for(int s = 2; s < 1 << n; s++) {
            if(v[s]) {
                for(int j = 0; j < n; j++) {
                    if((s >> j & 1) && v[s - (1 << j)]) { 
                        dp[s] = min(dp[s], max(dp[s - (1 << j)], cal[j + 1][popcnt(s)]));
                    }
                }
            }
        }
        cout << dp[(1 << n) - 1] << '\n';
    }

    return 0;
}