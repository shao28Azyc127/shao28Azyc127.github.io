#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
bool isP(int x)
{
    if(x == 0)return true;
    for(int i = 1; i * i <= x; i++)
    {
        if(i * i == x)return true;
    }
    return false;
}
int gcd(int a, int b)
{
    if(b > a)swap(a, b);
    for(int i = b; i >= 1; i--)
    {
        if(a % i == 0 && b % i == 0)return i;
    }
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(1);
    cin.tie(0);
    cout.tie(0);
    int T, M;
    cin >> T >> M;
    while(T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int dt = b * b - 4 * a * c;
        if(dt < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if(isP(dt))
        {
            int s;
            if(dt != 0)s = sqrt(dt);
            else s = 0;
            double ans1 = (-1 * b + s) / (2 * a);
            double ans2 = (-1 * b - s) / (2 * a);
            if(ans1 >= ans2)
            {
                int t1 = -1 * b + s, t2 = 2 * a;
                if(t1 % t2 == 0)
                {
                    cout << t1 / t2 << endl;
                    continue;
                }
                if(gcd(t1, t2) != 1 && t2 != t1)
                {
                    t1 /= gcd(t1, t2);
                    t2 /= gcd(t1, t2);
                }
                    if(t1 < 0 && t2 > 0)
                    {
                        cout << "-" << -1 * t1 << "/" << t2 << endl;
                    }
                    if(t1 > 0 && t2 < 0)
                    {
                        cout << "-" << t1 << "/" << -1 * t2 << endl;
                    }
                    if(t1 < 0 && t2 < 0)
                    {
                        cout << -1 * t1 << "/" << -1 * t2 << endl;
                    }
                    if(t1 > 0 && t2 > 0)
                    {
                        cout << t1 << "/" << t2 << endl;
                    }
            }
            else
            {
                int t1 = -1 * b - s, t2 = 2 * a;
                if(t1 % t2 == 0)
                {
                    cout << t1 / t2 << endl;
                    continue;
                }
                if(t1 == 0 || t2 == 0)
                {
                    cout << 0 << endl;
                    continue;
                }
                if(gcd(t1, t2) != 1 && t1 != t2)
                {
                    t1 /= gcd(t1, t2);
                    t2 /= gcd(t1, t2);
                }
                    if(t1 < 0 && t2 > 0)
                    {
                        cout << "-" << -1 * t1 << "/" << t2 << endl;
                    }
                    if(t1 > 0 && t2 < 0)
                    {
                        cout << "-" << t1 << "/" << -1 * t2 << endl;
                    }
                    if(t1 < 0 && t2 < 0)
                    {
                        cout << -1 * t1 << "/" << -1 * t2 << endl;
                    }
                    if(t1 > 0 && t2 > 0)
                    {
                        cout << t1 << "/" << t2 << endl;
                    }
            }
        }

    }
    return 0;
}
