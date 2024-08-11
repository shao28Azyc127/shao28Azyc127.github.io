#include <bits/stdc++.h>
using namespace std;
//pq + bfs

int n, m, k, ans;
vector <int> e[2005], v[2005];
struct node {
    int d, t, nw;
    bool operator <(node y) {
        return y.d < d;
    }
};
queue <node> q;
int dis[10005];
int vis[10005];
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
        int x, y, z; cin >> x >> y >> z;
        e[x].push_back(y);
        v[x].push_back(z);
    }
    q.push((node){0, 0, 1});
    memset(dis, 0x7f, sizeof(dis));
    while (q.size()) {
        int nt = q.front().t;
        int nw = q.front().nw;
        int nd = q.front().d;
        q.pop();
        cout << nt << " " << nw << " " << nd  << "\n";
        if (vis[nw]) continue;
        vis[nw] = 1;
        if (nw == n) {
            cout << nt << "\n";
            if (nd % k == 0) {
                cout << nd;
                return 0;
            }
            vis[nw] = 0;
        }
        for (int i = 0; i < e[nw].size(); i ++) {
            q.push((node){nd + 1, nt + v[nw][i], e[nw][i]});
        }
    }
    cout << ans;
    return 0;
}