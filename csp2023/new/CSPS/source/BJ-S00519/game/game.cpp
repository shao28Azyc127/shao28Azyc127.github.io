#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010;
char ch[maxn];
long long f[maxn][maxn];
long long dp(int l, int r)
{
    if(l >= r) return f[l][r] = 0;
    int ans = 1;
    if(ch[l] == ch[r]) if(dp(l - 1, r - 1) > ans) ans = dp(l - 1, r - 1);
    return f[l][r] = ans;
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    cin >> ch + 1;
    if(n <= 8000)
    {
        for(int i = 1; i <= n; i++) f[0][i] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) f[i][j] = 0;
        memset(f, -1, sizeof(f));
        cout << dp(1, n) << endl;
    }
    return 0;
}
