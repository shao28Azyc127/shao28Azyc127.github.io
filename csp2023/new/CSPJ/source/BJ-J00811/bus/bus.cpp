#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define  int long long

using namespace std;

typedef long long ll;

const int N = 1e4 +10;

struct node {
    int to, val;
};

int n, m, k;
vector <node> adj[N];
int v[N][110];
int T;

void dfs (int u, int val, int maxx) {
    //cout << u << " " << val << " " << maxx << endl;

    if (val > T && T != -1) return ;
    if (u == n && val % k == 0) {
        if (T == -1 ) T = val + ((maxx % 3 == 0) ? maxx : (maxx / 3 + 1) * 3);
        else T = min(T, val + ((maxx % 3 == 0) ? maxx : (maxx / 3 + 1) * 3));
        return ;
    }

    for (int i = 0; i < adj[u].size(); i ++ ) {
        int to = adj[u][i].to, w = adj[u][i].val;
        if (v[to][(val + 1) % k] != 0) continue;
        v[to][(val + 1) % k] = 1;
        dfs (to, val + 1, max (maxx, w));
    }
}

struct node2 {
    int id, val;
};

signed main () {
    freopen ("bus.in", "r", stdin);
    freopen ("bus.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    int r = 0;
    for (int i = 1; i <= m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        r = max (r, c);
    }
    v[1][0] = 1;
    //cout << "p" << endl;
    T = -1;
    dfs (1, 0, 0);

    cout << T << endl;

    //cout << r << endl;
    /*
    int l = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        cout << mid << endl;
        if(check (mid)) r = mid;
        else l = mid + 1;
    }
    */
    //cout << l  << endl;

    return 0;
}
