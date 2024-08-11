#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int NR = 5e5 + 10;
const int MR = 5e5 + 10;

int c, n, m, q;
int bx[NR], by[MR];
int x[NR], y[MR];

bool dfs(int nx, int my, int t)
{
    if(nx == n)
    {
        if(t * (x[n] - y[m]) <= 0) return 0;
        for(int j = my; j <= m; j++)
        {
            if(t * (x[n] - y[j]) <= 0) return 0;
        }
        return 1;
    }
    bool flag = 0;
    for(int i = my; i <= m; i++)
    {
        if(t * (x[nx] - y[i]) <= 0) break;
        flag |= dfs(nx + 1, i, t);
    }
    if(my > m)
    {
        if(t * (x[nx] - y[m]) > 0) flag |= dfs(nx + 1, my, t);
    }
    return flag;
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> bx[i];
    for(int j = 1; j <= m; j++) cin >> by[j];
    if(c > 4)
    {
        for(int i = 1; i <= q + 1; i++) cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++) x[i] = bx[i];
    for(int j = 1; j <= m; j++) y[j] = by[j];
    if(dfs(1, 1, 1) || dfs(1, 1, -1))
    {
        cout << 1;
    }
    else cout << 0;
    while(q--)
    {
        for(int j = 1; j <= n; j++) x[j] = bx[j];
        for(int j = 1; j <= m; j++) y[j] = by[j];
        int kx, ky;
        cin >> kx >> ky;
        for(int j = 1; j <= kx; j++)
        {
            int p, v;
            cin >> p >> v;
            x[p] = v;
        }
        for(int j = 1; j <= ky; j++)
        {
            int p, v;
            cin >> p >> v;
            y[p] = v;
        }
        if(dfs(1, 1, 1) || dfs(1, 1, -1))
        {
            cout << 1;
        }
        else cout << 0;
    }
    cout << endl;
    return 0;
}
