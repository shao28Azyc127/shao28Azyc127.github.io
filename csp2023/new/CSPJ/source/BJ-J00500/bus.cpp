#include <bits/stdc++.h>
#define N 10005
#define INF 0x7fffffff

using namespace std;
struct node {
    int id, d;
};
bool operator >(node a, node b) {
    return a.d > b.d;
}
vector<int> v[N]; int n, m, k, u, w, a, d[N] = {};
bool vis[N] = {};
priority_queue<node, vector<node>, greater<node> > q;
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++ ) {
        cin >> u >> w >> a;
        v[u].push_back(w);
    }
    fill(d, d+N, INF);
    d[1] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        int t = q.top().id; q.pop();
        if (vis[t]) continue;
        vis[t] = 1;
        for (auto y : v[t]) {
            if (d[y] > d[t] + 1) {
                d[y] = d[t] + 1;
                q.push({y, d[y]});
            }
        }
    }

    cout << ceil(1.0 * d[n] / k) * k;
    return 0;
}
