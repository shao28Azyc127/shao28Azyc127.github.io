#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int gcd(int x, int y)
{
    int ans = 1;
    for (int i = 1; i * i <= max(x, y); i++)
        if (x % i == 0 && y % i == 0) ans *= i;
    return ans;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, m;
    cin >> T >> m;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x = b * b - a * c * 4;
        // cout << x << '\n';
        if (x < 0) puts("NO");
        else if (x == 0)
        {
            if (c == 0 && b % (2 * a))
            {
                int x = gcd(b, 2 * a);
                int p = -b / x, q = 2 * a / x;
                cout << p << '/' << q << '\n';
            }
            else
            {
                int ans = (-b) / (2 * a);
                cout << ans << '\n';
            }
        }
        else
        {
            int ans1 = ((-b) + sqrt(x)) / (2 * a);
            int ans2 = ((-b) - sqrt(x)) / (2 * a);
            cout << max(ans1, ans2) << '\n';
        }

    }
    return 0;
}
