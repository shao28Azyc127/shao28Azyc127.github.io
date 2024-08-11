#include <bits/stdc++.h>

using namespace std;
int n;
char s[805];
bool f[805][805];
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i < n; i++)
        if (s[i] == s[i + 1]) f[i][i + 1] = true;
    for (int len = 3; len <= n; len++){
        for (int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;
            if (s[i] == s[j]) f[i][j] |= f[i + 1][j - 1];
            for (int k = i; k < j; k++)
                f[i][j] |= (f[i][k] && f[k + 1][j]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (f[i][j]) ans++;
    printf("%lld\n", ans);
    return 0;
}
