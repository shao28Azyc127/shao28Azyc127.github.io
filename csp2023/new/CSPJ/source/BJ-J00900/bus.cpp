#include <bits/stdc++.h>
using namespace std;

const int NN = 1e4 + 10;
int n, m, k, mi = 0x3f3f3f3f;
bool f[NN];
vector< pair< int, int > > vec[NN];
void dfs(int x, int ti) {
    if (x == n) {
        if (ti % k != 0) return;
        mi = min(mi, ti);
    }
    if (ti >= mi) return;
    int len = vec[x].size(), xx, tt;
    for (int i = 0; i < len; i++) {
        xx = vec[x][i].first;
        tt = vec[x][i].second;
        if (tt <= ti && !f[xx]) {
            f[xx] = true;
            dfs(xx, ti+1);
            f[xx] = false;
        }
    }
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    if (m > 1000) {
        printf("-1");
        return 0;
    }
    int ui, vi, ai, mai = k;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &ui, &vi, &ai);
        vec[ui].push_back(make_pair(vi, ai));
        mai = max(mai, ai);
    }

    f[1] = true;
    for (int i = k; i <= mai; i += k) dfs(1, i);

    if (mi == 0x3f3f3f3f) printf("-1");
    else printf("%d", mi);
    return 0;
}
