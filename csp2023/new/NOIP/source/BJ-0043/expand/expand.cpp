#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 500005
#define maxm 2005
using namespace std;
int C, n, m, q;
int x[maxn], y[maxn];
int a[maxn], b[maxn];
int qx, qy, _x[maxn], _y[maxn];
int sgn (int x) {
    if (x == 0) return 0;
    if (x > 0) return 1;
    return -1;
}
bool vis[maxm][maxm];
bool solve () {
    int Sgn = sgn(a[n]-b[m]);
    if (C <= 7) {
        memset (vis, false, sizeof vis);
        vis[n+1][m+1] = true;
        for (int i = n; i >= 1; i--)
            for (int j = m; j >= 1; j--) {
                if ((a[i]-b[j]) * Sgn <= 0) continue;
                vis[i][j] = vis[i+1][j] || vis[i][j+1] || vis[i+1][j+1];
            }
        return vis[1][1];
    }
}
int main () {
    freopen ("expand.in", "r", stdin);
    freopen ("expand.out", "w", stdout);
    scanf ("%d %d %d %d", &C, &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", x+i);
        a[i] = x[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf ("%d", y+i);
        b[i] = y[i];
    }
    printf ("%d", solve ());
    for (int i = 1; i <= q; i++) {
        scanf ("%d %d", &qx, &qy);
        for (int j = 1; j <= qx; j++) {
            scanf ("%d", _x+j);
            scanf ("%d", a+_x[j]);
        }
        for (int j = 1; j <= qy; j++) {
            scanf ("%d", _y+j);
            scanf ("%d", b+_y[j]);
        }
        printf ("%d", solve ());
        for (int j = 1; j <= qx; j++) a[_x[j]] = x[_x[j]];
        for (int j = 1; j <= qy; j++) b[_y[j]] = y[_y[j]];
    }
    return 0;
}