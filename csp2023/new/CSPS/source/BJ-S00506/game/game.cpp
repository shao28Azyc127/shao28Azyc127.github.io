#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n, r;
string s;
long long ans;
bool f[8005][8005];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    scanf("%d", &n);
    cin >> s;

    if(s.length() > 8000)
    {
        puts("0");
        return 0;
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == s[i + 1])
        {
            f[i][i + 1] = true;
            ans++;
        }
    }
    for(int len = 3; len <= n; len += 2)
    {
        for(int l = 0; l < n; l++)
        {
            r = l + len;
            if(r >= n)  break;
            f[l][r] = (s[l] == s[r] && f[l + 1][r - 1] == true);
            for(int x = 1; (!f[l][r]) && x < len - 1; x += 2)
            {
                f[l][r] = f[l][l + x] == true && f[l + x + 1][r] == true;
            }
            ans += f[l][r];
        }
    }

    printf("%lld\n", ans);
    return 0;
}
