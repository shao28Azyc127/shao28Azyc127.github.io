#include <bits/stdc++.h>
typedef long long LL;
const int MAXN = 2000005;
int n;
char s[MAXN];
int f[MAXN], res[MAXN];

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, s + 1);
    for(int i = 1; i <= n; ++i) {
        int cur = i - 1;
        while(cur > 0 && s[cur] != s[i])
            cur = f[cur] - 1;
        if(cur > 0)
            f[i] = cur, res[i] = res[cur - 1] + 1;
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += res[i];
    std::cout << ans;
    return 0;
}