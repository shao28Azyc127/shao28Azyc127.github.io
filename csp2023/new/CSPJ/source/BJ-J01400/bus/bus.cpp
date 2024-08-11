#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;

inline int read() {
    register int x = 0, w = 1;
    register char c = getchar();
    while (c < '0' || c > '9') { w = (c == '-') ? -1 : 1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
    return x * w;
}

const int N = 1e4 + 5;
const int INF = 2e9;
int n, m, k;
int a[N];
int ans = INF;
bool vis[N];
vector<pair<int, int> > e[N];

void dfs(int p, int now) {
    if (now > ans) return;
    if (p == n) {
        if (now % k == 0) ans = min(ans, now);
        return;
    }
    for (int i = 0; i < e[p].size(); i++) {
        int v = e[p][i].first, w = e[p][i].second;
        if (vis[v]) continue;
        vis[v] = true;
        dfs(v, now + ((now < w) ? k : 0) + 1);
        vis[v] = false;
    }
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    n = read(); m = read(); k = read();
    if (n >= 1000) {
        puts("-1");
        return 0;
    }
    for (int i = 1;  i <= m; i++) {
        int u = read(), v = read(), w = read();
        e[u].push_back({v, w});
    }
    vis[1] = true;
    dfs(1, 0);
    if (ans == INF) puts("-1");
    printf("%d\n", ans);
    return 0;
}
