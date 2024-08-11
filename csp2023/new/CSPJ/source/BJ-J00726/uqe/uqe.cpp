#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(a == 0) return b;
    else gcd(b % a, a);
}
bool check(int t)
{
    for(int i = -sqrt(t); i <= sqrt(t); i++)
        if(i * i == t) return true;
    return false;
}
int t, m;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for(int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(b * b - 4 * a * c < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else if(b * b - 4 * a * c >= 0)
        {
            int t = b * b - 4 * a * c;
            if(check(t) == true)
            {
                int max1 = (-b + sqrt(t));
                int max2 = (-b - sqrt(t));
                if((max(max1, max2)) % (2 * a) != 0)
                {
                    int r = gcd(max(max1, max2), 2 * a);
                    if((2 * a) / r < 0 && max(max1, max2) / r >= 0)
                    {
                        cout << "-" << max(max1, max2) / r << '/' << abs((2 * a) / r);
                    }
                    else if((2 * a) / r < 0 && max(max1, max2) / r < 0)
                    {
                        cout << abs(max(max1, max2) / r) << '/' << abs((2 * a) / r);
                    }
                    else cout << max(max1, max2) / r << '/' << (2 * a) / r;
                }
                else
                {
                    cout << max(max1, max2) / (2 * a);
                }
            }
            else
            {
                if(-b % (2 * a) == 0)
                {
                    int r = -b / (2 * a);
                    cout << r << "+" << r << "*" << "sqrt(" << t << ")";
                }
                else
                {
                    int r = gcd(2 * a, -b);
                    cout << -b / r << "/" << (2 * a) / r << "+" << "sqrt(" << t << ")/" << 2 * a;
                }
            }

        }
    }
    return 0;
}

