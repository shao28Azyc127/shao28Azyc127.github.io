#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long T, M, a, b, c, delta, p2 = 1;

long long gcd (long long a, long long b)
{
    if (a % b == 0) return b;
        else return gcd(b, abs(a - b));
}

void sd()
{
    for (int i = 2; i * i <= delta; i++)
    {
        while (delta % (i * i) == 0) delta /= (i * i), p2 *= i;
    }
    return;
}

int main ()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%lld%lld", &T, &M);
    for (int i = 0; i < T; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a < 0) a *= -1, b *= -1, c *= -1;
        delta = b * b - 4 * a * c;
        p2 = 1;
        if (delta < 0) cout << "NO" << endl;
            else
            {
                if (delta > 0) sd();
                if (delta == 1 || delta == 0)
                {
                    int p = b * (-1) + (p2 * delta), q = a * 2;
                    int x = p / abs(p), y = q / abs(q);
                    if (abs(p) % (abs(q)) == 0) cout << p / q << endl;
                        else{
                            long long gcds = gcd(max(abs(p),abs(q)), min(abs(p), abs(q)));
                            cout << x * y * abs(p) / gcds << '/' << abs(q) / gcds << endl;
                        }
                }
                    else{
                        int p1p = b * (-1), p1q = a * 2;
                        int x1 = p1p / abs(p1p), y1 = p1q / abs(p1q);
                        if (p1p * p1q == 0) cout <<"";
                        else
                        {
                            if ((abs(p1p) % (abs(p1q)) == 0)) cout << p1p / p1q;
                            else{
                                long long gcds = gcd(max(abs(p1p),abs(p1q)), min(abs(p1p), abs(p1q)));
                                cout << x1 * y1 * abs(p1p) / gcds << '/' << abs(p1q) / gcds;
                            }
                            cout << "+";
                        }
                        int p2p = p2, p2q = 2 * a;
                        if ((abs(p2p) % (abs(p2q)) == 0) && p2p != p2q) cout << p2p / p2q << "*sqrt(" << delta << ")" << endl;
                            else{
                                long long gcds = gcd(max(abs(p2p),abs(p2q)), min(abs(p2p), abs(p2q)));
                                if (p2p / gcds > 1) cout << p2p / gcds << '*';
                                cout << "sqrt(" << delta << ")";
                                if (p2q / gcds > 1) cout << '/' << p2q / gcds;
                                cout << endl;
                            }
                    }
            }
    }
    return 0;
}
