#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1005;
int n;
long long a[N];
int b[N];
int c[N];
long long dy[N];
vector<int> g[N];
int fath[N];
struct node {
    int i;
    int v;
} d[N];
bool operator<(node p1, node p2) {
    if(p1.v != p2.v) {
        return p1.v > p2.v;
    }
    return p1.i < p2.i;
}
void pre_dfs(int u, int fth) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v == fth) {
            continue;
        }
        pre_dfs(v, u);
    }
    fath[u] = fth;
}
int vis[N];
int ns = 0;
void sgn(int u) {
    if(vis[u]) {
        return;
    }
    vis[u] = 1;
    ns++;
    sgn(fath[u]);
}
bool check(int x) {
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    ns = 0;
    vis[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(d[i].i != 1) {
            sgn(d[i].i);
        }
        if(ns > x - d[i].v) {
            return false;
        }
    }
    return true;
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    int mdy = 1e9 + 5;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        dy[i] = a[i] / b[i];
        if(a[i] % b[i] != 0) {
            dy[i]++;
        }
        mdy = min(mdy, (int)dy[i]);
        d[i].i = i;
        d[i].v = dy[i];
    }
    int u, v;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pre_dfs(1, 0);
    int l = mdy;
    int r = 1e9;
    int mid;
    sort(d + 1, d + n + 1);
    while(l + 1 < r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}
