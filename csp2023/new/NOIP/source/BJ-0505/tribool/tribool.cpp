#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e5 + 10;
const int MR = 1e5 + 10;

// T == n + 1, F == - n - 1, U == 0
int v[NR];
bool f[NR];
int tv[NR];
int fa[2 * NR];

int fin(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = fin(fa[x]);
}

void mer(int x, int y)
{
    fa[fin(x)] = fin(y);
}

bool check(int x, int y)
{
    return fin(x) == fin(y);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int C, t;
    cin >> C >> t;
    while(t--)
    {
        memset(v, 0, sizeof(v));
        memset(tv, 0, sizeof(tv));
        memset(f, 0, sizeof(f));
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            tv[i] = i;
            v[i] = i;
        }
        for(int i = 1; i <= m; i++)
        {
            char c;
            cin >> c;
            int x, y;
            if(c == '+')
            {
                cin >> x >> y;
                v[x] = v[y];
                continue;
            }
            if(c == '-')
            {
                cin >> x >> y;
                v[x] = -v[y];
                continue;
            }
            if(c == 'T')
            {
                cin >> x;
                v[x] = n + 1;
                continue;
            }
            if(c == 'F')
            {
                cin >> x;
                v[x] = - n - 1;
                continue;
            }
            if(c == 'U')
            {
                cin >> x;
                v[x] = 0;
                continue;
            }
        }
        while(1)
        {
            bool flag = 0;
            for(int i = 1; i <= n; i++)
            {
                if(f[i]) continue;
                if(v[i] == 0 || v[i] == n + 1 || v[i] == - n - 1)
                {
                    tv[i] = v[i];
                    f[i] = 1;
                    flag = 1;
                    continue;
                }
                int id = abs(v[i]);
                if(f[id])
                {
                    tv[i] = v[i] / id * tv[id];
                    f[i] = 1;
                    flag = 1;
                    continue;
                }
            }
            if(!flag) break;
        }
        for(int i = 1; i <= 2 * n; i++) fa[i] = i;
        for(int i = 1; i <= n; i++)
        {
            if(f[i]) continue;
            int id = abs(v[i]);
            if(v[i] < 0)
            {
                mer(i, n + id);
                mer(n + i, id);
            }
            else
            {
                mer(i, id);
                mer(n + i, n + id);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(f[i])
            {
                if(tv[i] == 0) ans++;
                continue;
            }
            if(check(i, n + i)) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
