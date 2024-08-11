#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 5e5 + 5;

void read(int &x) {
    x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar());
    for (; isdigit(ch); ch = getchar())
        x = x * 10 + ch - 48;
}

int a[2][MAXN], b[2][MAXN], t1, t2 = 1;

bool f[2005][2005];
int g[2005];
bool check1(int n, int m) {
    if (a[0][1] == a[1][1] || a[0][n] == a[1][m]) return 0;
    if (a[0][1] < a[1][1] && a[0][n] > a[1][m]) return 0;
    if (a[0][1] > a[1][1] && a[0][n] < a[1][m]) return 0;
    t1 = 0, t2 = 1;
    if (a[0][1] > a[1][1]) t1 = 1, t2 = 0, swap(n, m);
    for (int i = 1; i <= m; i++) f[1][i] = 0;
    for (int i = 1; i <= m; i++) {
        if (a[t2][i] <= a[t1][1]) break;
        f[1][i] = 1;
    }
    for (int i = 1; i <= m; i++) g[i] = g[i - 1] + f[1][i];
    for (int i = 2; i <= n; i++) {
        int pos = 1e9;
        for (int j = 1; j <= m; j++) {
            if (a[t1][i] >= a[t2][j]) {f[i][j] = 0, pos = 1e9; continue;}
            pos = min(pos, j);
            int l = (pos == 1 ? 1 : pos - 1);
            f[i][j] = g[j] - g[l - 1];
        }
        for (int j = 1; j <= m; j++) g[j] = g[j - 1] + f[i][j];
    }
    return f[n][m];
}


struct SGT {
    int t[MAXN << 2];
    void pushup(int p) {t[p] = max(t[p << 1], t[p << 1 | 1]);}
    void build(int p, int l, int r) {
        if (l == r) {t[p] = a[t2][l]; return;}
        int mid = l + r >> 1;
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    int query(int p, int l, int r, int ql, int qr, int v) {
        if (t[p] <= v) return 0;
        if (l == r) return l;
        int mid = l + r >> 1;
        if (ql <= l && qr >= r) {
            if (t[p << 1 | 1] > v) return query(p << 1 | 1, mid + 1, r, ql, qr, v);
            return query(p << 1, l, mid, ql, qr, v);
        }
        int res = 0;
        if (qr > mid)
            res = query(p << 1 | 1, mid + 1, r, ql, qr, v);
        if (res) return res;
        return query(p << 1, l, mid, ql, qr, v);
    }
}sg1;
struct SGT2 {
    int t[MAXN << 2];
    void pushup(int p) {t[p] = min(t[p << 1], t[p << 1 | 1]);}
    void build(int p, int l, int r) {
        if (l == r) {t[p] = a[t2][l]; return;}
        int mid = l + r >> 1;
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }

    int query(int p, int l, int r, int ql, int qr, int v) {
        if (t[p] > v) return 0;
        if (l == r) return l;
        int mid = l + r >> 1;
        if (ql <= l && qr >= r) {
            if (t[p << 1] <= v) return query(p << 1, l, mid, ql, qr, v);
            return query(p << 1 | 1, mid + 1, r, ql, qr, v);
        }
        int res = 0;
        if (ql <= mid)
            res = query(p << 1, l, mid, ql, qr, v);
        if (res) return res;
        return query(p << 1 | 1, mid + 1, r, ql, qr, v);
    }
}sg2;

bool check(int n, int m) {
    if (a[0][1] == a[1][1] || a[0][n] == a[1][m]) return 0;
    if (a[0][1] < a[1][1] && a[0][n] > a[1][m]) return 0;
    if (a[0][1] > a[1][1] && a[0][n] < a[1][m]) return 0;
    t1 = 0, t2 = 1;
    if (a[0][1] > a[1][1]) t1 = 1, t2 = 0, swap(n, m);
    sg1.build(1, 1, m), sg2.build(1, 1, m);
    int now;
    for (int i = 1; i <= m; i++)
        if (a[t1][1] >= a[t2][i]) {now = i - 1; break;}
    for (int i = 2; i <= n; i++) {
        if (a[t1][i] == a[t1][i - 1]) continue;
        if (a[t1][i] < a[t1][i - 1]) {
            int pos = sg2.query(1, 1, m, now + 1, m, a[t1][i]);
            if (!pos) now = m; else now = pos - 1;
        }
        else {
            int pos = sg1.query(1, 1, m, 1, now, a[t1][i]);
            if (!pos) return 0;
            now = pos;
        }
    }
    return now == m;
}

int cid, n, m, totq;

int main() {
    // double st = clock();
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    read(cid), read(n), read(m), read(totq);
    for (int i = 1; i <= n; i++) read(a[0][i]), b[0][i] = a[0][i];
    for (int i = 1; i <= m; i++) read(a[1][i]), b[1][i] = a[1][i];
    if (cid <= 7) putchar(check1(n, m) + 48);
    else putchar(check(n, m) + 48);
    while (totq--) {
        for (int i = 1; i <= n; i++) a[0][i] = b[0][i];
        for (int i = 1; i <= m; i++) a[1][i] = b[1][i];
        int x, y, i, v; read(x), read(y);
        while (x--) read(i), read(v), a[0][i] = v;
        while (y--) read(i), read(v), a[1][i] = v;
        if (cid <= 7) putchar(check1(n, m) + 48);
        else putchar(check(n, m) + 48);
    }
    putchar('\n');
    // double ed = clock();
    // cerr << (ed - st) / CLOCKS_PER_SEC << '\n';
    return 0;
}