#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 23, stdin), p1 == p2) ? EOF : *p1++)
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
    return x * f;
}
const int N = 5e5 + 5;
int n, m, q, x[N], y[N], tx[N], ty[N], c;
bool f[2005][2005];
inline void calc(int *x, int *y, int n, int m) {
    if (x[1] == y[1]) { putchar('0'); return; }
    if (x[1] < y[1]) swap(x, y), swap(n, m);
    if (x[n] <= y[m]) { putchar('0'); return; }
    // if (flg) cerr << now[y[1]] << endl;
    int mxx = 0;
    rep(i, 1, n) mxx = max(mxx, x[i]);
    int mny = 0x3f3f3f3f;
    rep(i, 1, m) mny = min(mny, y[i]);
    rep(i, 1, n) if (x[i] <= mny) { putchar('0'); return; }
    rep(i, 1, m) if (y[i] >= mxx) { putchar('0'); return; }
    memset(f, 0, sizeof(f));
    f[1][1] = 1;
    rep(i, 1, n) rep(j, 1, m) if (f[i][j]) {
        if (j < m && x[i] > y[j + 1]) f[i][j + 1] = 1;
        if (i < n && x[i + 1] > y[j]) f[i + 1][j] = 1;
        if (i < n && j < m && x[i + 1] > y[j + 1]) f[i + 1][j + 1] = 1;
    }
    if (f[n][m]) putchar('1');
    else putchar('0');
}
namespace sub {
    int mn[20][N], mx[20][N];
vector<int> ned, ned1;
    inline int qmn(int l, int r) {
        int k = __lg(r - l + 1);
        return min(mn[k][l], mn[k][r - (1 << k) + 1]);
    }
    inline int qmx(int l, int r) {
        int k = __lg(r - l + 1);
        return max(mx[k][l], mx[k][r - (1 << k) + 1]);
    }
    // bool flg = 0;
    inline void calc(int *x, int *y, int n, int m) {
    if (x[1] == y[1]) { putchar('0'); return; }
    if (x[1] < y[1]) swap(x, y), swap(n, m);
    if (x[n] <= y[m]) { putchar('0'); return; }
    // if (flg) cerr << now[y[1]] << endl;
    int mxx = 0;
    rep(i, 1, n) mxx = max(mxx, x[i]);
    int mny = 0x3f3f3f3f;
    rep(i, 1, m) mny = min(mny, y[i]);
    rep(i, 1, n) if (x[i] <= mny) { putchar('0'); return; }
    rep(i, 1, m) if (y[i] >= mxx) { putchar('0'); return; }
    rep(i, 1, n) mn[0][i] = mx[0][i] = x[i];
    rep(i, 1, 19) {
        rep(j, 1, n - (1 << (i - 1))) {
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
        }
    }
    ned.clear(); ned1.clear();
    // x[1] > y[1], x[n] > y[m]
    int smx = -1;
    rep(i, 1, m) {
        if (y[i] > smx) {
            smx = y[i];
            ned.emplace_back(i);
        }
    }
    smx = -1;
    per(i, m, 1) {
        if (y[i] > smx) {
            smx = y[i];
            ned1.emplace_back(i);
        }
    }
    reverse(ned1.begin(), ned1.end());
    int szz = ned1.size();
    rep(i, 0, szz - 1) if (ned1[i] != ned.back()) ned.emplace_back(ned1[i]);
    int sz = ned.size(), nl = 1, nr = 1, lst = 0;
    rep(i, 0, sz - 1) {
        // if (flg) cerr << ned[i] << " " << nl << " " << nr << endl;
        // lst + 1 ~ ned[i]
        int tmn = 0x3f3f3f3f;
        rep(j, lst + 1, ned[i]) tmn = min(tmn, y[j]);
        // nl, tmn
        int L = nr, R = n;
        while (L < R) {
            int mid = (L + R + 1) >> 1;
            if (qmn(nr + 1, mid) > tmn) L = mid;
            else R = mid - 1;
        }
        int lstR = L;
        // if (flg) cerr << "mn: " << lstR << endl;
        // nl, L
        L = 0; R = lstR;
        while (L < R) {
            int mid = (L + R + 1) >> 1;
            if (qmx(mid, lstR) > y[ned[i]]) L = mid;
            else R = mid - 1;
        }
        lstR = L;
        if (!L) { putchar('0'); return; }
        L = 1, R = lstR;
        while (L < R) {
            int mid = (L + R) >> 1;
            if (qmn(mid, lstR) > y[ned[i]]) R = mid;
            else L = mid + 1;
        }
        nl = L; nr = lstR;
        lst = ned[i];
    }
    // cerr << nr << endl;
    if (nr == n) putchar('1');
    else putchar('0');
}
    void Main() {
        rep(i, 1, n) tx[i] = x[n - i + 1];
        rep(i, 1, m) ty[i] = y[m - i + 1];
        calc(tx, ty, n, m);
        rep(i, 1, q) {
            rep(i, 1, n) tx[i] = x[n - i + 1];
            rep(i, 1, m) ty[i] = y[m - i + 1];
            int kx = read(), ky = read();
            rep(j, 1, kx) {
                int p = read(), v = read();
                tx[n - p + 1] = v;
            }
            rep(j, 1, ky) {
                int p = read(), v = read();
                ty[m - p + 1] = v;
            }
            calc(tx, ty, n, m);
            // flg = 0;
        }
    }
}
signed main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    c = read(); n = read(); m = read(); q = read();
    rep(i, 1, n) x[i] = read();
    rep(i, 1, m) y[i] = read();
    if (c >= 8) {
        sub::Main();
        return 0;
    }
    rep(i, 1, n) tx[i] = x[i];
    rep(i, 1, m) ty[i] = y[i];
    calc(tx, ty, n, m);
    rep(i, 1, q) {
        rep(i, 1, n) tx[i] = x[i];
        rep(i, 1, m) ty[i] = y[i];
        int kx = read(), ky = read();
        rep(j, 1, kx) {
            int p = read(), v = read();
            tx[p] = v;
        }
        rep(j, 1, ky) {
            int p = read(), v = read();
            ty[p] = v;
        }
        calc(tx, ty, n, m);
    }
    return 0;
}