#include <bits/stdc++.h>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define lowbit(x) ((x)&-(x))
#define abs(x) (((x)>=0)?(x):((-x)))
using namespace std;
int t, m, a, b, c, d;
int quikpower(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}
int gcd(const int a, const int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
void huajian(int &a, int &b)
{
    if (a == 0)
    {
        b = 1;
        return;
    }
    if (b < 0)
    {
        a = -a;
        b = -b;
    }
    int k = gcd(abs(a), abs(b));
    a /= k;
    b /= k;
}
void solve()
{
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d < 0)
    {
        cout << "NO\n";
        return;
    }
    if (d == 0)
    {
        int p = -b;
        int q = 2 * a;
        huajian(p, q);
        if (q == 1)
        {
            cout << p << endl;
        }
        else
        {
            cout << p << "/" << q << endl;
        }
        return;
    }
    int ds = 1, t = d;
    unordered_map<int,int> mp;
    mp.clear();
    for (int i = 2; i * i <= t; i++)
    {
        while (t % i == 0)
        {
            t /= i;
            mp[i]++;
        }
    }
    for (pair<int,int> i : mp)
    {
        ds *= quikpower(i.first, i.second / 2);
    }
    int o = -b, p = ds, q = d / ds / ds, r = 2 * a, s = 2 * a; // o/r+p*sqrt(q)/s
    // cout << o << "/" << r << "+" << p << "*sqrt(" << q << ")/" << s << "\t";
    huajian(o, r);
    huajian(p, s);
    p = abs(p);
    if (q == 1)
    {
        o = o * s + p * r;
        r *= s;
        huajian(o, r);
        if (r == 1)
        {
            cout << o << endl;
        }
        else
        {
            cout << o << "/" << r << endl;
        }
        return;
    }
    if (o != 0)
    {
        if (r == 1)
        {
            cout << o;
        }
        else
        {
            cout << o << "/" << r;
        }
        if (p == 0 || q == 0)
        {
            cout << endl;
            return;
        }
        if (p < 0)
        {
            cout << p << "*";
            if (q != 1)
            {
                cout << "sqrt(" << q << ")";
            }
            if (s != 1)
            {
                cout << "/" << s;
            }
        }
        else
        {
            if (p != 1)
            {
                cout << "+" << p << "*";
            }
            else
            {
                cout << "+";
            }
            if (q != 1)
            {
                cout << "sqrt(" << q << ")";
            }
            if (s != 1)
            {
                cout << "/" << s;
            }
        }
        cout << endl;
        return;
    }
    if (p != 1)
    {
        cout << p << "*";
    }
    if (q != 1)
    {
        cout << "sqrt(" << q << ")";
    }
    if (s != 1)
    {
        cout << "/" << s;
    }
    cout << endl;
}
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while (t--)
    {
        solve();
    }
    return 0;
}