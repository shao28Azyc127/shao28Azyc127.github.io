#include <bits/stdc++.h>

#define getchar getchar_unlocked

using namespace std;

template<typename T = int>
inline T read() {
    int x = 0, f = 1;
    char ch = 0;
    while(!isdigit(ch = getchar())) {
        if (ch == '-') f = -1;
    }
    do x = x * 10 + ch - '0';
    while (isdigit(ch = getchar()));
    return x * f;
}

const int N = 10, M = 15;
int C, n, m, q, x[N], y[N], xx[N], yy[N], cx[M + 5], cy[M + 5];

bool dfs2(int u, int left) {
    if (u == m) {
        for (int j = M - left + 1; j <= M; j++) cy[j] = y[u];
        // for (int i = 1; i <= M; i++) cout << cx[i] << " ";
        // cout << endl;
        // for (int i = 1; i <= M; i++) cout << cy[i] << " ";
        // cout << endl;
        bool fg = true;
        for (int i = 1; i <= M && fg; i++)
            if (cx[i] <= cy[i])
                fg = false;
        return fg;
    }
    for (int i = 1; i <= left - (m - u); i++) {
        int s = M - left + 1;
        for (int j = 0; j < i; j++) cy[s + j] = y[u];
        if (dfs2(u + 1, left - i)) return true;
    }
    return false;
}

bool dfs1(int u, int left) {
    if (u == n) {
        for (int j = M - left + 1; j <= M; j++) cx[j] = x[u];
        return dfs2(1, M);
    }
    for (int i = 1; i <= left - (n - u); i++) {
        int s = M - left + 1;
        for (int j = 0; j < i; j++) cx[s + j] = x[u];
        if (dfs1(u + 1, left - i)) return true;
    }
    return false;
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    C = read(), n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++) x[i] = read();
    for (int i = 1; i <= m; i++) y[i] = read();
    memcpy(xx + 1, x + 1, sizeof(int) * (n + 1));
    memcpy(yy + 1, y + 1, sizeof(int) * (m + 1));
    if (x[1] < y[1]) swap(x, y);
    putchar(dfs1(1, M) + '0');
    while(q--) {
        int kx = read(), ky = read();
        memcpy(x + 1, xx + 1, sizeof(int) * (n + 1));
        memcpy(y + 1, yy + 1, sizeof(int) * (m + 1));
        for (int i = 1; i <= kx; i++) {
            int p = read(), v = read();
            x[p] = v;
        }
        for (int i = 1; i <= ky; i++) {
            int p = read(), v = read();
            y[p] = v;
        }
        if (x[1] < y[1]) swap(x, y);
        putchar(dfs1(1, M) + '0');
        // cout << endl;
        // for (int i = 1; i <= n; i++) cout << x[i] << " ";
        // cout << endl;
        // for (int i = 1; i <= m; i++) cout << y[i] << " ";
        // cout << endl;
    }
    puts("");
    fflush(stdout);
    return 0;
}