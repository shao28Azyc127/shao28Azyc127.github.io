#include<bits/stdc++.h>
using namespace std;

int T, m;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> m;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b*b - 4*a*c < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int x = -1, y = -1;
        for (int i = -m; i <= m; i++)
        {
            if (a*i*i + b*i + c == 0)
            {
                if (x == -1)
                    x = i;
                else
                {
                    y = i;
                    break;
                }
            }
        }
        int ans = max(x, y);
        cout << ans << endl;
    }
    return 0;
}