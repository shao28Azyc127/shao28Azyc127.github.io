
#include <bits/stdc++.h>
#define ll long long
#define MAXM 20005
#define MAXN 10005
using namespace std;
struct Edge {
    ll to, nxt, val;
}edge[MAXM];
ll ecnt, head[MAXN];
void add(int u, int v, int w) {
    edge[++ecnt].to = v;
    edge[ecnt].val = w;
    edge[ecnt].nxt = head[u];
    head[u] = ecnt;
}
ll nowt, n, m, k, flag;
int dfs(int u, int t, int outtime) {
 //   cout << u << ' ' << t << endl;
    if (u == n) {
        if (t % k == 0) {
            return t + ceil(1.0 * outtime / k) * k;
        }
        return 99999999;
    }
    int ret = 99999999;
    for (int i = head[u]; i != 0; i = edge[i].nxt) {
//        cout << dfs(edge[i].to, t + 1) << endl;
        if (edge[i].val - t > outtime) {
            outtime = edge[i].val - t;
        }
        ret = min(ret, dfs(edge[i].to, t + 1, outtime));
    }
    return ret;
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    nowt = k;
    for (int i = 1; i <= m; i++) {
        int in1, in2, in3;
        scanf("%d%d%d", &in1, &in2, &in3);
        add(in1, in2, in3);
    }
    int ans = dfs(1, 0, 0);
    if (ans > 9999999) {
        cout << -1;
    }
    cout << ans;
    return 0;
}


