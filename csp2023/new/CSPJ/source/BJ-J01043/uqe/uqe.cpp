#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;

const int maxT = 5005, maxM = 1005;
int t = 0, m = 0;
//----------Methods----------
int dagongyin(int a, int b)
{
    a = abs(a); b = abs(b);
    if (b > a)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    for(int i = b; i > 1; i--)
        if (b % i == 0 && a % i == 0) return i;
    return 1;
}
//----------Main----------
int main()
{
    ios::sync_with_stdio(false);
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> t >> m;
    for(int k = 0; k < t; k++)
    {
        int a = 0, b = 0, c = 0, delta = 0;
        cin >> a >> b >> c;
        int bcs = 2 * a;
        delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "NO\n";
            continue;
        }
        double tx = -b + sqrt(delta), x = tx / bcs;
        if ((double)(int)tx == tx)
        {
            if((double)(int)x == x)
            {
                cout << x << endl;
                continue;
            }
            else
            {
                int dgy = dagongyin(tx, bcs);
                if(dgy != 1)
                {
                    if(bcs < 0)
                    {
                        cout << -(tx / dgy) << "/" << -(bcs / dgy) << endl;
                        continue;
                    }
                    cout << tx / dgy << "/" << bcs / dgy << endl;
                    continue;
                }
                if(bcs < 0)
                {
                    cout << -tx << "/" << -bcs << endl;
                    continue;
                }
                cout << tx << "/" << bcs << endl;
                continue;
            }
        }
        double q2 = 1; int r = delta;
        if((int)sqrt(delta) * (int)sqrt(delta) != delta);
        {
            double q1 = -b / bcs;
            if (q1 != 0)
                if(-b % bcs == 0)
                    cout << q1 << "+";
                else
                {
                    int dgy2 = dagongyin(-b, bcs);
                    if (dgy2 != 1)
                    {
                        if(bcs < 0)
                            cout << b / dgy2 << "/" << -bcs / dgy2 << "+";
                        else
                            cout << -b / dgy2 << "/" << bcs / dgy2 << "+";
                    }
                    else
                        if(bcs < 0)
                            cout << b << "/" << -bcs << "+";
                        else
                            cout << -b << "/" << bcs << "+";
                }

            int maxTry = sqrt(delta);
            for(int i = maxTry; i > 1; i--)
            {
                if (r % (i * i) == 0)
                {
                    q2 = q2 * i;
                    r = delta / (i * i);
                }
            }

            double q3 = 1 / q2;
            if (q2 > 1 && ((double)(int)q3 != q3))
            {
                int dgy3 = dagongyin(q2, bcs);
                if(q2 == bcs)
                {
                    cout << "sqrt(" << r << ")\n";
                    continue;
                }
                if ((int)q2 % bcs == 0)
                {
                    if (abs(q2 / bcs) == 1)
                    {
                        cout << "sqrt(" << r << ")\n";
                        continue;
                    }
                    cout << abs(q2 / bcs) << "*sqrt(" << r << ")\n";
                    continue;
                }
                if(dgy3 == 1)
                {
                    cout << abs(q2) << "*sqrt(" << r << ")/" << abs(bcs) << endl;
                    continue;
                }
                if(q2 / dgy3 == 1)
                {
                    cout << "sqrt(" << r << ")/" << abs(bcs / dgy3) << endl;
                    continue;
                }
                cout << abs(q2 / dgy3) << "*sqrt(" << r << ")/" << abs(bcs / dgy3) << endl;
                continue;
            }
/*
            if (((double)(int)q3 == q3) && q2 > 0 && q2 != 1)
            {
                cout << "sqrt(" << delta << ")/" << abs(bcs) << endl;
                continue;
            }*/
            cout << "sqrt(" << delta << ")/" << abs(bcs) << endl;
        }
    }
    return 0;
}
