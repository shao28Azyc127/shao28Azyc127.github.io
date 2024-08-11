#include <bits/stdc++.h>
using namespace std;
int t, m;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main ()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int s = pow(b, 2) - 4 * a * c;
        if (s < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        b /= -1;
        a *= 2;
        if (b == 0)
        {
            int qq = a;
            int q = 1;
            for (int i = 2; i * i < s; i++)
            {
                if (s % (i * i) == 0)
                {
                    s /= i * i;
                    q *= i;
                }
            }
            int x = gcd(q, qq);
            if (x != 1)
            {
                q /= x;
                qq /= x;
                if (qq < 0)
                {
                    q /= -1;
                    qq /= -1;
                }
            }
            if (qq == 1)
            {
                if (q != 1)
                {
                    cout << q << "*sqrt(" << s << ")" << endl;
                }
                else
                {
                    cout << "sqrt(" << s << ")" << endl;
                }
            }
            else
            {
                if (q != 1)
                {
                    cout << q << "*sqrt(" << s << ")/" << qq << endl;
                }
                else
                {
                    cout << "sqrt(" << s << ")/" << qq << endl;
                }
            }
            continue;
        }
        if (sqrt(s) == (int)sqrt(s))
        {
            s = sqrt(s);
            b += s;
            int x = gcd(b, a);
            if (x != 1)
            {
                b /= x;
                a /= x;
                if (a < 0)
                {
                    b /= -1;
                    a /= -1;
                }
            }
            if (a == 1)
            {
                cout << b << endl;
            }
            else
            {
                cout << b << "/" << a << endl;
            }
        }
        else
        {
            int qq = a;
            int x = gcd(b, a);
            if (x != 1)
            {
                b /= x;
                a /= x;
                if (a < 0)
                {
                    b /= -1;
                    a /= -1;
                }
            }
            int q = 1;
            for (int i = 2; i * i < s; i++)
            {
                if (s % (i * i) == 0)
                {
                    s /= i * i;
                    q *= i;
                }
            }
            int y = gcd(q, qq);
            if (y != 1)
            {
                q /= y;
                qq /= y;
                if (qq < 0)
                {
                    q /= -1;
                    qq /= -1;
                }
            }
            if (a == 1)
            {
                cout << b;
                if (qq == 1)
                {
                    if (q != 1)
                    {
                        cout << "+" << q << "*sqrt(" << s << ")" << endl;
                    }
                    else
                    {
                        cout << "+sqrt(" << s << ")" << endl;
                    }
                }
                else
                {
                    if (q != 1)
                    {
                        cout << "+" << q << "*sqrt(" << s << ")/" << qq << endl;
                    }
                    else
                    {
                        cout << "+sqrt(" << s << ")/" << qq << endl;
                    }
                }
            }
            else
            {
                cout << b << "/" << a;
                if (qq == 1)
                {
                    if (q != 1)
                    {
                        cout << "+" << q << "*sqrt(" << s << ")" << endl;
                    }
                    else
                    {
                        cout << "+sqrt(" << s << ")" << endl;
                    }
                }
                else
                {
                    if (q != 1)
                    {
                        cout << "+" << q << "*sqrt(" << s << ")/" << qq << endl;
                    }
                    else
                    {
                        cout << "+sqrt(" << s << ")/" << qq << endl;
                    }
                }
            }
        }
    }
    return 0;
}
