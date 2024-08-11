#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int t, m;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    cin >> t >> m;
    for(int i = 1; i <= t; i ++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        int x = b * b - 4 * a * c;

        if(x < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        
        if(b == 0 && c == 0)
        {
            cout << 0 << endl;
            continue;
        }

        if(x == 0)
        {
            int f1 = -b;
            int f2 = 2 * a;

            if(f1 % f2 == 0)
            {
                cout << f1 / f2 << endl;
                continue;
            }
            else
            {
                int q = __gcd(f1, f2);
                cout << f1 / q << "/" << f2 / q << endl;
                continue;
            }
        }

        if(x > 0)
        {
            int f2 = a * 2;
            if(f2 > 0)
            {
                int q = sqrt(x);
                if(q * q == x)
                {
                    int f1 = -b + q;

                    if(f1 % f2 == 0)
                    {
                        cout << f1 / f2 << endl;
                        continue;
                    }
                    else
                    {
                        int q = __gcd(f1, f2);
                        cout << f1 / q << "/" << f2 / q << endl;
                        continue;
                    }
                }
                else
                {
                    int v = 1, xx = x;
                    for(int i = 1; i * i <= x / 2; i ++)
                    {
                        if(x % (i * i) == 0)
                        {
                            v *= i;
                            xx /= i * i;
                        }
                    }

                    int f1 = -b;
                    int f2 = 2 * a;
                    int f3 = v;
                    int f4 = f2;

                    if(f1 % f2 == 0)
                    {
                        if(f3 % f4 == 0)
                        {
                            if(f3 % f4 != 1) cout << f1 / f2 << "+" << f3 / f4 << "*sqrt(" << xx << ")" << endl;
                            else cout << f1 / f2 << "+" << "sqrt(" << xx << ")" << endl;
                            continue;
                        }
                        else
                        {
                            int q = __gcd(f3, f4);
                            if(f3 / q != 1) cout << f1 / f2 << "+" << f3 / q << "*sqrt(" << xx << ")/" << f4 / q << endl;
                            else cout << f1 / f2 << "+" << "sqrt(" << xx << ")/" << f4 / q << endl;
                            continue;
                        }
                    }
                    else
                    {
                        int q = __gcd(f1, f2);

                        if(f3 % f4 == 0)
                        {
                            if(f3 % f4 != 1) cout << f1 / q << "/" << f2 / q << "+" << f3 / f4 << "*sqrt(" << xx << ")" << endl;
                            else cout << f1 / q << "/" << f2 / q << "+" << "sqrt(" << xx << ")" << endl;
                            continue;
                        }
                        else
                        {
                            int qq = __gcd(f3, f4);
                            if(f3 / qq != 1) cout << f1 / q << "/" << f2 / q << "+" << f3 / qq << "*sqrt(" << xx << ")/" << f4 / qq << endl;
                            else cout << f1 / q << "/" << f2 / q << "+" << "sqrt(" << xx << ")/" << f4 / qq << endl;
                            continue;
                        }
                    }
                }
            }
            else
            {
                int q = sqrt(x);
                if(q * q == x)
                {
                    int f1 = -b - q;

                    if(f1 % f2 == 0)
                    {
                        cout << f1 / f2 << endl;
                        continue;
                    }
                    else
                    {
                        int q = __gcd(f1, f2);
                        cout << f1 / q << "/" << f2 / q << endl;
                        continue;
                    }
                }
                else
                {
                    int v = 1, xx = x;
                    for(int i = 1; i * i <= x / 2; i ++)
                    {
                        if(x % (i * i) == 0)
                        {
                            v *= i;
                            xx /= i * i;
                        }
                    }

                    int f1 = -b;
                    int f2 = 2 * a;
                    int f3 = v;
                    int f4 = f2;

                    if(f1 % f2 == 0)
                    {
                        if(f3 % f4 == 0)
                        {
                            if(f3 / f4 != 1) cout << f1 / f2 << "-" << f3 / f4 << "*sqrt(" << xx << ")" << endl;
                            else cout << f1 / f2 << "-" << "sqrt(" << xx << ")" << endl;
                            continue;
                        }
                        else
                        {
                            int q = __gcd(f3, f4);
                            if(f3 / q != 1) cout << f1 / f2 << "-" << f3 / q << "*sqrt(" << xx << ")/" << f4 / q << endl;
                            else cout << f1 / f2 << "-" << "sqrt(" << xx << ")/" << f4 / q << endl;
                            continue;
                        }
                    }
                    else
                    {
                        int q = __gcd(f1, f2);

                        if(f3 % f4 == 0)
                        {
                            if(f3 / f4 != 1) cout << f1 / q << "/" << f2 / q << "-" << f3 / f4 << "*sqrt(" << xx << ")" << endl;
                            else cout << f1 / q << "/" << f2 / q << "-" << "sqrt(" << xx << ")" << endl;
                            continue;
                        }
                        else
                        {
                            int qq = __gcd(f3, f4);
                            if(f3 / qq != 1) cout << f1 / q << "/" << f2 / q << "-" << f3 / qq << "*sqrt(" << xx << ")/" << f4 / qq << endl;
                            else cout << f1 / q << "/" << f2 / q << "-"  << "*sqrt(" << xx << ")/" << f4 / qq << endl;
                            continue;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
