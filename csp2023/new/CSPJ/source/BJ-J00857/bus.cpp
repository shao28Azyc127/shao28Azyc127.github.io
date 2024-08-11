#include<iostream>
#include<cstdio>
using namespace std;

struct ver{
    int e[20001][2]; // rubian&quanzhong
    int elen;
}v[10001];

int n, m, k;
int tc, ma = 0;
int ans = -1;

void dfs(int t, int nv) {
    if (ans != -1 && t > ans || t > ma + m)
        return;

    if (nv == n) {
        if (t % k == 0)
            ans = t;
        return;
    }

    for (int i = 1;i <= v[nv].elen;i++)
        if (v[nv].e[i][1] <= t)
            dfs(t + 1, v[nv].e[i][0]);
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++) {
        int u, b, q;
        cin >> u >> b >> q;
        v[u].elen++;
        v[u].e[v[u].elen][0] = b;
        v[u].e[v[u].elen][1] = q;
        ma = max(ma, q);

    }
    for (tc = 0;tc <= ma + k;tc += k)
        dfs(tc, 1);

    cout << ans;
    return 0;
}
