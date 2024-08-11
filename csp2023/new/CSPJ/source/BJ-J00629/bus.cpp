

#include <iostream>
#include <vector>
#include <queue>

#define int long long
#define endl '\n'

using namespace std;

const int MAXI = 1e4 + 9;
int n, m, k;
int u, v, a;
vector<int> G[MAXI];

queue<int> q;
queue<int> cnt;
int solo;

bool vis[MAXI];

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> a;
        G[u].push_back(v), G[v].push_back(u);
    }

    if (k > 1) return cout << "-1\n", 0;

    vis[1] = 1, q.push(1), cnt.push(0);
    while (!q.empty()) {
        u = q.front(), q.pop();
        solo = cnt.front(), cnt.pop();
        if (u == n) return cout << solo << endl, 0;
        for (int i = 0; i < (int)G[u].size(); i++) {
            v = G[u][i];
            if (!vis[v]) vis[v] = 1, q.push(v), cnt.push(solo + 1);
        }
    }

    cout << "-1\n";

    return 0;
}
