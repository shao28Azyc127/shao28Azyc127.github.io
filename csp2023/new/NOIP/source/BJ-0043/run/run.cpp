#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define maxn 400005
#define maxm 1005
#define inf 0x3f3f3f3f
using namespace std;
int C, T;
int n, m, k;
ll d;
struct node {
    int day; ll val;
};
vector <node> g[maxn];
ll f[maxm][maxm], add[maxn];
int x[maxn], y[maxn]; ll v[maxn];
int inq[maxn], N = 0;
ll F[maxn], _F[maxn];
int main () {
    freopen ("run.in", "r", stdin);
    freopen ("run.out", "w", stdout);
    scanf ("%d %d", &C, &T);
    while (T--) {
        N = 0;
        scanf ("%d %d %d %lld", &n, &m, &k, &d);
        if (C <= 9) for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
            scanf ("%d %d %lld", x+i, y+i, v+i);
            if (y[i] > k) continue;
            inq[++N] = x[i], inq[++N] = x[i]-y[i];
            if (C <= 9) g[x[i]].push_back((node){y[i], v[i]});
        }
        sort (inq+1, inq+N+1);
        N = unique (inq+1, inq+N+1) - inq - 1;
        if (C <= 9) {
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= k; j++)
                    f[i][j] = -1e15;
            f[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < k; j++)
                    f[i][j+1] = max (f[i][j+1], f[i-1][j]-d),
                    f[i][0] = max (f[i][0], f[i-1][j]), add[j+1] = 0;
                f[i][0] = max (f[i][0], f[i-1][k]);
                for (int j = 0; j < g[i].size(); j++)
                    add[g[i][j].day] += g[i][j].val;
                for (int j = 1; j <= k; j++)
                    add[j] += add[j-1];
                for (int j = 1; j <= k; j++)
                    f[i][j] += add[j];
            }
            ll ans = -1e15;
            for (int j = 0; j <= k; j++)
                ans = max (ans, f[n][j]);
            printf ("%lld\n", ans);
            continue;
        }
        for (int i = 1; i <= N; i++) g[i].clear();
        for (int i = 1; i <= m; i++)
            x[i] = lower_bound(inq+1, inq+N+1, x[i]) - inq,
            g[x[i]].push_back((node){y[i], v[i]});
        for (int i = 1; i <= k; i++) F[i] = -1e15; F[0] = 0;
        inq[0] = 0;
        for (int i = 1; i <= N; i++) {
            if (inq[i] == 0) continue;
            int len = inq[i] - inq[i-1];
            for (int j = 0; j <= k; j++) _F[j] = -1e15;
            for (int j = 0; j <= k; j++) {
                _F[0] = max (_F[0], F[j]), add[j] = 0;
                if (j + len <= k) _F[j+len] = max (_F[j+len], F[j] - len*d);
            }
            for (int j = 0; j < g[i].size(); j++) add[g[i][j].day] += g[i][j].val;
            for (int j = 1; j <= k; j++) add[j] += add[j-1];
            for (int j = 0; j <= k; j++) F[j] = _F[j] + add[j];
        }
        ll ans = -1e15;
        for (int i = 0; i <= k; i++) ans = max (ans, F[i]);
        printf ("%lld\n", ans);
    }
    return 0;
}