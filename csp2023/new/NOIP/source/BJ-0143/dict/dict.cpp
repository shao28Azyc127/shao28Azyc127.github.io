#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int n, m;
char s[N][N], t[N][N];
int cnt[N][30];
int min1, cnt2;
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) scanf("%s", (s[i] + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cnt[i][s[i][j] - 'a']++;
    for (int i = 1; i <= n; i++)
    {
        int pos = 0;
        for (int j = 1; j <= m; j++)
        {
            while (!cnt[i][pos]) pos++;
            cnt[i][pos]--;
            s[i][j] = char(pos + 'a');
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cnt[i][s[i][j] - 'a']++;
    for (int i = 1; i <= n; i++)
    {
        int pos = 0;
        for (int j = m; j >= 1; j--)
        {
            while (!cnt[i][pos]) pos++;
            cnt[i][pos]--;
            t[i][j] = char(pos + 'a');
        }
    }
    min1 = 1;
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 1; j <= m; j++)
        {
            if (t[i][j] != t[min1][j])
            {
                flag = 1;
                if (t[i][j] < t[min1][j]) min1 = i;
                break;
            }
        }
        if (!flag) cnt2++;
    }
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] != t[min1][j])
            {
                if (s[i][j] < t[min1][j]) flag = 1;
                break;
            }
        }
        if (i == min1 && cnt2 == 1) flag = 1;
        printf("%d", flag);
    }
    puts("");
    return 0;
}