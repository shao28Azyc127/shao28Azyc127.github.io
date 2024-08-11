#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    int p = a;
    a = max(a, b);
    b = min(p, b);
    if(b == 0) return -1;
    while (a % b != 0)
    {
        p = b;
        b = a % b;
        a = p;
    }
    return b;
}
int sq(int a)
{
    for (int i = sqrt(a); i >= 1; i--)
    {
        if(a % (i * i) == 0)
        return i;
    }
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    int a, b, c,delta;
    cin >> t >> m;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        delta = b * b - 4 * a * c;
        if(delta < 0) cout << "NO";
        else
        {
            if(b == 0 && delta == 0)
            {
                cout << "0";
            }
             a *= 2;
             int ma = abs(a);
             int sqt = sq(delta);
             delta /= sqt * sqt;
             int g = gcd(sqt, ma);int sqf = ma;
             sqt /= g; sqf /= g;
             int wt = abs(b);
             int wg = gcd(wt, ma);
             wt /= wg;ma /= wg;
             if(delta == 1)
             {
                 int tg = gcd(sqt * ma + wt *sqf, sqf * ma);
                 wt = (sqt * ma + wt *sqf) / tg;
                 ma = sqf * ma / tg;
             }
             if(b > 0 && a > 0 || b < 0 && a < 0) cout<<"-";
             if(b != 0)
             {
                 cout << wt;
                 if(ma != 1)
                    cout << "/" << ma;
             }
             if(delta > 1)
             {
                 cout << "+";
                 if(sqt != 1)cout << sqt << "*";
                 cout << "sqrt(" << delta << ")";
                 if(sqf != 1)cout << "/" << sqf;
             }
        }
        cout << endl;
    }
}