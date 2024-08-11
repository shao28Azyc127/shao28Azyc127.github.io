#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[3010];
string maxs[3010];
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        string tmp = s[i];
        stable_sort (tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        maxs[i] = tmp;
    }
    if (n == 1)
    {
        for (int i = 1; i <= n; i++) putchar('1');
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        string tmp = s[i];
        stable_sort (s[i].begin(), s[i].end());
        int ans = 1;
        for (int j = 1; j <= n; j++)
        {
            if (j == i) continue;
            else
            {
                if (maxs[j] < s[i])
                {
                    ans = 0;
                    break;
                }
            }
        }
        printf("%d", ans);
        s[i] = tmp;
    }
    return 0;
}
