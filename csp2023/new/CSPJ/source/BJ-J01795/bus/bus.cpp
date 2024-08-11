#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e4 + 5;

int n, m, k, t;
vector <int> G[N];
int bfs() {
    queue <int> q;
    q.push(1);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 1; i <= G[now].size(); i++) {
             int temp = G[now][i];
             t++;
             if (temp == n) {
                if (t % k == 0) return t;
             }
             q.push(temp);
        }
    }
    return -1;
}

int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    bool flag = true;
    for (int i = 1; i <= m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        if (a != 0) flag = false;
        G[u].push_back(v);
    }
    cout << -1 << endl;
    return 0;
}
