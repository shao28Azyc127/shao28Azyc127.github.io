#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, q;

int x[500010];
int y[500010];

int f[500010];
int g[500010];

void solve_c2()
{
    if(n == 1)
    {
        if((y[1] - x[1]) * (y[2] - x[1]) > 0)
        {
            cout << 1;
        }
        else cout << 0;
        return ;
    }
    else if(m == 1)
    {
        if((x[1] - y[1]) * (x[2] - y[1]) > 0)
        {
            cout << 1;
        }
        else cout << 0;
        return ;
    }
    if((x[1] - y[1]) * (x[2] - y[2]) > 0)
    {
        cout << 1;
    }
    else cout << 0;
    return ;
}

signed main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    if(n == 1 && m == 1)
    {
        int a, b;
        cin >> a >> b;
        int ta, tb;
        ta = a, tb = b;
        if(a == b) cout << 0;
        else cout << 1;
        while(q--)
        {
            int kx, ky;
            cin >> kx >> ky;
            a = ta, b = tb;
            for(int i=1; i<=kx; i++)
            {
                int id, val;
                cin >> id >> val;
                a = val;
            }
            for(int i=1; i<=ky; i++)
            {
                int id, val;
                cin >> id >> val;
                b = val;
            }
            if(a == b) cout << 0;
            else cout << 1;
        }
        return 0;
    }
    if(c == 2)
    {
        for(int i=1; i<=n; i++)
        {
            cin >> x[i];
            f[i] = x[i];
        }
        for(int i=1; i<=m; i++)
        {
            cin >> y[i];
            g[i] = y[i];
        }
        solve_c2();
        while(q--)
        {
            for(int i=1; i<=n; i++)
            {
                x[i] = f[i];
            }
            for(int i=1; i<=m; i++)
            {
                y[i] = g[i];
            }
            int kx, ky;
            cin >> kx >> ky;
            for(int i=1; i<=kx; i++)
            {
                int id, val;
                cin >> id >> val;
                x[id] = val;
            }
            for(int i=1; i<=ky; i++)
            {
                int id, val;
                cin >> id >> val;
                y[id] = val;
            }
            solve_c2();
        }
        return 0;
    }
}
// 216
