#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int T, m;
int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}
int sqr(int x)
{
    int res = 1;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % (i * i) == 0)
        {
            x = x / i / i;
            res *= i;
        }
    }
    return res;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> m;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else if (delta == 0)
        {
            int t = gcd(-b, 2 * a);
            b = -b / t;
            a = 2 * a / t;
            if (a == 1)
            {
                cout << b << endl;
            }
            else if (a == -1)
            {
                cout << -b << endl;
            }
            else
            {
                if (a < 0)
                {
                    a = -a;
                    b = -b;
                }
                cout << b << "/" << a << endl;
            }
        }
        else
        {
            if (sqrt(1.0 * delta) == int(sqrt(1.0 * delta)))
            {
                int x1 = -b - sqrt(delta);
                int x2 = -b + sqrt(delta);
                a *= 2;
                if (a > 0 && x1 > x2 || a < 0 && x1 < x2)
                {
                    b = x1;
                }
                else
                {
                    b = x2;
                }
                int t = gcd(a, b);
                a /= t;
                b /= t;
                if (a == 1)
                {
                    cout << b << endl;
                }
                else if (a == -1)
                {
                    cout << -b << endl;
                }
                else
                {
                    if (a < 0)
                    {
                        a = -a;
                        b = -b;
                    }
                    cout << b << "/" << a << endl;
                }
            }
            else if (c == 0)
            {
                if (b < 0 && a > 0 || b > 0 && a < 0)
                {
                    int t = gcd(a, -b);
                    a /= t;
                    b = -b / t;
                    if (a == 1)
                    {
                        cout << b << endl;
                    }
                    else if (a == -1)
                    {
                        cout << -b << endl;
                    }
                    else
                    {
                        if (a < 0)
                        {
                            a = -a;
                            b = -b;
                        }
                        cout << b << "/" << a << endl;
                    }
                }
                else
                {
                    cout << 0 << endl;
                }
            }
            else if (b == 0)
            {
                if (a > 0)
                {
                    c = -c;
                }
                else
                {
                    a = -a;
                }
                b = sqr(a * c);
                int t = a * c / b / b;
                int tt = gcd(a, b);
                a /= tt;
                b /= tt;
                if (b > 1)
                {
                    cout << b << "*";
                }
                cout << "sqrt(" << t << ")";
                if (a > 1)
                {
                    cout << "/" << a;
                }
                cout << endl;
            }
        }
    }
    return 0;
}