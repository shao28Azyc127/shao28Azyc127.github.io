#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t, m, a, b, c, delta, ta, tb, tc;

int gcd(int a, int b)
{
    if(a == 0 || b == 0) return 1;
    if(a % b == 0) return b;
    if(b % a == 0) return a;
    if(a > b) a = a % b;
    else b = b % a;
    return gcd(a, b);
}

int spsqrt(int x)
{
    int ans = 1;
    for(int i = 2; i * i <= x; i++)
    {
        while(x % (i * i) == 0)
        {
            ans *= i;
            x /= i * i;
        }
    }
    return ans;
}

bool issq(int x)
{
    for(int i = 1; i * i <= x; i++)
    {
        if(i * i == x) return 1;
    }
    return 0;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else if(delta == 0)
        {
            if(b == 0)
            {
                cout << 0 << endl;
                continue;
            }
            tb = abs(b);
            ta = abs(2 * a);
            int tmp1 = gcd(ta, tb);
            tb /= tmp1;
            ta /= tmp1;
            if((b < 0 || a < 0) && !(a < 0 && b < 0))
            {
                if(ta == 1)
                {
                    cout << tb << endl;
                    continue;
                }
                else
                {
                    cout << tb << "/" << ta << endl;
                    continue;
                }
            }
            cout << "-" << tb << "/" << ta << endl;
            continue;
        }
        else
        {
            if(issq(delta))
            {
                int ttb = -b;
                ttb += (int)sqrt(delta);
                if(b == 0)
                {
                    cout << 0 << endl;
                    continue;
                }
                tb = abs(ttb);
                ta = abs(2 * a);
                int tmp1 = gcd(ta, tb);
                tb /= tmp1;
                ta /= tmp1;
                if((b < 0 || a < 0) && !(a < 0 && b < 0))
                {
                    if(ta == 1)
                    {
                        cout << tb << endl;
                        continue;
                    }
                    else
                    {
                        if(tb == ta) cout << 1 << endl;
                        else cout << tb << "/" << ta << endl;
                        continue;
                    }
                }
                if(tb == ta) cout << -1 << endl;
                else cout << "-" << tb << "/" << ta << endl;
                continue;
            }
            tb = abs(b);
            ta = abs(2 * a);
            int tmp2 = gcd(ta, tb);
            tb /= tmp2;
            ta /= tmp2;
            if(b != 0)
            {
                if((b < 0 || a < 0) && !(a < 0 && b < 0))
                {
                    if(ta == 1)
                        cout << tb << "+";
                    else
                        cout << tb << "/" << ta << "+";
                }
                else cout << "-" << tb << "/" << ta << "+";
            }
            int q2 = spsqrt(delta);
            ta = abs(2 * a);
            int tmp3 = gcd(q2, ta);
            ta /= tmp3;
            int tq2 = q2;
            q2 /= tmp3;
            if(q2 != 1) cout << q2 << "*";
            cout << "sqrt(" << delta / (tq2 * tq2) << ")";
            if(ta != 1) cout << "/" << ta;
            cout << endl;
        }
    }
    return 0;
}
