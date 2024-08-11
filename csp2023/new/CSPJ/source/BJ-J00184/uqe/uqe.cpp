# include <bits/stdc++.h>
using namespace std;

int a, b, c;
int gcd(int x, int y)
{
    int ans = 0;
    for (int i = 1; i <= min(x, y); i++)
    {
        if (x % i == 0 && y % i == 0)
            ans = i;
    }
    return ans;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        int x = b*b - 4*a*c;
        if (x < 0)
        {
            cout << "NO\n";
            continue ;
        }
        if (sqrt(x) * sqrt(x) == x)
        {
            double ans;
            int n;
            ans = max((0-b+sqrt(x)) / (2*a), (0-b-sqrt(x)) / (2*a));
            if ((0-b+sqrt(x)) / (2*a) == ans) n = 1;
            else n = 2;
            if (int(ans) == max((0-b+sqrt(x)) / (2*a), (0-b-sqrt(x)) / (2*a))) cout << ans << endl;
            else
            {
                if (ans < 0) cout << "-";
                int a1;
                if (n == 1)
                    a1 = (0-b+sqrt(x));
                else
                    a1 = (0-b-sqrt(x));
                int a2 = 2 * a;
                a1 = abs(a1);
                a2 = abs(a2);
                int a3 = gcd(a1, a2);
                cout << a1/a3 << "/" << a2/a3 << endl;
            }
        }
    }

    return 0;
}
