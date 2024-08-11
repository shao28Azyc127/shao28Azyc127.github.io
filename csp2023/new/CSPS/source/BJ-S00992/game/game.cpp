#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 5;
int f[N], lst[N], mto[N];
char ch[N];
namespace Bf {
    bool dp[805][805];
    void Main(int n) {
        LL Ans = 0;
        for (int i = 1; i < n; i++) if (ch[i] == ch[i + 1]) dp[i][i + 1] = 1, Ans++;
        for (int len = 4; len <= n; len += 2) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                if (ch[l] == ch[r] && dp[l + 1][r - 1]) dp[l][r] = 1;
                else {
                    for (int k = l + 1; k < r; k += 2) if (ch[k + 1] == ch[r] && dp[l][k] && (r - k == 2 || dp[k + 2][r - 1])) { dp[l][r] = 1; break; }
                }
                if (dp[l][r]) Ans++;
            }
        }
        for (int r = 1; r <= n; r++) {
            int cnt = 0;
            for (int l = r - 1; l > 0; l -= 2) {
                if (dp[l][r]) cnt++; // printf("(%d, %d), ", l, r);
            }
            printf("%d%c", cnt, " \n"[r == n]);
        }
        printf("%lld\n", Ans);
    }
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n; scanf("%d%s", &n, ch + 1);
    // Bf::Main(n);
    int now = 0;
    for (int i = 2; i <= n; i++) {
        if (now == 0) {
            if (ch[i] == ch[i - 1]) f[i] = 1, now = i - 1, f[i] = f[now - 1] + 1, mto[i] = now;
        } else {
            while (now && ch[now - 1] != ch[i]) now = mto[now - 1];
            if (ch[i] == ch[i - 1]) {
                lst[i - 1] = now - 1; now = i - 1;
            } else if (now) now--;
            if (now) f[i] = f[now - 1] + 1, mto[i] = now;
        }
        // printf("%d%c", now, " \n"[i == n]);
    }
    // for (int i = 1; i <= n; i++) printf("%d%c", lst[i], " \n"[i == n]);
    LL Ans = 0;
    // for (int i = 1; i <= n; i++) printf("%d%c", f[i], " \n"[i == n]);
    for (int i = 1; i <= n; i++) Ans += f[i];
    printf("%lld\n", Ans);
    return 0;
}
/*
10
aabcbcbbdd
*/