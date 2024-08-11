#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<map>
#include<cstring>
#include<vector>
#define int long long
using namespace std;

int f[2000010], a[2000010], cnt[2000010], ans;

signed main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    for (int i = 2; i <= n; i++)
    {
        if (s[i] == s[i - f[i - 1] - 1]) f[i] = f[i - 1] + 2;
        if (s[i] == s[i - 1]) f[i] = 2;
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i])
        {
            a[i - f[i] + 1] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i]) cnt[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        ans += cnt[i];
        if (cnt[a[i] + 1] > 0)
        {
            cnt[a[i] + 1] += cnt[i];
        }
    }
    cout << ans << endl;
    return 0;
}
