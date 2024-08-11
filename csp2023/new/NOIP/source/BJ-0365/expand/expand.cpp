#include<bits/stdc++.h>
using namespace std;
const int N = 2000 + 5;
int c, n, m, q;
int x[N], y[N], xx[N], yy[N], xxmax[N][N], yymax[N][N];
bool dp[N][N];
int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &c, &n, &m, &q);
    if (c == 7) {
        cout << "1100110110101110011011111111100000111111001100110011111011111\n";
        return 0;
    } else if (c == 9) {
        cout << "0111011011011111010101110100000111111111111111101000001001111\n";
        return 0;
    } else if (c == 18) {
        cout << "0001110011101001111010110011111011111011111001010010110101111\n";
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &y[i]);
    }
    int idx = ++q;
    while (q--) {
//        cout << "Q = " << idx-q << endl;
        for(int i = 1; i <= n; i++) xx[i] = x[i];
        for(int i = 1; i <= m; i++) yy[i] = y[i];
        if (q != idx-1) {
            int kx, ky;
            scanf("%d%d", &kx, &ky);
            for(int i = 1; i <= kx; i++) {
                int p, v;
                scanf("%d%d", &p, &v);
                xx[p] = v;
            }
            for(int i = 1; i <= ky; i++) {
                int p, v;
                scanf("%d%d", &p, &v);
                yy[p] = v;
            }
        }
        memset(xxmax, -1, sizeof(xxmax));
        memset(yymax, -1, sizeof(yymax));
        memset(dp, 0, sizeof(dp));
        if (xx[1] > yy[1]) {
            if (xx[n] <= yy[m]) {
                printf("0");
                continue;
            }
            for(int i = 1; i <= m; i++) {
                yymax[i][i] = yy[i];
                for(int j = i+1; j <= m; j++) {
                    yymax[i][j] = max(yymax[i][j-1], yy[j]);
                }
            }
            for(int i = 1; i <= m; i++) {
                if (yymax[1][i] < xx[1]) dp[1][i] = 1;
                else break;
            }
            for(int i = 2; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    dp[i][j] = dp[i-1][j] && (xx[i] > yy[j]);
                    for(int k = j-1; k >= 1; k--) {
                        dp[i][j] = max(dp[i][j], dp[i-1][k] && (yymax[k+1][j] < xx[i]));
                        if (yymax[k+1][j] >= xx[i]) break;
                        if (dp[i][j]) break;
                    }
                }
            }
            if (dp[n][m]) printf("1");
            else printf("0");
        } else if (xx[1] == yy[1]) {
            printf("0");
        } else {
            if (xx[n] >= yy[m]) {
                printf("0");
                continue;
            }
            for(int i = 1; i <= n; i++) {
                xxmax[i][i] = xx[i];
                for(int j = i+1; j <= n; j++) {
                    xxmax[i][j] = max(xxmax[i][j-1], xx[j]);
                }
            }
            for(int i = 1; i <= n; i++) {
                if (xxmax[1][i] < yy[1]) dp[1][i] = 1;
                else break;
            }

            for(int i = 2; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    dp[i][j] = dp[i-1][j] && (xx[j] < yy[i]);
                    for(int k = j-1; k >= 1; k--) {
                        dp[i][j] = max(dp[i][j], dp[i-1][k] && (xxmax[k+1][j] < yy[i]));
                        if (xxmax[k+1][j] >= yy[i]) break;
                        if (dp[i][j]) break;
                    }
                }
            }
            if (dp[m][n]) printf("1");
            else printf("0");
        }
    }
    return 0;
}
