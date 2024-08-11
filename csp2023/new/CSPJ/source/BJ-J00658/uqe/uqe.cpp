#include <bits/stdc++.h>
using namespace std;
int t, m, a, b, c, p;
int rt (int x)
{
    if (x == 0)
        return 0;
    for (int i = sqrt(x); i >= 2; i--)
    {
        if (x % (i*i) == 0)
        {
            return i;
        }
    }
    return 1;
}
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    return gcd(y, x%y);
}
void out(int x, int y)
{
    if (abs(y / gcd(x,y)) == 1)
    {
        cout << abs(x*y) / (x*y) * abs(x / gcd(x,y));
        return;
    }
    cout << abs(x*y) / (x*y) * abs(x / gcd(x,y)) << "/" << abs(y / gcd(x,y));
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        if (a < 0)
        {
            a = -a;
            b = -b;
            c = -c;
        }
        p = b*b - 4*a*c;
        if (p < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (rt(p) == 0)
        {
            if (b == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                out(-b, 2*a);
                cout << endl;
            }
        }
        else
        {
            if (p == rt(p) * rt(p))
            {
                out(-b+rt(p), 2*a);
                cout << endl;
            }
            else
            {
                out(-b, 2*a);
                cout << "+";
                int e = rt(p);
                int f = p / e / e;
                if (e == 2*a)
                {
                    cout << "sqrt(" << f << ")" << endl;
                }
                else if (2*a / gcd(e,2*a) == 1)
                {
                    cout << e / gcd(e,2*a) << "*sqrt(" << f << ")" << endl;
                }
                else if (e / gcd(e,2*a) == 1)
                {
                    cout << "sqrt(" << f << ")" << "/" << 2*a / gcd(e,2*a) << endl;
                }
                else
                {
                    cout << e / gcd(e,2*a) << "*sqrt(" << f << ")" << "/" << 2*a / gcd(e,2*a) << endl;
                }
            }
        }
    }
    return 0;
}
