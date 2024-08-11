#include <iostream>
#include <cmath>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, m;
    cin >> T >> m;
    for (int i = 1; i <= T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int del = b * b - 4 * a * c;
        if (del < 0) cout << "NO" << endl;
        else if (c == 0)
        {
            int d = gcd(a, b);
            a /= d;
            b /= d;
            b = -b;
            if (b % a == 0) cout << max(0, b / a) << endl;
            else if (1.0 * b / a >= 0)
            {
                if (b < 0 && a < 0) cout << -b << "/" << -a << endl;
                else cout << b << "/" << a << endl;
            }
            else cout << 0 << endl;
            // cout << i << endl;
        }
        else
        {
            int sdel = sqrt(del);
            int one = (-b + sdel) / (2 * a);
            int two = (-b - sdel) / (2 * a);
            cout << max(one, two) << endl;
        }
    }
    return 0;
}
