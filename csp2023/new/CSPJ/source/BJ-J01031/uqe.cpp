#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int T, M;
long long gcd(long long x, long long y)
{
    if(y == 0)return x;
    return gcd(y, x % y);
}
long long hua(long long x){for(long long i = sqrt(x);i >= 1;i--)if(x % (i * i) == 0)return i;}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while(T--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long delta = b * b - 4 * a * c;
        if(delta < 0)cout << "NO\n";
        else
        {
            if(hua(delta) * hua(delta) == delta)
            {
                b = -b + int(sqrt(delta)), a *= 2;
                if(b == 0)cout << "0\n";
                else
                {
                    if(a < 0 && b < 0)a = -a, b = -b;
                    else if(a < 0 && b > 0)
                    {
                        a = -a;
                        cout << "-";
                    }
                    else if(a > 0 && b < 0)
                    {
                        b = -b;
                        cout << "-";
                    }
                    long long k = gcd(a, b);
                    a /= k, b /= k;
                    if(a == 1)cout << b << "\n";
                    else cout << b << "/" << a << "\n";
                }
            }
            else{
                b = -b, a *= 2;
                long long a2 = a;
                if(b != 0)
                {
                    if(a < 0 && b < 0)a = -a, b = -b;
                    else if(a < 0 && b > 0)
                    {
                        a = -a;
                        cout << "-";
                    }
                    else if(a > 0 && b < 0)
                    {
                        b = -b;
                        cout << "-";
                    }
                    long long k = gcd(a, b);
                    a /= k, b /= k;
                    if(a == 1)cout << b;
                    else cout << b << "/" << a;
                    cout << "+";
                }
                long long x = hua(delta);
                delta /= x * x;
                if(a2 < 0)a2 = -a2;
                long long k2 = gcd(a2, x);
                a2 /= k2, x /= k2;
                if(x != 1)cout << x << "*";
                cout << "sqrt(" << delta << ")";
                if(a2 != 1)cout << "/" << a2;
                cout << "\n";
            }
        }
    }
    return 0;
}