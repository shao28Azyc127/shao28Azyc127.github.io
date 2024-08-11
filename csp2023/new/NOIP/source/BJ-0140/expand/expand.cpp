#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int tid, n, m, q, a[N], b[N], oa[N], ob[N], lg[N], dp[2005][2005], f[2005][14];
bool ans[N];

inline int query1(int l, int r){
    int k = lg[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

inline int query2(int l, int r){
    int k = lg[r - l + 1];
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &tid, &n, &m, &q);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]), oa[i] = a[i];
    for (int i=1; i<=m; i++) scanf("%d", &b[i]), ob[i] = b[i];
    for (int i=2; i<=max(n, m); i++) lg[i] = lg[i >> 1] + 1;
    if (a[1] > b[1] && a[n] > b[m]){
        int nmx = b[1];
        for (int i=1; i<=m; i++){
            nmx = max(nmx, b[i]);
            if (a[1] > nmx) dp[1][i] = 1;
        }
        for (int i=1; i<=m; i++) f[i][0] = b[i];
        for (int j=1; (1<<j)<=m; j++) for (int i=1; i<=m-(1<<j)+1; i++) f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        for (int i=2; i<=n; i++) for (int j=1; j<=m; j++){
            dp[i][j] |= dp[i - 1][j] && (a[i] > b[j]);
            for (int k=1; k<j&&(!dp[i][j]); k++) dp[i][j] |= dp[i - 1][k] && (a[i] > query1(k + 1, j));
        }
        ans[0] = dp[n][m];
    }
    else if (a[1] < b[1] && a[n] < b[m]){
        int nmn = b[1];
        for (int i=1; i<=m; i++){
            nmn = min(nmn, b[i]);
            if (a[1] < nmn) dp[1][i] = 1;
        }
        for (int i=1; i<=m; i++) f[i][0] = b[i];
        for (int j=1; (1<<j)<=m; j++) for (int i=1; i<=m-(1<<j)+1; i++) f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        for (int i=2; i<=n; i++) for (int j=1; j<=m; j++){
            dp[i][j] |= dp[i - 1][j] && (a[i] < b[j]);
            for (int k=1; k<j&&(!dp[i][j]); k++) dp[i][j] |= dp[i - 1][k] && (a[i] < query2(k + 1, j));
        }
        ans[0] = dp[n][m];
    }
    int kx, ky, p, v;
    for (int kk=1; kk<=q; kk++){
        scanf("%d%d", &kx, &ky);
        for (int i=1; i<=kx; i++) scanf("%d%d", &p, &v), a[p] = v;
        for (int i=1; i<=ky; i++) scanf("%d%d", &p, &v), b[p] = v;
        // printf("for ask %d:\na: ", kk);
        // for (int i=1; i<=n; i++) printf("%d ", a[i]); printf("\nb: ");
        // for (int i=1; i<=m; i++) printf("%d ", b[i]); printf("\n");
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) dp[i][j] = 0;
        if (a[1] > b[1] && a[n] > b[m]){
            for (int i=1; i<=m; i++) for (int j=0; j<14; j++) f[i][j] = 0;
            int nmx = b[1];
            for (int i=1; i<=m; i++){
                nmx = max(nmx, b[i]);
                if (a[1] > nmx) dp[1][i] = 1;
            }
            for (int i=1; i<=m; i++) f[i][0] = b[i];
            for (int j=1; (1<<j)<=m; j++) for (int i=1; i<=m-(1<<j)+1; i++) f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            for (int i=2; i<=n; i++) for (int j=1; j<=m; j++){
                dp[i][j] |= dp[i - 1][j] && (a[i] > b[j]);
                for (int k=1; k<j&&(!dp[i][j]); k++) dp[i][j] |= dp[i - 1][k] && (a[i] > query1(k + 1, j));
            }
            ans[kk] = dp[n][m];
        }
        else if (a[1] < b[1] && a[n] < b[m]){
            for (int i=1; i<=m; i++) for (int j=0; j<14; j++) f[i][j] = 2e9;
            int nmn = b[1];
            for (int i=1; i<=m; i++){
                nmn = min(nmn, b[i]);
                if (a[1] < nmn) dp[1][i] = 1;
            }
            for (int i=1; i<=m; i++) f[i][0] = b[i];
            for (int j=1; (1<<j)<=m; j++) for (int i=1; i<=m-(1<<j)+1; i++) f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            for (int i=2; i<=n; i++) for (int j=1; j<=m; j++){
                dp[i][j] |= dp[i - 1][j] && (a[i] < b[j]);
                for (int k=1; k<j&&(!dp[i][j]); k++) dp[i][j] |= dp[i - 1][k] && (a[i] < query2(k + 1, j));
            }
            ans[kk] = dp[n][m];
        }
        for (int i=1; i<=n; i++) a[i] = oa[i];
        for (int i=1; i<=m; i++) b[i] = ob[i];
    }
    for (int i=0; i<=q; i++) printf("%d", ans[i]);
    return 0;
}
