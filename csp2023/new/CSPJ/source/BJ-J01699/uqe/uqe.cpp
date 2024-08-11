#include<bits/stdc++.h>
using namespace std;
int Mod[3000];
int gcd(int a, int b)
{
    if(a > b) swap(a, b);
    if(!a) return b;
    return gcd(a, b % a);
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, M;
    cin >> t >> M;
    for(int i = 1; i <= 1000; i ++) Mod[i] = i * i;
    while(t --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int delta_sq = (b * b - 4 * a * c);
        if(delta_sq < 0) cout << "NO" << endl;
        else
        {
            int delta = sqrt(delta_sq);
            //cout << delta << endl;
            if(delta * delta == delta_sq) 
            {
                //cout << -b << endl;
                //cout << 2 * a << endl;
                int t = a / abs(a);
                if((-b + delta) / t > (-b - delta) / t) delta = -b + delta;
                else delta = -b - delta;
                //cout << delta << endl;
                if(delta % (2 * a) == 0) cout << delta / (2 * a) << endl;
                else 
                {
                    a *= 2;
                    int p = gcd(abs(delta), abs(a));
                    if(delta < 0 && a < 0) delta = -delta, a = -a;
                    if(delta >= 0 && a < 0) delta = -delta, a = -a;
                    delta /= p, a /= p;
                    if(a != 1)cout << delta << "/" << a << endl; 
                    else cout << delta << endl;
                }
            }
            else
            {
                a *= 2;
                if(b != 0) 
                {
                    int a2 = a, b2 = b;
                    b = -b;
                    if(a < 0 && b < 0) a = -a, b = -b;
                    if(a < 0 && b >= 0) a = -a, b = -b;
                    int gcdab = gcd(abs(a), abs(b));
                    a /= gcdab, b /= gcdab;
                    if(a == 1) cout << b << "+";
                    else cout << b <<"/"<<a<<"+";
                    a = a2, b = b2;
                }
                int q2 = 1;
                for(int i = 2; i <= 1000; i ++)
                {
                    if(delta_sq < Mod[i]) break;
                    else 
                    {
                        while(delta_sq % Mod[i] == 0)
                        {
                            delta_sq /= Mod[i];
                            q2 *= i;
                        }
                    }
                }
                if(q2 < 0 && a < 0) q2 = -q2, a = -a;
                if(q2 > 0 && a < 0) q2 = -q2, a = -a;
                if(q2 < 0) q2 = -q2;
                int l = gcd(abs(q2), abs(a));
                q2 /= l, a /= l;
                if(q2 % a == 0)
                {
                    q2 /= a;
                    if(q2 / a == 1) cout << "sqrt(" << delta_sq << ")" << endl;
                    else cout << q2 << "*" << "sqrt(" << delta_sq << ")" << endl;
                } 
                else
                {
                    if(q2 == 1) cout << "sqrt(" << delta_sq << ")/" << a << endl;
                    else
                    {
                        cout << q2 << "*sqrt(" << delta_sq << ")/" << a << endl;
                    }
                }
            }
        }
    }
    return 0;
}  