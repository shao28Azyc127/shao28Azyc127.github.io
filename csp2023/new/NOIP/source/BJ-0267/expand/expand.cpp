#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int INF = numeric_limits<int>::max();

int c, n, m, q;
int a[MAXN], b[MAXN];
int d[MAXN], e[MAXN]; // memo

inline int read() {
    int x = 0, f = 0, ch = getchar();
    while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x: x;
}

set<int> col[MAXN];
int ok;

inline bool check() {
    set<int> st;
    for (int i = 1; i <= m; i++) {
        if (!col[i].size())
            return false;
    }
    if (a[1] < b[1]) {
        // f[i] < g[i] holds for all i.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (col[j].count(i) && b[j] <= a[i])
                    return false;
            }
        }
        return true;
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (col[j].count(i) && b[j] >= a[i])
                    return false;
            }
        }
        return true;
    }
}

void dfs(int cur, int last) {
    if (cur == n + 1) {
        if (check()) ok = true;
        return;
    }
    for (int i = last; i <= m; i++) {
        for (int j = last; j <= i; j++) {
            col[j].insert(cur);
        }
        dfs(cur + 1, i);
        for (int j = last; j <= i; j++) {
            col[j].erase(cur);
        }
    }
}

inline void solve() {
    ok = 0;
    if (a[1] == b[1]) {
        putchar('0');
        return;
    }
    dfs(1, 1);
    putchar(ok ? '1' : '0');
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    c = read(), n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++) {
        a[i] = d[i] = read();
    }
    for (int i = 1; i <= m; i++) {
        b[i] = e[i] = read();
    }
    solve();
    while (q--) {
        int Kx = read(), Ky = read();
        while (Kx--) {
            int p = read(), v = read();
            a[p] = v;
        }
        while (Ky--) {
            int p = read(), v = read();
            b[p] = v;
        }
        solve();
        for (int i = 1; i <= n; i++) {
            a[i] = d[i];
        }
        for (int i = 1; i <= m; i++) {
            b[i] = e[i];
        }
    }
}