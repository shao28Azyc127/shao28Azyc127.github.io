#include <bits/stdc++.h>
typedef std::pair<int, int> P;
const int MAXN = 500005, lgMAXN = 22;
int n, m, a[MAXN], b[MAXN], st[MAXN], x[MAXN], y[MAXN];
int px[MAXN], vx[MAXN], py[MAXN], vy[MAXN];
int f[2][MAXN][lgMAXN];

// namespace Sub1 {
//     const int MAXN = 40005;
//     std::bitset<MAXN> S[MAXN], res;
//     P a[MAXN], b[MAXN];
//     int tn, tm;

//     inline bool cmpa(int x, int y) {
//         return a[x] < a[y];
//     }

//     inline bool cmpb(int x, int y) {
//         return b[x] < b[y];
//     }

//     bool solve() {
//         if(x[1] == y[1] || x[n] == y[m] || ((x[1] < y[1]) ^ (x[n] < y[m])))
//             return false;
//         if(x[1] > y[1]) {
//             tn = m, tm = n;
//             for(int i = 1; i <= tn; ++i)
//                 a[i].first = y[i], a[i].second = i;
//             for(int i = 1; i <= tm; ++i)
//                 b[i].first = x[i], b[i].second = i;
//         }
//         else {
//             tn = n, tm = m;
//             for(int i = 1; i <= tn; ++i)
//                 a[i].first = x[i], a[i].second = i;
//             for(int i = 1; i <= tm; ++i)
//                 b[i].first = y[i], b[i].second = i;
//         }
//         std::sort(a + 1, a + tn + 1);
//         std::sort(b + 1, b + tm + 1);
//         int cur = 1;
//         S[0].set();
//         for(int i = 1; i <= tn; ++i) {
//             S[a[i].second] = S[a[i - 1].second];
//             while(cur <= tm && a[i].first >= b[cur].first)
//                 S[a[i].second][b[cur++].second] = 0;
//         }
//         res.reset();
//         res[0] = 1;
//         for(int i = 1; i <= tn; ++i) {
//             for(int j = 1; j <= tn; j <<= 1)
//                 res <<= j, res &= S[i];
//         }
//         return res[tm];
//     }
// }

int jump0(int pos, int v) {
    for(int i = 31 - __builtin_clz(m); i >= 0; --i) {
        int t = f[0][pos][i];
        if(t && b[t] <= v)
            pos = t;
    }
    return f[0][pos][0];
}

int jump1(int pos, int v) {
    for(int i = 31 - __builtin_clz(m); i >= 0; --i) {
        int t = f[1][pos][i];
        if(t && b[t] > v)
            pos = t;
    }
    if(!f[1][pos][0])
        return m;
    return jump0(f[1][pos][0], v);
}

bool solve() {
    if(x[1] == y[1] || x[n] == y[m] || ((x[1] < y[1]) ^ (x[n] < y[m])))
        return false;
    bool flag = false;
    if(x[1] > y[1])
        flag = true;
    if(flag) {
        std::swap(n, m);
        for(int i = 1; i <= n; ++i)
            a[i] = y[i];
        for(int i = 1; i <= m; ++i)
            b[i] = x[i];
    }
    else {
        for(int i = 1; i <= n; ++i)
            a[i] = x[i];
        for(int i = 1; i <= m; ++i)
            b[i] = y[i];
    }
    int top = 1;
    for(int i = 1; i <= m; ++i) {
        while(top && b[i] >= b[st[top]])
            --top;
        st[++top] = i;
        for(int j = 0; j <= 20; ++j)
            f[0][i][j] = 0;
        for(int j = 0; top - (1 << j) > 0; ++j)
            f[0][i][j] = st[top - (1 << j)];
    }
    top = 0;
    for(int i = m; i >= 1; --i) {
        while(top && b[i] <= b[st[top]])
            --top;
        st[++top] = i;
        for(int j = 0; j <= 20; ++j)
            f[1][i][j] = 0;
        for(int j = 0; top - (1 << j) > 0; ++j)
            f[1][i][j] = st[top - (1 << j)];
    }
    int cur = jump1(1, a[1]);
    for(int i = 1; i <= n; ++i) {
        //std::cout << cur << '\n';
        if(!cur)
            return false;
        if(a[i] < b[cur])
            cur = jump1(cur, a[i]);
        else
            cur = jump0(cur, a[i]);
    }
    if(flag)
        std::swap(n, m);
    return cur == m;
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int sid, q;
    std::cin >> sid >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
        std::cin >> x[i];
    for(int i = 1; i <= m; ++i)
        std::cin >> y[i];
    std::cout << solve();
    while(q--) {
        int kx, ky;
        std::cin >> kx >> ky;
        for(int i = 1; i <= kx; ++i)
            std::cin >> px[i] >> vx[i], std::swap(x[px[i]], vx[i]);
        for(int i = 1; i <= ky; ++i)
            std::cin >> py[i] >> vy[i], std::swap(y[py[i]], vy[i]);
        std::cout << solve();
        for(int i = 1; i <= kx; ++i)
            x[px[i]] = vx[i];
        for(int i = 1; i <= ky; ++i)
            y[py[i]] = vy[i];
    }
    std::cout << '\n';
    return 0;
}