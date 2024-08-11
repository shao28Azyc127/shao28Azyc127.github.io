#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 2000;
int n, ans;
bool f[NR + 7][NR + 7];
string s;

signed main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    memset(f, false, sizeof(f));
    cin >> n >> s;
    s = ' ' + s;
    for(int i = 1; i <= n - 1; i++)
        if(s[i] == s[i + 1]) f[i][i + 1] = true;
    for(int len = 4; len <= n; len += 2)
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            for(int k = i + 1; k <= j; k += 2)
                if(f[i][k] & f[k + 1][j])
                {
                    f[i][j] = true;
                    break;
                }
            if(f[i + 1][j - 1] && s[i] == s[j]) f[i][j] = true;
        }
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if(f[i][j]) ans++;
    cout << ans << endl;
    return 0;
}
