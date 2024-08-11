#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;

int n, m;
bool flag;

struct strings
{
    int low, high;
    char str[maxn];
} s[maxn];

bool cmpstr (strings a, strings b)
{
    if (a.low < b.high) return 1;
    return 0;
}

int main ()
{
    freopen ("dict.in", "r", stdin);
    freopen ("dict.out", "w", stdout);
    scanf ("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++)
    {
        scanf ("%s", &s[i].str);
        s[i].low = 100;
        for (int j = 0; j < m; j ++)
        {
            s[i].low = min (s[i].str[j] - 'a', s[i].low);
            s[i].high = max (s[i].str[j] - 'a', s[i].high);
        }
    }

    for (int i = 1; i <= n; i ++)
    {
        flag = 1;
        for (int j = 1; j <= n; j ++)
        {
            if (i == j)
                continue;
            if (!cmpstr (s[i], s[j]))
            {
                printf ("0");
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf ("1");
        }
    }
    return 0;
}
