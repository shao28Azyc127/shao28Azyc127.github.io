#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define nrep(i, a, b) for(int i = (a); i >= (b); --i)
#define put(x) printf("%d ", x)
#define endl() putchar('\n')
using namespace std;

typedef long long ll;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = (x << 1) +(x << 3) + (ch ^ 48), ch = getchar();
    return x * f;
}

const int N = 1e5 + 10, K = 2200;
int n, m, q;
int a[N], b[N], _a[N], _b[N];
int ma[N], mb[N];
int f[K][K];
int block[K][K];

bool brute(int *a, int n, int *b, int m) {
//    int i = 1, j = 1;
//    a[n + 1] = 1e9;
//    b[m + 1] = -1;
//    rep(t, 1, n) {
//        while(i <= n && b[j] < a[i]) i++;
//        while(j <= m && b[j] < a[i]) j++;
//    }
//    print(i, j);
//    return i == n + 1 && j == m + 1;
//    ma[0] = mb[0] = 1e9;
//    rep(i, 1, n) ma[i] = min(ma[i - 1], a[i]);
//    rep(i, 1, m) mb[i] = min(mb[i - 1], b[i]);
//    bool flag = 1;
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    rep(i, 1, n) rep(j, 1, m) {
        if(!(a[i] > b[j])) { block[i][j] = 1; continue; }
        f[i][j] |= f[i - 1][j - 1];
        f[i][j] |= f[i][j - 1];
        f[i][j] |= f[i - 1][j];
//        if(f[i][j]) print(i, j, a[i], b[j]);
    }
    return f[n][m];
}

void sub1_brute() {
    n = read(), m = read(), q = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 1, m) b[i] = read();
    bool ans = brute(a, n, b, m) || brute(b, m, a, n);
    printf("%d", ans);
//        rep(i, 1, n) put(a[i]); endl();
//        rep(i, 1, m) put(b[i]); endl();
//    rep(i, 1, n) {
//        rep(j, 1, m) cerr << f[i][j] << " "; cerr << endl;
//    } cerr << endl;
//
//    rep(i, 1, n) {
//        rep(j, 1, m) cerr << block[i][j] << " "; cerr << endl;
//    } cerr << endl;
    while(q--) {
        rep(i, 1, n) _a[i] = a[i]; rep(i, 1, m) _b[i] = b[i];
        int kx = read(), ky = read(), p, v;
        rep(i, 1, kx) p = read(), v = read(), a[p] = v;
        rep(i, 1, ky) p = read(), v = read(), b[p] = v;
        bool ans = brute(a, n, b, m) || brute(b, m, a, n);
        printf("%d", ans);
//        endl();
//        rep(i, 1, n) put(a[i]); endl();
//        rep(i, 1, m) put(b[i]); endl();
        rep(i, 1, n) a[i] = _a[i]; rep(i, 1, m) b[i] = _b[i];
    }
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

//    freopen("ext.out", "w", stderr);

    int Case = read();
    if(Case <= 7) sub1_brute();
    return 0;
}



















