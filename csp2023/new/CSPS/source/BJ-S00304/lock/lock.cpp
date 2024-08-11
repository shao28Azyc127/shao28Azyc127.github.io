#include <bits/stdc++.h>
using namespace std;
int a[10][6], prob[100][6];
bool tot[100], can[100];
bool cmp(int k, int t)
{
    for (int i = 1; i <= 5; i++)
    {
        if (a[k][i] != prob[t][i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= 81; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            prob[i][j] = a[1][j];
        }
    }
    int sz = 0;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            sz++;
            prob[sz][i] = (prob[sz][i] + j) % 10;
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            sz++;
            prob[sz][i] = (prob[sz][i] + j) % 10;
            prob[sz][i + 1] = (prob[sz][i + 1] + j) % 10;
        }
    }
    // Here starts deleting probrabilities
    int ans = 0;
    memset(tot, true, sizeof(tot));
    for (int k = 2; k <= n; k++)
    {
        memset(can, false, sizeof(can));
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                for (int t = 1; t <= 81; t++)
                {
                    int pre = a[k][i];
                    a[k][i] = (a[k][i] + j) % 10;
                    if (!can[t] && cmp(k, t))
                    {
                        can[t] = true;
                    }
                    a[k][i] = pre;
                }
            }
        }
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                for (int t = 1; t <= 81; t++)
                {
                    int pre1 = a[k][i];
                    a[k][i] = (a[k][i] + j) % 10;
                    int pre2 = a[k][i + 1];
                    a[k][i + 1] = (a[k][i + 1] + j) % 10;
                    if (!can[t] && cmp(k, t))
                    {
                        can[t] = true;
                    }
                    a[k][i] = pre1;
                    a[k][i + 1] = pre2;
                }
            }
        }
        for (int i = 1; i <= 81; i++)
        {
            tot[i] &= can[i];
        }
    }
    for (int i = 1; i <= 81; i++)
    {
        if (tot[i])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
