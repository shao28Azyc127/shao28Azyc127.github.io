#include <cstdio>
using namespace std;
const int NR = 5e5;
int C,n,m,q,a[NR + 5],b[NR + 5],c[NR + 5],d[NR + 5];
bool dp[2005][2005];
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
inline void work()
{
    if (a[1] < b[1])
    {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                dp[i][j] = false;
        dp[1][1] = true;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                if (a[i] < b[j])
                {
                    if (dp[i][j - 1] == true)
                        dp[i][j] = true;
                    if (dp[i - 1][j] == true)
                        dp[i][j] = true;
                    if (dp[i - 1][j - 1] == true)
                        dp[i][j] = true;
                }
        if (dp[n][m])
        {
            putchar('1');
            return;
        }
    }
    if (a[1] > b[1])
    {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                dp[i][j] = false;
        dp[1][1] = true;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                if (a[i] > b[j])
                {
                    if (dp[i][j - 1] == true)
                        dp[i][j] = true;
                    if (dp[i - 1][j] == true)
                        dp[i][j] = true;
                    if (dp[i - 1][j - 1] == true)
                        dp[i][j] = true;
                }
        if (dp[n][m])
        {
            putchar('1');
            return;
        }
    }
    putchar('0');
    return;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    C = read();
    n = read();
    m = read();
    q = read();
    for (int i = 1;i <= n;i++)
        c[i] = read();
    for (int i = 1;i <= m;i++)
        d[i] = read();
    for (int i = 1;i <= n;i++)
        a[i] = c[i];
    for (int i = 1;i <= m;i++)
        b[i] = d[i];
    work();
    for (int i = 1;i <= q;i++)
    {
        int x = read(),y = read(),pos,val;
        for (int i = 1;i <= n;i++)
            a[i] = c[i];
        for (int i = 1;i <= m;i++)
            b[i] = d[i];
        for (int j = 1;j <= x;j++)
        {
            pos = read();
            val = read();
            a[pos] = val;
        }
        for (int j = 1;j <= y;j++)
        {
            pos = read();
            val = read();
            b[pos] = val;
        }
        work();
    }
    return 0;
}