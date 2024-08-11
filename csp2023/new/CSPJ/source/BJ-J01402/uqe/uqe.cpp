#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool pf(int x)
{
    int t = sqrt(x);
    return t * t == x;
}

int gcd(int a, int b)
{
    int x = max(abs(a), abs(b));
    for (int i = x; i >= 1; --i)
        if (a % i == 0 && b % i == 0) return i;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x = b * b - 4 * a * c;
        if (x < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (!pf(x))
        {
            b *= -1;
            int n = gcd(b, 2 * a);
            bool f = false;
            if (2 * a / n < 0)
            {
                b *= -1;
                a *= -1;
            }
            if (b != 0)
            {
                cout << b / n;
                f = true;
            }
            if (!(2 * a == n) && b != 0)
            {
                cout << '/' << 2 * a / n;
                f = true;
            }
            if (f) cout << '+';
            int y = -1;
            for (int i = 2; i * i <= x; ++i)
                if (x % (i*i) == 0) y = i;
            x /= y * y;
            a *= 2;
            if (y != -1)
            {
                int n2 = gcd(y, a);
                a /= n2;
                if (y != n2) cout << y / n2 << "*";
            }
            if (a / n < 0)
            {
                cout << '-';
                a *= -1;
            }
            cout << "sqrt(" << x << ')';
            if (a != 1 || y == -1) cout << '/' << a;
            cout << endl;
        }
        else
        {
            int num;
            if (a > 0) num = max(-1 * b - sqrt(x), -1 * b + sqrt(x));
            else num = min(-1 * b - sqrt(x), -1 * b + sqrt(x));
            int n = gcd(num, 2 * a);
            bool f = false;
            if (2 * a / n < 0)
            {
                num *= -1;
                a *= -1;
            }
            if (num != 0)
            {
                cout << num / n;
                f = true;
            }
            if (!(2 * a == n) && num != 0)
            {
                cout << '/' << 2 * a / n;
                f = true;
            }
            if (!f) cout << 0;
            cout << endl;
        }
    }
    return 0;
}
