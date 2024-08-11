#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[100010], a[10];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int T = 1; T <= n; T++)
    {
        for (int i = 1; i <= 5; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                a[j] = (a[j] + i) % 10;
                cnt[a[1] * 10000 + a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5]]++;
                a[j] = (a[j] + 10 - i) % 10;
            }
            for (int j = 1; j <= 4; j++)
            {
                a[j] = (a[j] + i) % 10;
                a[j + 1] = (a[j + 1] + i) % 10;
                cnt[a[1] * 10000 + a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5]]++;
                a[j] = (a[j] + 10 - i) % 10;
                a[j + 1] = (a[j + 1] + 10 - i) % 10;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 99999; i++)
    {
        if (cnt[i] == n) ans++;
    }
    cout << ans << endl;
    return 0;
}
