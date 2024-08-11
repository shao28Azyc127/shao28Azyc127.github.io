// 35pts
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
int c, n, m, q, a[N], b[N];
bool dp[2009][2009];
int slv() {
    if (a[1] == b[1]) return 0;
    else if (a[1] < b[1]) {
        if (a[n] >= b[m]) return 0;
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] > b[j]) {dp[i][j] = 0; continue;}
                if ((i > 1 && dp[i - 1][j]) || (j > 1 && dp[i][j - 1]) || (i > 1 && j > 1 && dp[i - 1][j - 1])) dp[i][j] = 1;
                else if (!(i == 1 && j == 1)) dp[i][j] = 0;
            }
        }
    } else {
        if (a[n] <= b[m]) return 0;
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] < b[j]) {dp[i][j] = 0; continue;}
                if ((i > 1 && dp[i - 1][j]) || (j > 1 && dp[i][j - 1]) || (i > 1 && j > 1 && dp[i - 1][j - 1])) dp[i][j] = 1;
                else if (!(i == 1 && j == 1)) dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}
int pos[2][N], vl[2][N], X[N], Y[N];
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); X[i] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]); Y[i] = b[i];
    }
    printf("%d", slv());
    while (q--) {
        int kx, ky; scanf("%d%d", &kx, &ky);
        for (int i = 1; i <= kx; i++) {
            scanf("%d%d", &pos[0][i], &vl[0][i]);
            a[pos[0][i]] = vl[0][i];
        }
        for (int i = 1; i <= ky; i++) {
            scanf("%d%d", &pos[1][i], &vl[1][i]);
            b[pos[1][i]] = vl[1][i];
        }
        printf("%d", slv());
        for (int i = 1; i <= kx; i++) {
            a[pos[0][i]] = X[pos[0][i]];
        }
        for (int i = 1; i <= ky; i++) {
            b[pos[1][i]] = Y[pos[1][i]];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
3 1 2 4 1
4 5 2

*/
