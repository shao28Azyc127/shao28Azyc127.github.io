#include <bits/stdc++.h>
using namespace std;

int C, n, m, q, a[500100], b[500100];
int ta[500100], tb[500100];
bool f[2100][2100];
int work(int fl) {
    if(C > 7) { return ta[n] < tb[m]; }
    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
        if(ta[i] * fl <= tb[j] * fl) { f[i][j] = 0; continue; }
        f[i][j] = f[i - 1][j] | f[i][j - 1] | f[i - 1][j - 1];
    } return f[n][m];
}
int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d", &C, &n, &m, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), ta[i] = a[i];
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]), tb[i] = b[i];
    printf((work(-1) || work(1)) ? "1" : "0");
    while(q--) {
        int kx, ky, p, v; scanf("%d%d", &kx, &ky);
        for(int i = 1; i <= n; i++) ta[i] = a[i];
        for(int i = 1; i <= m; i++) tb[i] = b[i];
        for(int i = 1; i <= kx; i++)
            scanf("%d%d", &p, &v), ta[p] = v;
        for(int i = 1; i <= ky; i++)
            scanf("%d%d", &p, &v), tb[p] = v;
        printf((work(-1) || work(1)) ? "1" : "0");
    } return 0;
}
