#include <bits/stdc++.h>

using namespace std;
const int N = 3e3 + 10;

int mn[N], mx[N], n, m;
char str[N];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", str + 1);
        mx[i] = -1, mn[i] = 26;
        for(int j = 1; j <= m; j++)
        {
            mx[i] = max(mx[i], str[j] - 'a');
            mn[i] = min(mn[i], str[j] - 'a');
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int flag = 1;
        for(int j = 1; j <= n; j++)
        {
            if(i != j) flag &= mn[i] < mx[j];
        }
        putchar('0' + flag);
    }
    return 0;
}
