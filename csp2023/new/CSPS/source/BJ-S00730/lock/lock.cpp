#include <bits/stdc++.h>
#define int long long
using namespace std;
map <int, int> st;
int a[15], m10[15] = {1, 10, 100, 1000, 10000, 100000, 1000000};
signed main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n, x, y;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%lld", &x);
            a[i] = (a[i] << 3) + (a[i] << 1) + x;
        }
        //printf("%lld\n", a[i]);
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (k == a[i] / m10[j] % 10)
                    continue;
                st[a[i] - (a[i] / m10[j]) % 10 * m10[j] + k * m10[j]]++;
                //printf("%d %d %d\n",a[i] - (a[i] / m10[j]) % 10 * m10[j] + k * m10[j], j, k);
            }
        }
        for (int j = 0; j < 4; j++)
        {
            for (int k = 1; k < 10; k++)
            {
                x = a[i] / m10[j] % 10;
                y = a[i] / m10[j + 1] % 10;
                st[a[i] - x * m10[j] - y * m10[j + 1] + (x + k) % 10 * m10[j] + (y + k) % 10 * m10[j + 1]]++;
                //printf("%d %d %d\n", a[i] - x - y + (x + k) % 10 * m10[j] + (y + k) % 10 * m10[j + 1], j, k);
            }
        }
    }
    int cnt = 0;
    for (auto i : st)
    {
        if (i.second >= n)
            cnt++;
        //printf("%d,%d\n", i.first,i.second);
    }
    printf("%lld", cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
