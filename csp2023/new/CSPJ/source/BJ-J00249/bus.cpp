#include<bits/stdc++.h>

using namespace std;

#define int long long
const int MAXN = 1e7+10;

int ans = LLONG_MAX;
int n, m, k;
struct node {
    int u, v, t;
};
vector<node> G[MAXN];

void dfs(int x, int d, int st) {
    if(x==n) {
        if(d%k) return;
        if(st==0) ans = min(ans, d);
        else if(st%k==0) ans = min(ans, st+d);
        else ans = min(ans, st/k*k+k+d);
    }

    for(int i = 0; i < G[x].size(); i++) {
        int v = G[x][i].v, t = G[x][i].t;
        dfs(v, d+1, max(st, t-d));
    }
}

signed main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        G[u].push_back({u, v, a});
    }
    dfs(1, 0, 0);
    if(ans==LLONG_MAX) cout <<-1;
    else cout << ans;
    return 0;
}
