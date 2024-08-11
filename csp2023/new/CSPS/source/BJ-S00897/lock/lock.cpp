#include <bits/stdc++.h>
using namespace std;
const int N = 100;
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
int n, res, pos1, pos2;
int a[N][N], cur[N], d[N];
void dfs(int x)
{
    if (x == 5)
    {
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= 5; j++)
            {
                if (cur[j] != a[i][j]) d[j] = 1, cnt++;
                else d[j] = 0; 
            }
            if (!cnt) return ;
            if (cnt == 1) continue;
            else
            {
                if (cnt > 2) return ;
                pos1 = 0, pos2 = 0;
                for (int j = 1; j <= 5; j++)
                {
                    if (d[j] == 1 && !pos1) pos1 = j;
                    else if (d[j] == 1) pos2 = j;
                }
                if (abs(pos1 - pos2) != 1) return ;
                else
                {
                    if ((a[i][pos1] - cur[pos1] != a[i][pos2] - cur[pos2]) && (a[i][pos1] + 10 - cur[pos1] != a[i][pos2] - cur[pos2]) && (a[i][pos1] - cur[pos1] != a[i][pos2] + 10 - cur[pos2])) return ;
                    continue;
                }
            }
        }
        res++;
        return ;
    }
    for (int i = 0; i <= 9; i++)
    {
        cur[x + 1] = i;
        dfs(x + 1);
    }
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= 5; j++) a[i][j] = read();
    dfs(0);
    printf("%d\n", res);
    return 0;
}