#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1e5 + 10;
int C, T, n, m, K, D;

struct Seg {
    int l, r, w;
    int len() {return r - l + 1;}
    void print() {cout << l << ' ' << r << ' ' << w << '\n';}
    bool operator < (const Seg &seg) const {
        return r < seg.r;
    }
} a[M];

vector<int> f[M];
int g[M];

void MAIN() {
    cin >> n >> m >> K >> D;
    for(int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w;
        a[i] = {x - y + 1, x, w};
    }
    sort(a + 1, a + m + 1);
    if(C == 17 || C == 18) {
        int ans = 0;
        for(int i = 1; i <= m; i++) if(a[i].len() <= K && a[i].w > a[i].len() * D) ans += a[i].w - a[i].len() * D;
        cout << ans << endl;
        return;
    }
    for(int i = 0; i <= m; i++) f[i].clear(), g[i] = 0;
    for(int i = 0; i <= m; i++) for(int j = 0; j <= K; j++) f[i].push_back(0);
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= min(a[i].r, K); j++)
            if(a[i].l < a[i - 1].r) {
                int p = a[i].r - j + 1;
                if(p > a[i - 1].r + 1) f[i][j] = g[i - 1] - j * D;
                else if(p > a[i].l) f[i][j] = f[i - 1][a[i - 1].r - p + 1] - (a[i].r - a[i - 1].r) * D;
                else f[i][j] = f[i - 1][a[i - 1].r - p + 1] - (a[i].r - a[i - 1].r) * D + a[i].w;
                g[i] = max(g[i], f[i][j]);
            }
            else if(a[i].l > a[i - 1].r) {
                int p = a[i].r - j + 1;
                if(p > a[i].l) f[i][j] = g[i - 1] - j * D;
                else if(p > a[i - 1].r + 1) f[i][j] = g[i - 1] - j * D + a[i].w;
                else f[i][j] = f[i - 1][a[i - 1].r - p + 1] - (a[i].r - a[i - 1].r) * D + a[i].w;
                g[i] = max(g[i], f[i][j]);
            }
            else {
                int p = a[i].r - j + 1, J = a[i].l;
                if(p > J + 1) f[i][j] = g[i - 1] - j * D;
                else if(p == J + 1) f[i][j] = f[i - 1][J - p + 1] - (a[i].r - J) * D;
                else f[i][j] = f[i - 1][J - p + 1] - (a[i].r - J) * D + a[i].w;
                g[i] = max(g[i], f[i][j]);
            }
    }
    cout << g[m] << endl;
    return;
}

signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> C >> T;
    while(T--) MAIN();
    return 0;
}