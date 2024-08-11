#include <bits/stdc++.h>

using namespace std;

int check (int a, int b, int c)
{
    int ans = b * b - 4 * a * c;
    return ans;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    if (m == 1)
    {
        int a, b, c;
        int i;
        for (i = 1; i <= t; i++)
        {
            cin >> a >> b >> c;
            cout << 0 << endl;
        }
    }
    else
    {
        int a, b, c;
        int i;
        for (i = 1; i <= t; i++)
        {
            cin >> a >> b >> c;
            if (check (a, b ,c) < 0)
            {
                cout << "NO" << endl;
                continue;
            }
            cout << (-b + sqrt(check (a, b, c))) / 2 << endl;
        }
    }
    return 0;
}
