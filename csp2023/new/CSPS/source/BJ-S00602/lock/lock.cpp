#include<bits/stdc++.h>
using namespace std;
int a[10], b[10];
int cnt[10][10][10][10][10];
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int t = 1; t <= n; t++)
    {
        for(int i = 1; i <= 5; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        for(int i = 1; i <= 5; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                b[i] = (b[i] + 1) % 10;
                cnt[b[1]][b[2]][b[3]][b[4]][b[5]]++;
            }
            b[i] = a[i];
            if(i == 5) continue;
            for(int j = 1; j <= 9; j++)
            {
                b[i] = (b[i] + 1) % 10;
                b[i + 1] = (b[i + 1] + 1) % 10;
                cnt[b[1]][b[2]][b[3]][b[4]][b[5]]++;
            }
            b[i] = a[i];
            b[i + 1] = a[i + 1];
        }
    }
    int res = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                for(int a = 0; a < 10; a++)
                {
                    for(int b = 0; b < 10; b++)
                    {
                        if(cnt[i][j][k][a][b] == n) res++;
                    }
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}
