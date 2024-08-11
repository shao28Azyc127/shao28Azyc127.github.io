#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

typedef pair<ll, int> pii;

struct land {
    ll a, b, c;
};

land l[100005];
ll a[100005];
vector<int> g[100005];
int st[100005];

void gt() {
    int t = 0;
    priority_queue<pii> q;
    q.push(make_pair(a[1], 1));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        st[u] = t++;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!st[v]) {
                q.push(make_pair(a[v], v));
            }
        }
    }
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i].a >> l[i].b >> l[i].c;
        a[i] = ceil(l[i].a / (double)max(l[i].b, 1LL));
    }
    int u, v;
    bool isa1 = true;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        if (u != 1) isa1 = false;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (isa1) { // special D
        gt();
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, st[i] + a[i]);
        }
        cout << ans << endl;
    } else {}
    return 0;
}