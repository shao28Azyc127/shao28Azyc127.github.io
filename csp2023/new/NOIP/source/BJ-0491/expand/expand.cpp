#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int c, n, m, q, a[N], b[N], x[N], y[N];
int state, ag;

bool check0()
{
    if(x[1] > y[1] && x[2] > y[1]) return 1;
    else if(x[1] < y[1] && x[2] < y[1]) return 1;
    return 0;
}

bool check1()
{
    if(x[1] > y[1] && x[1] > y[2]) return 1;
    else if(x[1] < y[1] && x[1] < y[2]) return 1;
    return 0;
}
bool check2()
{
    if(x[1] > y[1] && x[1] > y[2] && x[2] > y[2]) return 1;
    else if(x[1] < y[1] && x[1] < y[2] && x[2] < y[2]) return 1;
    else if(x[1] > y[1] && x[2] > y[1] && x[2] > y[2]) return 1;
    else if(x[1] < y[1] && x[2] < y[1] && x[2] < y[2]) return 1;
    else if(x[1] > y[1] && x[2] > y[2]) return 1;
    else if(x[1] < y[1] && x[2] < y[2]) return 1;
    return 0;
}

void dfs(int u, int v)
{
    if(u == n && v == m)
    {
        if(state == 1 && x[n] > y[m])
        {
            ag = 1;
            return ;
        }
        else if(!state && x[n] < y[m])
        {
            ag = 1;
            return ;
        }
        return ;
    }
    else if(u == n)
    {
        if(x[n] == y[v]) return ;
        else if(state == 1 && x[n] < y[v]) return ;
        else if(!state && x[n] > y[v]) return ;
        dfs(n, v + 1);
    }
    else if(v == m)
    {
        if(x[u] == y[m]) return ;
        else if(state == 1 && x[u] < y[m]) return ;
        else if(!state && x[u] > y[m]) return ;
        dfs(u + 1, m);
    }
    else
    {
        if(x[u] == y[v]) return ;
        else if(state == 1 && x[u] < y[v]) return ;
        else if(!state && x[u] > y[v]) return ;
        dfs(u + 1, v);
        dfs(u, v + 1);
        dfs(u + 1, v + 1);
    }

}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        x[i] = a[i];
    }
    for(int i = 1; i <= m; ++ i)
    {
        cin >> b[i];
        y[i] = b[i];
    }
    if(x[1] > y[1]) state = 1;
    else if(x[1] < y[1]) state = 0;
    if(c == 1)
    {
        if(a[1] > b[1]) cout << 1;
        else cout << 0;
    }
    else
    {
        dfs(1, 1);
        cout << ag;
    }
    while(q --)
    {
        ag = 0;
        int kx, ky;
        for(int i = 1; i <= n; ++ i) x[i] = a[i];
        for(int i = 1; i <= m; ++ i) y[i] = b[i];
        cin >> kx >> ky;
        for(int i = 1; i <= kx; ++ i)
        {
            int px, vx;
            cin >> px >> vx;
            x[px] = vx;
        }
        for(int i = 1; i <= ky; ++ i)
        {
            int py, vy;
            cin >> py >> vy;
            y[py] = vy;
        } 
        if(x[1] > y[1]) state = 1;
        else if(x[1] < y[1]) state = 0;
        if(c == 1)
        {
            if(x[1] > y[1]) cout << 1;
            else cout << 0;
        }
        else
        {
            dfs(1, 1);
            cout << ag;
        }
    }
    return 0;
}