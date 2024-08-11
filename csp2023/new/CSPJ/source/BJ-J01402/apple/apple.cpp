#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool f[10000005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, ans = 1, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i]) continue;
        cnt++;
        f[i] = true;
        if (i == n) ans = cnt;
        int c = 0;
        for (int j = i + 1; j <= n; ++j)
        {
            if (f[j]) continue;
            c++;
            if (c == 3)
            {
                f[j] = true;
                c = 0;
                if (j == n) ans = cnt;
            }
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}