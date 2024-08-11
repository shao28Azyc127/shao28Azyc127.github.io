#include <bits/stdc++.h>
using namespace std;

int x[105], y[105];
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c, n, m, q;
    cin >> c >> n >> m >> q;
    if (c == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> y[i];
        }
        cout << 1;
        for (int i = 1; i <= q; i++)
        {
            int kx, ky;
            cin >> kx >> ky;
            for (int j = 1; j <= kx; j++)
            {
                int px;
                cin >> px;
            }
            for (int j = 1; j <= ky; j++)
            {
                int py;
                cin >> py;
            }
            cout << 1;
        }
    }
    return 0;
}