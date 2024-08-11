#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e4 + 10;
const int maxk = 100 + 10;
const int A = 1e6 + 5e4;
int n, m, k, head, tail, q[maxn * maxk][2];
int dis[maxn][maxk];
vector<pair<int, int> > e[maxn];
int check(int x) {
    head = tail = 0; 
    q[tail][0] = 1; q[tail++][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            dis[i][j] = 0;
    dis[1][0] = 1;
    while (head < tail) {
        int u = q[head][0], K = q[head++][1];
        for (auto [v, w] : e[u]) 
            if (w <= x * k + K && !dis[v][(K + 1) % k]) {
                dis[v][(K + 1) % k] = dis[u][K % k] + 1;
                q[tail][0] = v; q[tail++][1] = K + 1;
            }
    }
    return dis[n][0];
}
int main() {
    ios::sync_with_stdio(false);
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[u].emplace_back(v, w);
    }
    int l = 0, res = -1, r = A / k, mn = A;
    while (l <= r) {
        int mid = (l + r) >> 1, val = check(mid);
        if (val) mn = min(mn, mid * k + val - 1), res = mid, r = mid - 1;
        else l = mid + 1;
    }
    for (int i = res + 1; i <= res + 20; i++) mn = min(mn, i * k + check(i) - 1);
    cout << (~res ? mn : res) << '\n';
    return 0;
}