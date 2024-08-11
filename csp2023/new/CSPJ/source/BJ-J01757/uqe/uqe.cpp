#include<bits/stdc++.h>
using namespace std;

long long a, b, c;
long long t, m;

long long gcd(long long x, long long y)
{
    if(x < 0) x *= -1;
    if(y < 0) y *= -1;
    if(y == 0) return x;
    if(x < y) return gcd(y, x);
    return gcd(x % y, y);
}

long long fen(long long x)
{
    long long num = 1;
    for(int i = 2; i * i <= x; i++)
    {
        long long cnt = 0;
        while(x % i == 0)
        {
            cnt++;
            x /= i;
            if(cnt == 2)
            {
                num *= i * i;
                cnt = 0;
            }
        }
    }
    return num;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while(t > 0)
    {
        t--;
        cin >> a >> b >> c;
        long long dt = b * b - 4 * a * c;
        if(dt < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        a *= 2, b *= -1;
        if(a < 0) b *= -1, a *= -1;
        if(int(sqrt(dt)) == sqrt(dt))
        {
            dt = sqrt(dt);
            long long awa = a;
            b += dt;
            a /= gcd(awa, b), b /= gcd(awa, b);
            cout << b;
            if(a != 1) cout << "/" << a;
            cout << endl;
            continue;
        }
        long long q2;
        q2 = sqrt(fen(dt)), dt /= fen(dt);
        long long awa = a, ad = a;
        a /= gcd(awa, b), b /= gcd(awa, b);
        ad /= gcd(awa, q2), q2 /= gcd(awa, q2);
        if(b != 0) cout << b;
        if(a != 1) cout << "/" << a;
        if(b != 0) cout << "+";
        if(q2 != 1) cout << q2 << "*";
        cout << "sqrt(" << dt << ")";
        if(ad != 1) cout << "/" << ad;
        cout << endl;
    }
    return 0;
}
