#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000000;

int a[maxn], dp[maxn], in[maxn], pre[maxn][26];
int cnt, sz[maxn];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char ch;
        scanf(" %c", &ch);
        a[i] = ch - 'a';
    }
    cnt = 0;
    memset(dp, 0, sizeof(dp));
    memset(in, 0, sizeof(in));
    memset(pre, 0, sizeof(pre));
    memset(sz, 0, sizeof(sz));
    long long ans = 0;
    sz[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = pre[in[i - 1]][a[i]];
        if (dp[i] != 0) {
            in[i] = in[dp[i] - 1];
        } else {
            in[i] = ++cnt;
        }
        sz[in[i]]++;
        pre[in[i]][a[i]] = i;
        ans = ans + sz[in[i]] - 1;
        //printf("i=%d, dp=%d, in=%d, sz=%d, ans=%d\n", i, dp[i], in[i], sz[in[i]], ans);
    }
    printf("%lld\n", ans);
    return 0;
}
