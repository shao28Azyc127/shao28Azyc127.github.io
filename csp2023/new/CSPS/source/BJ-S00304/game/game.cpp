#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
string str;
int vis[maxn];
int check(int l, int r)
{
    int tot = r - l + 1;
    bool flag = true;
    while (flag)
    {
        flag = false;
        int j = l;
        while (j <= r && vis[j])
        {
            j++;
        }
        while (j <= r)
        {
            int x = j;
            j++;
            while (j <= r && vis[j])
            {
                j++;
            }
            if (j <= r)
            {
                int y = j;
                if (str[x] == str[y])
                {
                    vis[x] = true;
                    vis[y] = true;
                    flag = true;
                    tot -= 2;
                    j++;
                    while (j <= r && vis[j])
                    {
                        j++;
                    }
                }
            }
        }
    }
    return (tot > 0 ? 0 : 1);
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    long long ans = 0;
    cin >> n >> str;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i + 1; j < str.size(); j += 2)
        {
            memset(vis, false, sizeof(vis));
            ans += check(i, j);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
