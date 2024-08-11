#include <iostream>
using namespace std;

int n, st[10][6], ans = 81, t[90][6], cnt;
bool f[90];

bool chk(int i, int j, int k)
{
    for (int l = k + 1; l <= 5; ++l)
    {
        if (st[i][l] != t[j][l]) return false;
    }
    return true;
}

bool bj(int i, int j)
{
    int p = 0;
    for (int k = 1; k <= 5; ++k)
    {
        if (st[i][k] == t[j][k]) continue;
        if (p != 0 && p != k - 1) return false;
        if (p == 0)
        {
            p = k;
            continue;
        }
        if (((st[i][k - 1] - t[j][k - 1] - st[i][k] + t[j][k] + 20) % 10) || !chk(i, j, k)) return false;
        //if (!chk(i, j, k)) return false;
        return true;
    }
    //if (!p) return false;
    //return true;

    return p;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            scanf("%d", &st[i][j]);
        }
    }
    if (n <= 1)
    {
        printf("81");
        return 0;
    }
    for (int i = 1; i <= 81; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            t[i][j] = st[1][j];
        }
    }
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cnt++;
            t[cnt][i] += j;
            t[cnt][i] %= 10;
        }
    }
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cnt++;
            t[cnt][i] += j;
            t[cnt][i + 1] += j;
            t[cnt][i] %= 10;
            t[cnt][i + 1] %= 10;
        }
    }
    /*for (int i = 1; i <= 81; ++i)
    {
        if (!f[i])
        {
            for (int j = 1; j <= 5; ++j)
            {
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }
    }*/
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= 81; ++j)
        {
            //if (f[j]) continue;
            if (!f[j] && !bj(i, j))
            {
                ans--;
                f[j] = true;
            }
        }
    }
    /*for (int i = 1; i <= 81; ++i)
    {
        if (!f[i])
        {
            for (int j = 1; j <= 5; ++j)
            {
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }
    }*/
    printf("%d", ans);
    return 0;
}