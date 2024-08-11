#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[N], b[N], c[N], d[N], now, ans;
vector<int> G[N];
bool cmp(int x, int y) {
    return d[x] > d[y];
}
void dfs1(int u, int fa) {
    sort(G[u].begin(), G[u].end(), cmp);
    int tmp = ++now;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) {
            continue;
        }
        dfs1(v, u);
        ans = max(tmp + d[u] - 1, ans);
    }
}
bool check1() {
    for(int i = 1; i <= n; i++) {
        if(c[i]) return false;
    }
    return true;
}
int get(int now) {
    int sum = 0, cnt = 0, day = now;
    while(sum < a[now]) {
        sum += max(b[now] + c[now] * day, 1ll), cnt++, day++;
    }
}
signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]), d[i] = (a[i] + b[i] - 1) / b[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    if(check1()) {
        dfs1(1, -1);
        cout << ans;
    } else {
        for(int i = 1; i <= n; i++) {
            ans = max(ans, get(i));
        }
        printf("%lld", ans);
    }
    return 0;
}
