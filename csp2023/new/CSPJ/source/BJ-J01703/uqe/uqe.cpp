#include<bits/stdc++.h>
using namespace std;
long long t,m,a,b,c,d1,d2,d3 = 1,d4,cnt = 2,y;

int gcd(long long d,long long e)
{
    if (d < e)
    {
        swap(d,e);
    }
    while (e != 0)
    {
        long long f = d;
        d = e;
        e = f % e;
    }
    return d;
}

bool squ(int g)
{
    return int(sqrt(g)) * int(sqrt(g)) == g;
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    for (int i = 1;i <= t;i++)
    {
        cin >> a >> b >> c;
        long long x = (b * b) - (4 * a * c);
        if (x < 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (squ(x))
            {
                x = sqrt(x) - b;
                d1 = x / gcd(x,2 * a);
                d2 = 2 * a / gcd(x,2 * a);
                if (d1 != 0)
                {
                    if (abs(d2) == 1)
                    {
                        if (d1 * d2 > 0)
                        {
                            cout << abs(d1) << endl;
                        }
                        else
                        {
                            cout << "-" << abs(d1) << endl;
                        }
                    }
                    else
                    {
                        if (d1 * d2 > 0)
                        {
                            cout << abs(d1) << "/" << abs(d2) << endl;
                        }
                        else
                        {
                            cout << "-" << abs(d1) << "/" << abs(d2) << endl;
                        }
                    }
                }
                else
                {
                    cout << "0" << endl;
                }
            }
            else
            {
                d1 = b / gcd(abs(b),abs(2 * a));
                d2 = 2 * a / gcd(abs(b),abs(2 * a));
                if (d1 != 0)
                {
                    if (abs(d2) == 1)
                    {
                        if (d1 * d2 < 0)
                        {
                            cout << abs(d1) << "+";
                        }
                        else
                        {
                            cout << "-" << abs(d1) << "+";
                        }
                    }
                    else
                    {
                        if (d1 * d2 < 0)
                        {
                            cout << abs(d1) << "/" << abs(d2) << "+";
                        }
                        else
                        {
                            cout << "-" << abs(d1) << "/" << abs(d2) << "+";
                        }
                    }
                }
                d4 = abs(2 * a);
                while (cnt < x)
                {
                    while (x % (cnt * cnt) == 0)
                    {
                        d3 *= cnt;
                        y = d3;
                        d3 /= gcd(y,d4);
                        d4 /= gcd(y,d4);
                        x /= (cnt * cnt);
                    }
                    cnt++;
                }
                if (abs(d4) == 1)
                {
                    if (abs(d3) == 1)
                    {
                        cout << "sqrt(" << x << ")" << endl;
                    }
                    else
                    {
                        cout << abs(d3) << "*sqrt(" << x << ")" << endl;
                    }
                }
                else
                {
                    if (abs(d3) == 1)
                    {
                        cout << "sqrt(" << x << ")/" << abs(d4) << endl;
                    }
                    else
                    {
                        cout << abs(d3) << "*sqrt(" << x << ")/" << abs(d4) << endl;
                    }
                }
            }
        }
    }
    return 0;
}
