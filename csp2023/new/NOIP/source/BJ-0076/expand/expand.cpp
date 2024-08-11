#include <bits/stdc++.h>

using namespace std;

const int NR = 2000 + 5;
const int MR = 5e5 + 5;

char *p1, *p2, buf[1000000];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1 ++)
inline int read() {
    int x = 0; char c = gc();
    while (c < '0' || c > '9') c = gc();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = gc();
    return x;
}

int c, n, m, q, a[MR], b[MR], nxt[MR];
bool f[NR][NR];
vector < pair < int, int > > ra, rb;

inline void dp() {
    f[0][0] = 1;
    if (a[1] < b[1] && a[n] < b[m]) {
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= m; ++j) {
                if (a[i] < b[j]) f[i][j] = f[i - 1][j - 1] | f[i - 1][j] | f[i][j - 1];
                else f[i][j] = 0;
            }
        cout << f[n][m];
    }
    else if (a[1] > b[1] && a[n] > b[m]) {
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= m; ++j) {
                if (a[i] > b[j]) f[i][j] = f[i - 1][j - 1] | f[i - 1][j] | f[i][j - 1];
                else f[i][j] = 0;
            }
        cout << f[n][m];
    }
    else cout << '0';
}

inline void solve() {
    if (a[1] < b[1] && a[n] < b[m]) {
        int pl = 1;
        for (int i = 1; i <= m; ) {
            int p = i + 1, mp = i;
            while (p <= m && b[p] < b[i]) {
                if (b[p] < b[mp]) mp = p;
                p ++;
            }
            int mx = 0;
            while (pl <= n && a[pl] < b[i]) {
                if (a[pl] < b[mp]) mx = max(mx, pl);
                pl ++;
            }
            if (!mx) return cout << 0, void();
            pl = mx, i = mp + 1;
        }
        cout << 1;
    }
    else if (a[1] > b[1] && a[n] > b[m]) {
        int pl = 1;
        for (int i = 1; i <= n; ) {
            int p = i + 1, mp = i;
            while (p <= n && a[p] < a[i]) {
                if (a[p] < a[mp]) mp = p;
                p ++;
            }
            int mx = 0;
            while (pl <= m && b[pl] < a[i]) {
                if (b[pl] < a[mp]) mx = max(mx, pl);
                pl ++;
            }
            if (!mx) return cout << 0, void();
            pl = mx, i = mp + 1;
        }
        cout << 1;
    }
    else cout << '0';
}

signed main() {
    ios :: sync_with_stdio(false), cin.tie(0);
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    c = read(), n = read(), m = read(), q = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i) b[i] = read();
    if (n <= 2000 && m <= 2000) dp();
    else solve();
    while (q --) {
        int ca, cb; ca = read(), cb = read(), ra.clear(), rb.clear();
        for (int i = 1, x, y; i <= ca; ++i) x = read(), y = read(), ra.push_back(make_pair(x, a[x])), a[x] = y;
        for (int i = 1, x, y; i <= cb; ++i) x = read(), y = read(), rb.push_back(make_pair(x, b[x])), b[x] = y;
        if (n <= 2000 && m <= 2000) dp();
        else solve();
        for (auto it : ra) {
            int x = it.first, y = it.second;
            a[x] = y;
        }
        for (auto it : rb) {
            int x = it.first, y = it.second;
            b[x] = y;
        }
    }
    return 0;
}