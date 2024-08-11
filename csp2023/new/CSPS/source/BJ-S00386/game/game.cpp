#include <bits/stdc++.h>
using namespace std;

const int maxn = 810000;

int n, ans, cnt;
string s;
string subs[maxn];

int main ()
{
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 1; j <= n - i; j ++)
        {
            subs[++ cnt] = s.substr (i, j);
        }
    }
    for (int i = 1; i <= cnt; i ++)
    {
        if (subs[i].length () % 2 == 1)
            continue;
        ans ++;
        while (subs[i].length () > 0)
        {
            int j;
            bool flag = 0;
            for (j = 0; j < subs[i].length () - 1; j ++)
            {
                if (subs[i][j] == subs[i][j + 1])
                {
                    subs[i].erase (j, 2);
                    j -= 2;
                    flag = 1;
                }
            }
            if (!flag)
            {
                ans --;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
