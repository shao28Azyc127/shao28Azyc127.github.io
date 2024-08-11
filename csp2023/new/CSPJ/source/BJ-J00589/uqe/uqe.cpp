#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool is_wanping(int r)
{
    double a = sqrt(r);
    if (abs(a - floor(a)) < (1 / 1e6) || abs(ceil(a) - a) < (1 / 1e6))
    {
        return true;
    }
    return false;
}
void print_wulishu(int p, int q, int r)
{
    int t = __gcd(p, q);
    p /= t;
    q /= t;
    if (q < 0)
    {
        p *= -1;
        q *= -1;
    }
    if (is_wanping(r))
    {
        p *= sqrt(r);
        t = __gcd(p, q);
        p /= t;
        q /= t;
        if (q < 0)
        {
            p *= -1;
            q *= -1;
        }
        if (q == 1)
        {
            cout << p;
        }
        else
        {
            cout << p << '/' << q;
        }
    }
    else
    {
        for (int i = 2; i <= r; i++)
        {
            if (r % i == 0 && is_wanping(i))
            {
                r /= i;
                p *= sqrt(i);
                i--;
            }
        }
        t = __gcd(p, q);
        p /= t;
        q /= t;
        if (q < 0)
        {
            p *= -1;
            q *= -1;
        }
        if (p == q && p == 1)
        {
            cout << "sqrt(" << r << ")";
        }
        else if (p == 1)
        {
            cout << "sqrt(" << r << ")/" << q;
        }
        else if (q == 1)
        {
            cout << p << "*sqrt(" << r << ")";
        }
        else
        {
            cout << p << "*sqrt(" << r << ")/" << q;
        }
    }
}
signed main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, w;
    cin >> t >> w;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            cout << "NO";
        }
        else
        {
            if (b == 0)
            {
                print_wulishu(a > 0 ? 1 : -1, 2 * a, delta);
            }
            else if (delta == 0)
            {
                print_wulishu(b * -1, 2 * a, 1);
            }
            else
            {
                if (is_wanping(delta))
                {
                    print_wulishu(b * -1 + (a > 0 ? 1 : -1) * sqrt(delta), 2 * a, 1);
                }
                else
                {
                    print_wulishu(b * -1, 2 * a, 1);
                    cout << '+';
                    print_wulishu(a > 0 ? 1 : -1, 2 * a, delta);
                }
            }
        }
        cout << endl;
    }
    return 0;
}