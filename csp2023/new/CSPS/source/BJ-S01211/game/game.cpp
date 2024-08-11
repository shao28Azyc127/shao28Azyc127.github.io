#include<bits/stdc++.h>
using namespace std;

long long n, ans;
string s;
bool f[200005][200005];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++)
        if(s[i] == s[i + 1]) f[i][i + 1] = 1;
    for(int len = 4; len <= n; len += 2)
        for(int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            if(f[l + 1][r - 1] && s[l] == s[r])
            {
                f[l][r] = 1;
                continue;
            }
            for(int k = l + 1; k <= r; k += 2)
            {
                if(f[l][k] != 0 && f[k + 1][r] != 0)
                {
                    f[l][r] = 1;
                }
            }
        }
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if(f[i][j]) ans++;
    cout << ans << endl;
    return 0;
}
