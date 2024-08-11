#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2000006;
int n;
int s[N];
char c;
ll dp[N];
int go[N][26];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf(" %c", &c);
        s[i] = c - 'a';
        if (i == 1)
        {
            go[i][s[i]] = i;
            continue;
        }
        int now = go[i - 1][s[i]];
        if (now != 0) dp[i] = dp[now - 1] + 1;
        ans += dp[i];
        for (int j = 0; j < 26; j++)
            go[i][j] = go[now - 1][j];
        go[i][s[i]] = i;
    }
    printf("%lld\n", ans);
    return 0;
}
