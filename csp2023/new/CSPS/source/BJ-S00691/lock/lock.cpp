#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n, a[N][N], ans;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= 5;j++)
            scanf("%d", &a[i][j]);
    for (int i = 0;i <= 99999;i++)
    {
        bool flag = 1;
        for (int j = 1;j <= n;j++)
        {
            int cnt = 0, sum = 0, p = 0;
            for (int x = i, k = 5;k > 0;x /= 10, k--)
            {
                if (x%10 != a[j][k])
                {
                    if (!cnt) sum = (x%10 - a[j][k] + 10) % 10, p = k;
                    else if (cnt != 1 || sum != (x%10 - a[j][k] + 10) % 10 || p-k != 1)
                    {
                        flag = 0;
                        break;
                    }
                    cnt++;
                }
            }
            if (!cnt || !flag)
            {
                flag = 0;
                break;
            }
        }
        if (flag) ans++;
    }
    printf("%d", ans);
    return 0;
}

