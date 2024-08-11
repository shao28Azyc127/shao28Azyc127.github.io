#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, m, a, b, c, sita, insqrt, outsqrt;

void printfen(ll p, ll q)
{
    if(q < 0) q *= -1, p *= -1;
    for(ll i = 2; i <= q; i++)
        while(q % i == 0 && p % i == 0)
            p /= i, q /= i;
    if(q == 1) cout << p;
    else cout << p << "/" << q;
}

signed main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> m;
    for(ll kkk = 1; kkk <= t; kkk++)
    {
        cin >> a >> b >> c;
        sita = b * b - 4 * a * c;
        if(sita == 0) printfen(-b, 2 * a), cout << endl;
        else if(sita < 0) cout << "NO\n";
        else
        {
            insqrt = sita, outsqrt = 1;
            for(ll i = 2; i * i <= insqrt; i++)
                while(insqrt % (i * i) == 0)
                    insqrt /= i * i, outsqrt *= i;
            if(insqrt != 1)
            {
                if(b != 0) printfen(-b, 2 * a), cout << "+";
                if(outsqrt == 1)
                {
                    if(a < 0) cout << "sqrt(" << insqrt << ")/" << -2 * a << endl;
                    else cout << "sqrt(" << insqrt << ")/" << 2 * a << endl;
                }
                else
                {
                    ll p = outsqrt, q = 2 * abs(a);
                    for(ll i = 2; i <= q; i++)
                        while(q % i == 0 && p % i == 0)
                            p /= i, q /= i;
                    if(q == 1 && p == 1) cout << "sqrt(" << insqrt << ")" << endl;
                    else if(p == 1) cout << "sqrt(" << insqrt << ")/" << q << endl;
                    else if(q == 1) cout << p << "*" << "sqrt(" << insqrt << ")" << endl;
                    else cout << p << "*" << "sqrt(" << insqrt << ")/" << q << endl;
                }
            }
            else
            {
                if(a < 0) printfen(-b - outsqrt, 2 * a), cout << endl;
                else printfen(-b + outsqrt, 2 * a), cout << endl;
            }
        }
    }
    return 0;
}
