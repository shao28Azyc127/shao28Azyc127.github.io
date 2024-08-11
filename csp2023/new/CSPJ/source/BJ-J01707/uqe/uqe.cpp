#include <iostream>
#include <cmath>
using namespace std;
int a, b, c, delta, q1, q2, r, t, m, g, g1, g2;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;
        delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            cout << "NO" << endl;
        }
        else if (delta == 0)
        {
            g = gcd(2 * abs(a), abs(b));
            if (2 * abs(a) == g)
            {
                if (a > 0)
                {
                    cout << (0 - b) / g << endl;
                }
                else
                {
                    cout << b / g << endl;
                }
            }
            else
            {
                if (a < 0)
                {
                    cout << b / g << "/" << abs(a) * 2 / g << endl;
                }
                if (a > 0)
                {
                    cout << (0 - b) / g << "/" << abs(a) * 2 / g << endl;
                }
            }
        }
        else
        {
            if (floor(sqrt(delta)) == sqrt(delta))
            {
                r = sqrt(delta);
                if (a > 0)
                {
                    g = gcd(2 * abs(a), abs(r - b));
                    if (2 * abs(a) == g)
                    {
                        cout << (r - b) / g << endl;
                    }
                    else
                    {
                        cout << (r - b) / g << "/" << abs(a) * 2 / g << endl;
                    }
                }
                if (a < 0)
                {
                    g = gcd(2 * abs(a), abs(r + b));
                    if (2 * abs(a) == g)
                    {
                        cout << (r + b) / g << endl;
                    }
                    else
                    {
                        cout << (r + b) / g << "/" << abs(a) * 2 / g << endl;
                    }
                }
            }
            else
            {
                q1 = -b;
                for (int i = 1; i < sqrt(delta) + 1; i++)
                {
                    if (delta % (i * i) == 0)
                    {
                        q2 = i;
                    }
                }
                r = delta / (q2 * q2);
                g1 = gcd(abs(q1), 2 * abs(a));
                g2 = gcd(abs(q2), 2 * abs(a));
                if (b == 0)
                {
                    cout << "";
                }
                else if (2 * abs(a) == g1)
                {
                    if (a > 0)
                    {
                        cout << q1 / g1 << "+";
                    }
                    else
                    {
                        cout << (0 - q1) / g1 << "+";
                    }
                }
                else
                {
                    if (a > 0)
                    {
                        cout << q1 / g1 << "/" << abs(a) * 2 / g1 << "+";
                    }
                    if (a < 0)
                    {
                        cout << -q1 / g1 << "/" << abs(a) * 2 / g1 << "+";
                    }
                }
                if (q2 == g2)
                {
                    if (2 * abs(a) == g2)
                    {
                        cout << "sqrt(" << r << ")" << endl;
                    }
                    else
                    {
                        cout << "sqrt(" << r << ")" <<"/" << abs(a) * 2 / g2 << endl;
                    }
                }
                else
                {
                    if (2 * abs(a) == g2)
                    {
                        cout << q2 / g2 << "*sqrt(" << r << ")" << endl;
                    }
                    else
                    {
                        cout << q2 / g2 << "*sqrt(" << r << ")" <<"/" << abs(a) * 2 / g2 << endl;
                    }
                }
            }
        }
    }
    return 0;
}