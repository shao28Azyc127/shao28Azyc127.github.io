#include <bits/stdc++.h>
using namespace std;

int n, m;
double a, b, c;

int gcd(int x, int y)
{
    int X = max(x, y);
    int Y = min(x, y);
    x = X;
    y = Y;

    int ans = x % y;

    if (x % y == 0)
    {
        return y;
    }

    else
    {
        while (x % ans != 0 || y % ans != 0)
        {
            ans = max(x % ans, y % ans);
        }
        return ans;
    }
}

int main()
{
//    freopen("uqe.in", "r", stdin);
//    freopen("uqe.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0)
        {
            cout << "NO" << endl;
        }
        else if (b * b - 4 * a * c == 0)
        {
            if (b * 2 * a < 0)
            {
                if (ceil(0 - (b / (2 * a))) == 0 - (b / (2 * a)))
                    cout << int(0 - (b / (2 * a))) << endl;
                else
                    cout << abs(b / gcd(2 * a, b)) << '/' << abs(2 * a / gcd(2 * a, b)) << endl;
            }
            else
            {
                if (ceil(b / (2 * a)) == b / (2 * a))
                    cout << '-' << int(0 - (b / (2 * a))) << endl;
                else
                    cout << '-' << abs(b / gcd(2 * a, b)) << '/' << abs(2 * a / gcd(2 * a, b)) << endl;
            }
        }
        else
        {
            if (b * 2 * a < 0)
            {
                if (ceil(0 - (b / (2 * a))) == 0 - (b / (2 * a)))
                    cout << int(0 - (b / (2 * a))) << '+';
                else
                    cout << abs(b / gcd(2 * a, b)) << '/' << abs(2 * a / gcd(2 * a, b)) << '+';
            }
            else if (b * 2 * a == 0)
            {
                cout << '';
            }
            else
            {
                if (ceil(b / (2 * a)) == b / (2 * a))
                    cout << '-' << int(0 - (b / (2 * a))) << '+';
                else
                    cout << '-' << abs(b / gcd(2 * a, b)) << '/' << abs(2 * a / gcd(2 * a, b)) <<'+';
            }  
            
            if (ceil(1 / (2 * a)) == 1 / (2 * a) && 1 / (2 * a) != 1.0)//zhengshu
                cout << int(1 / (2 * a)) * int(sqrt(int(b * b - 4 * a * c))) << "sqrt(" << int(b * b - 4 * a * c) / (sqrt(int(b * b - 4 * a * c)) * sqrt(int(b * b - 4 * a * c))) << ")";
            else if (1 / (2 * a) == 1.0)
                cout << '' << int(sqrt(int(b * b - 4 * a * c))) << "sqrt(" << int(b * b - 4 * a * c) / (sqrt(int(b * b - 4 * a * c)) * sqrt(int(b * b - 4 * a * c))) << ")";
            else
                cout << 1 / (2 * a) << '/' << abs(2 * a / gcd(2 * a, b)) << '+';            
        }
    }
    return 0;
}
