#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 5;
bool a[N];
int main ()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, ans, t;
    cin >> n;
    int x = n;
    while (n)
    {
        int cnt = 0;
        bool flag = false;
        for (int i = 1; i <= x; i++)
        {
            if (!a[i] && !flag)
            {
                flag = true;
                a[i] = true;
                if (i == x)
                {
                    t = ans + 1;
                }
                continue;
            }
            if (!a[i])
            {
                cnt++;
            }
            if (cnt == 3)
            {
                a[i] = true;
                cnt = 0;
                if (i == x)
                {
                    t = ans + 1;
                }
            }
        }
        if (n % 3 != 0)
        {
            n--;
        }
        n -= n / 3;
        ans++;
    }
    cout << ans << " " << t << endl;
    return 0;
}
