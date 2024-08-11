#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n, ans = 0;
bool f[1000010];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    memset(f, false, sizeof(f));
    int cnt = n, c = 0;
    for (int i = 1; i <= n; i++)
    {
        int m = 2;
        for (int j = 1; j <= n; j++)
            if (!f[j])
            {
                m++;
                if (m == 3)
                {
                    cnt--;
                    m = 0;
                    f[j] = true;
                    if (j == n) ans = i;
                    if (cnt == 0)
                    {
                        c = i;
                        break;
                    }
                }
            }
        if (c > 0) break;
    }
    cout << c << ' ' << ans << endl;
    return 0;
}