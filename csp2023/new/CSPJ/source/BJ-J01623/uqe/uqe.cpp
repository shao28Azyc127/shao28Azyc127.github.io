#include <iostream>
using namespace std;

int t, m;

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

struct frac
{
    int a, b;

    frac()
    {
        a = b = 0;
    }

    void yuefen()
    {
        if (a == 0)
        {
            b = 1;
            return;
        }
        int g = gcd(a, b);
        a /= g;
        b /= g;
        if (b < 0)
        {
            a *= -1;
            b *= -1;
        }
    }

    void print()
    {
        if (b == 1)
        {
            cout << a;
        }
        else
        {
            cout << a << "/" << b;
        }
    }
};

frac operator+ (const frac& x, const frac& y)
{
    frac z;
    z.a = x.a * y.b + y.a * x.b;
    z.b = x.b * y.b;
    z.yuefen();
    return z;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while (t--)
    {
        int a, b, c, tri;
        cin >> a >> b >> c;
        tri = b * b - 4 * a * c;
        if (tri < 0)
        {
            cout << "NO";
        }
        else
        {
            frac q1, q2;
            int r;
            q1.a = -b;
            q1.b = 2 * a;
            q2.a = 1;
            q2.b = abs(2 * a);
            r = tri;
            q1.yuefen();
            for (int i = 2; i * i <= r; i++)
            {
                while (r % (i * i) == 0)
                {
                    q2.a *= i;
                    r /= i * i;
                }
            }
            q2.yuefen();
            if (r == 0)
            {
                q1.print();
            }
            else if (r == 1)
            {
                (q1 + q2).print();
            }
            else
            {
                if (q1.a != 0 || q1.b != 1)
                {
                    q1.print();
                    cout << "+";
                }
                if (q2.a == 1 && q2.b == 1)
                {
                    cout << "sqrt(" << r << ")";
                }
                else if (q2.b == 1)
                {
                    cout << q2.a << "*sqrt(" << r << ")";
                }
                else if (q2.a == 1)
                {
                    cout << "sqrt(" << r << ")/" << q2.b;
                }
                else
                {
                    cout << q2.a << "*sqrt(" << r << ")/" << q2.b;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
