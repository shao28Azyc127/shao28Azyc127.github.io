#include <iostream>
#include <cmath>

using namespace std;

#define int long long

int t, x;

int fnd(int s)
{
    if (s == 0) return 1;
    for (int i = sqrt(s); i >= 1; i--)
        if (s % (i * i) == 0)
            return i;
    return 1;
}

int gcd(int x, int y) { return (y == 0 ? x : gcd(y, x % y)); }

signed main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("uqe.in" ,"r", stdin);
    freopen("uqe.out", "w", stdout);

    cin >> t >> x;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b * b < 4 * a * c) cout << "NO\n";
        else
        {
            int y = b * b - 4 * a * c;
            int x1 = fnd(y), x2 = y / x1 / x1;
            int GCD = gcd(abs(b), abs(2 * a)), GGCD = gcd(abs(2 * a), x1);
            if (x2 == 1) 
            {
                int p = -b + x1, q = 2 * a;
                int gcd_ = gcd(p, q);
                p /= gcd_, q /= gcd_;
                if (p == 0) cout << "0\n";
                else if (q != 1) cout << p << "/" << q << "\n";
                else cout << p << "\n";
            }
            else
            {
                int p = -b / GCD, q = 2 * a / GCD;
                bool flg = 0;
                if (p * q > 0) p = abs(p), q = abs(q);
                else p = -abs(p), q = abs(q);
                if (p != 0)
                {
                    if (q == 1) cout << p;
                    else cout << p << "/" << q;
                }
                else flg = 1;

                p = x1 / GGCD, q = 2 * a / GGCD;
                // cout << p << " " << q << "\n";
                if (p * q > 0 && x2 != 0) { if (!flg) cout << "+"; p = abs(p), q = abs(q); }
                else p = -abs(p), q = abs(q);
                if (x2 == 0 && flg)
                {
                    cout << "0\n";
                }
                else if (p != 0)
                {
                    if (x2 != 0)
                    {
                        if (x2 == 1)
                        {
                            if (q == 1) cout << p << "\n";
                            else cout << p << "/" << q << "\n";
                        }
                        else 
                        {
                            if (q == 1) 
                            {
                                if (p != -1 && p != 1) cout << p << "*sqrt(" << x2 << ")" << "\n";
                                else if (p == 1) cout << "sqrt(" << x2 << ")" << "\n";
                                else cout << "-sqrt(" << x2 << ")" << "\n";
                            }
                            else 
                            {
                                if (p != -1 && p != 1) cout << p << "*sqrt(" << x2 << ")" << "/" << q << "\n";
                                else if (p == -1) cout << "-sqrt(" << x2 << ")" << "/" << q << "\n";
                                else if (p == 1) cout << "sqrt(" << x2 << ")" << "/" << q << "\n";
                            }
                        }
                    }
                    else cout << "\n";
                }
            }
        }
    }
    return 0;
}