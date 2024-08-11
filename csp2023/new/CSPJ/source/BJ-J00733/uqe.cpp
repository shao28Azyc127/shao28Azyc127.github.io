#include <cmath>
#include <iostream>
using namespace std;
struct str
{
    int a,r;
};
int gcd(int x,int y)
{
    if (y == 0) return x;
    return gcd(y,x % y);
}
void outnum1(int p,int q)
{
    int x = 1;
    if (p < 0) x *= -1;
    if (q < 0) x *= -1;
    p = abs(p);
    q = abs(q);
    int k = gcd(p,q);
    p /= k;
    q /= k;
    if (x == -1) cout << "-";
    if (q == 1) cout << p;
    else cout << p << "/" << q;
}
void outnum2(int p,int q,int c,int d,int r)
{
    if (p != 0)
    {
        outnum1(p,q);
        cout << "+";
    }
    int x = 1;
    if (c < 0) x *= -1;
    if (d < 0) x *= -1;
    c = abs(c);
    d = abs(d);
    int k = gcd(c,d);
    c /= k;
    d /= k;
    if (x == -1) cout << "-";
    if (c != 1) cout << c << "*";
    cout << "sqrt(" << r << ")";
    if (d != 1) cout << "/" << d;
    cout << endl;
}
bool isint(double x)
{
    int xx = x;
    return x - xx == 0;
}
str sqj(int r)
{
    int ans = 1;
    for (int i = 2;i <= sqrt(r);i++)
    {
        int ii = i * i;
        while (ii < r)
        {
            ans *= i;
            r /= ii;
        }
    }
    return {ans,r};
}
void uqe(int a,int b,int c)
{
    int k = b * b - 4 * a * c;
    if (k < 0)
    {
        cout << "NO\n";
        return;
    }
    double sq = sqrt(1.0 * k);
    if (isint(sq))
    {
        int q = a * 2;
        int p = sq - b;
        outnum1(p,q);
        cout << endl;
    }
    else
    {
        int q = a * 2;
        int p = -b;
        str tmp = sqj(k);
        int cc = tmp.a;
        int d = q;
        int r = tmp.r;
        outnum2(p,q,cc,d,r);
    }
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    cin >> t >> m;
    while (t--)
    {
        cin >> a >> b >> c;
        if (b == 0 && c == 0)
        {
            cout << "0\n";
        }
        else if (b == 0)
        {
            if (c > 0) cout << "NO\n";
            else
            {
                str x = sqj(-c);
                if (x.r == 1)
                {
                    cout << x.a << endl;
                }
                else
                {
                    cout << x.a << "*sqrt(" << x.r << ")\n";
                }
            }
        }
        else if (c == 0)
        {
            if (-b * a < 0) cout << "0\n";
            else
            {
                a = abs(a);
                b = abs(b);
                int k = gcd(a,b);
                a /= k;
                b /= k;
                cout << b;
                if (a != 1) cout << "/" << a;
                cout << endl;
            }
        }
        else uqe(a,b,c);
    }
    return 0;
}
