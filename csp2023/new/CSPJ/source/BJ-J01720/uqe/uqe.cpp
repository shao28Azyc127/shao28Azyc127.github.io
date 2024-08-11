#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, m;
ll gcd(ll a, ll b)
{
    if(a < 0 && b > 0)
        return gcd(-a, b);
    return a % b ? gcd(b, a % b) : b;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while(t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            ll p = -b, q = 2 * a;
            if(q < 0)
                q = -q, p = -p;
            if(p == 0 && delta == 0)
            {
                cout << 0 << endl;
                continue;
            }
            else if(delta == 0)
            {
                ll x = gcd(p, q);
                cout << p / x;
                if(q != x)
                {
                    cout << '/' << q / x;
                }
                cout << endl;
            }
            else
            {
                ll sq = 1;
                for(ll i = sqrt(delta); i > 1; --i)
                {
                    if(delta % (i * i) == 0)
                    {
                        delta /= i * i;
                        sq *= i;
                    }
                }
                if(delta == 1)
                {
                    p += sq;
                    ll x = gcd(p, q);
                    cout << p / x;
                    if(q != x)
                    {
                        cout << '/' << q / x;
                    }
                    cout << endl;
                }
                else
                {
                    //(p + sqrt(delta) * sq) / q
                    ll x;
                    if(p != 0)
                    {
                        x = gcd(p, q);
                        cout << p / x;
                        if(q != x)
                        {
                            cout << '/' << q / x;
                        }
                        cout << '+';
                    }
                    x = gcd(sq, q);
                    if(sq != x)
                        cout << sq / x << '*';
                    cout << "sqrt(" << delta << ')';
                    if(q != x)
                    {
                        cout << '/' << q / x;
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
