#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int loc[10][10][10][10][10];
bool flag[10][10][10][10][10];
int g[10][6];
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w",stdout);
    scanf("%d", &n);
    for(int i = 1;i <= n;i ++)
    {
        scanf("%d%d%d%d%d", &g[i][1], &g[i][2], &g[i][3], &g[i][4], &g[i][5]);
        // 0-9
        loc[g[i][1]][g[i][2]][g[i][3]][g[i][4]][g[i][5]] ++;
        flag[g[i][1]][g[i][2]][g[i][3]][g[i][4]][g[i][5]] = true;
    }
    // single change
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= 9;j ++)
        {
            int x1 = g[i][1];
            int x2 = g[i][2];
            int x3 = g[i][3];
            int x4 = g[i][4];
            int x5 = g[i][5];
            loc[(x1 + j) % 10][x2][x3][x4][x5] ++;
            loc[x1][(x2 + j) % 10][x3][x4][x5] ++;
            loc[x1][x2][(x3 + j) % 10][x4][x5] ++;
            loc[x1][x2][x3][(x4 + j) % 10][x5] ++;
            loc[x1][x2][x3][x4][(x5 + j) % 10] ++;
        }
    }
    // double change
    for(int i = 1;i <= n;i ++)
    {
        for(int j = 1;j <= 9;j ++)
        {
            int x1 = g[i][1];
            int x2 = g[i][2];
            int x3 = g[i][3];
            int x4 = g[i][4];
            int x5 = g[i][5];
            loc[(x1 + j) % 10][(x2 + j) % 10][x3][x4][x5] ++;
            loc[x1][(x2 + j) % 10][(x3 + j) % 10][x4][x5] ++;
            loc[x1][x2][(x3 + j) % 10][(x4 + j) % 10][x5] ++;
            loc[x1][x2][x3][(x4 + j) % 10][(x5 + j) % 10] ++;
        }
    }
    int ans = 0;
    for(int i1 = 0;i1 <= 9;i1 ++)
    {
        for(int i2 = 0;i2 <= 9;i2 ++)
        {
            for(int i3 = 0;i3 <= 9;i3 ++)
            {
                for(int i4 = 0;i4 <= 9;i4 ++)
                {
                    for(int i5 = 0;i5 <= 9;i5 ++)
                    {
                        if(loc[i1][i2][i3][i4][i5] == n && !flag[i1][i2][i3][i4][i5])
                        {
                            ans ++;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
