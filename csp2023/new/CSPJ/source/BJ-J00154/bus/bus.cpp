#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m, k, x, y, z;
int tot, head[N], nxt[N << 1], to[N << 1], open[N << 1];
inline void Add(int x, int y, int z) {
    tot++, nxt[tot] = head[x], head[x] = tot;
    to[tot] = y, open[tot] = z;
}

namespace n1 {
    struct node {
        int x, t, len;
        node(int _x, int _t, int _len) : x(_x), t(_t), len(_len) {}
        inline bool operator < (const node &cmp) const {
            return len > cmp.len;
        }
    };
    priority_queue<node> q;
    int dis[N][105];
    bool vis[N][105];
    inline void Solve(void) {
        memset(dis, 0x3f, sizeof dis);
        dis[1][0] = 0; q.push(node(1, 0, 0));
        while (!q.empty()) {
            int x = q.top().x, t = q.top().t; q.pop();
            if (vis[x][t]) continue;
            vis[x][t] = 1;
            for (int i = head[x]; i != 0; i = nxt[i]) {
                if (dis[to[i]][(t + 1) % k] > dis[x][t] + 1) {
                    dis[to[i]][(t + 1) % k] = dis[x][t] + 1;
                    q.push(node(to[i], (t + 1) % k, dis[to[i]][(t + 1) % k]));
                }
            }
        }
        if (dis[n][0] > 1e9) cout << "-1" << endl;
        else cout << dis[n][0] << endl;
    }
}

bool flag1 = 1;
int main(void) {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        Add(x, y, z);
        flag1 &= (z == 0);
    }
    if (flag1) n1::Solve();
    else cout << "-1" << endl;
    return 0;
}
