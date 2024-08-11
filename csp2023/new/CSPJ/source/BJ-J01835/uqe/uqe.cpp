#include <iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int t, m, a, b, c;
int gcd(int x, int y)
{
    int maxi = 1;
    for(int i = 1; i <= min(x, y); i++)
    {
        if(x % i == 0 && y % i == 0 && i > maxi)
        {
            maxi = i;
        }
    }
    return maxi;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        int x = b * b - 4 * a * c;
        if(x < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        double y;
        int z;
        if(c == 0)
        {
            if(a >= 0)
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                y = -b / (double)a;
                if(y == -b / a)
                {
                    cout << -b / a << endl;
                    continue;
                }
                else
                {
                    if(-b < 0 && a < 0)
                    {
                        b *= -1;
                        a *= -1;
                    }
                    cout << -b / gcd(-b, a) << "/" << a / gcd(-b, a);
                    continue;
                }
            }
        }
        if(a >= 0)
        {
            z = (-b + sqrt(x)) / 2 / a;
            cout << z << endl;
            continue;
        }
        else
        {
            z = (-b - sqrt(x)) / 2 / a;
            cout << z << endl;
            continue;
        }
    }
    return 0;
}
