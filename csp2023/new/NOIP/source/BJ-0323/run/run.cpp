#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e3 + 5, M = 1e3 + 5;
const ll INF = 1e14 + 5;

ll f[N][M], cres[N];

vector<pair<int, ll> > qt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t -- ) {
        ll n, m, k, d;
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= n; i ++ ) {
            qt[i].clear();
        }
        for (int i = 1; i <= m; i ++ ) {
            int x, y, v;
            cin >> x >> y >> v;
            qt[x].push_back({y, v});
        }
        for (int i = 0; i <= n; i ++ ) {
            for (int j = 0; j <= k; j ++ ) {
                f[i][j] = -INF;
            }
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i ++ ) {
            cres[i] = cres[i - 1];
            if (i >= 2) {
                f[i][1] = cres[i - 2] - d;
                f[i][0] = cres[i - 2];
            }
            for (int j = 1; j <= k; j ++ ) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] - d);
                cres[i] = max(cres[i], f[i][j]);
            }
            for (auto j : qt[i]) {
                for (int tk = j.first; tk <= k; tk ++ ) {
                    f[i][tk] += j.second;
                    cres[i] = max(cres[i], f[i][tk]);
                }
            }
        }
        cout << cres[n] << '\n';
    }
    return 0;
}
/*
wow.
30 min left.
thx u. hope next meet!

a lot of things!

hai shi shen me dou bu hui a.
ha ha !

*/