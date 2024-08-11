#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    if(a == b) return a;
    if(a == 1) return 1;
    return gcd(min(a, b - a), max(a, b - a));
}

bool isperfsq(int t)
{
    int s = sqrt(t);
    if(s * s == t) return true;
    return false;
}

int calc(int n)
{
    int u = sqrt(n);
    int tot = 1;
    for(int i=2; i<=u; i++)
    {
        while(n % (i * i) == 0)
        {
            tot *= i;
            n /= (i * i);
        }
    }
    return tot;
}

signed main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        long double delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if(delta == 0)
        {
            int x = abs(b);
            int y = abs(2 * a);
            if(x == 0)
            {
                cout << 0 << endl;
                continue;
            }
            int g = gcd(min(x, y), max(x, y));
            if((b > 0) + (2 * a < 0) == 1)
            {
                cout << "-";
            }
            cout << x / g;
            if(y == g) cout << endl;
            else cout << "/" << y / g << endl;
            continue;
        }
        if(isperfsq(delta))
        {
            int sq = sqrt(delta);
            int x = abs(-b + sq);
            if(a < 0) x = abs(-b - sq);
            int y = abs(2 * a);
            if(x == 0)
            {
                cout << 0 << endl;
                continue;
            }
            int g = gcd(min(x, y), max(x, y));
            if((a > 0 && (-b + sq) < 0) || (a < 0 && (-b - sq) > 0))
            {
                cout << "-";
            }
            cout << x / g;
            if(y == g) cout << endl;
            else cout << "/" << y / g << endl;
            continue;
        }
        int x = abs(b);
        int y = abs(2 * a);
        if(x != 0)
        {
            int g = gcd(min(x, y), max(x, y));
            if((b > 0) + (2 * a < 0) == 1)
            {
                cout << "-";
            }
            x /= g;
            y /= g;
            cout << x;
            if(y == 1) cout << "+";
            else cout << "/" << y << "+";
        }
        int q = calc(delta);
        delta = delta / q / q;
        // cout << q << " " << delta << endl; // TEST
        int ta = abs(2 * a);
        int gn = gcd(min(ta, q), max(ta, q));
        ta /= gn;
        q /= gn;
        if(ta == 1 && q == 1) cout << "sqrt(" << delta << ")" << endl;
        else if(ta == 1) cout << q << "*sqrt(" << delta << ")" << endl;
        else if(q == 1) cout << "sqrt(" << delta << ")/" << ta << endl;
        else cout << q << "*sqrt(" << delta << ")/" << ta << endl;
    }
}
