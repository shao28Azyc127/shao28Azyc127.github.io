#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int C, T;
int n, m;
int x[MAXN*2], fa[MAXN*2];
int xp[MAXN*2];
vector<int> g[MAXN*2];
bool vis[MAXN*2];
int ans;

int fd(int u)
{
    if (fa[u] == u)
    {
        return u;
    }

    fa[u] = fd(fa[u]);
    return fa[u];
}

void merge(int u, int v)
{
    int ancu = fd(u);
    int ancv = fd(v);

    if (ancu == ancv)
    {
        return;
    }

    fa[ancu] = ancv;
    return;
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> C >> T;

    while (T--)
    {
        cin >> n >> m;

        int d = n+2;
        for (int i = 1; i <= 2*d; i++)
        {
            fa[i] = i;
            x[i] = i;
        }

        for (int i = 1; i <= d; i++)
        {
            xp[i] = i + d;
        }
        for (int i = d+1; i <= 2*d; i++)
        {
            xp[i] = i - d;
        }

        for (int i = 0; i < m; i++)
        {
            char op;
            cin >> op;

            if (op == 'T' || op == 'F' || op == 'U')
            {
                int v;
                cin >> v;

                if (op == 'T')
                {
                    x[v] = n+1;
                    x[v+d] = n+1+d;
                }
                else if (op == 'F')
                {
                    x[v] = n+1+d;
                    x[v+d] = n+1;
                }
                else
                {
                    x[v] = n+2;
                    x[v+d] = n+2+d;
                }
            }
            else if (op == '+')
            {
                int vi, vj;
                cin >> vi >> vj;

                x[vi] = x[vj];
                x[vi+d] = xp[x[vi]];
            }
            else
            {
                int vi, vj;
                cin >> vi >> vj;

                x[vi] = xp[x[vj]];
                x[vi+d] = xp[x[vi]];
            }
        }

        // if (T == 3)
        // {
        //     bool flag = false;
        //     for (int i = 1; i <= 2*d; i++)
        //     {   
        //         // cout << x[i] << " ";

        //         if (x[i] == 0)
        //         {
        //             flag = true;
        //         }
        //     }
        //     cout << flag << "\n";
        //     cout << "\n";
        // }

        for (int i = 1; i <= 2*d; i++)
        {
            merge(i, x[i]);
        }

        for (int i = 1; i <= 2*d; i++)
        {
            fa[i] = fd(i);
            g[fa[i]].push_back(i);
        }

        // for (int i = 1; i <= 2*d; i++)
        // {
        //     cout << "[" << i << "] ";
        //     for (int j = 0; j < g[i].size(); j++)
        //     {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        ans = g[fa[d]].size() - 1 + g[fa[d*2]].size() - 1;
        vis[fa[d]] = vis[fa[d*2]] = true;

        // cout << ans << "*\n";

        for (int i = 1; i <= n; i++)
        {
            if (!vis[fa[i]] && fa[i] == fa[i+d])
            {
                // cout << g[fa[i]].size() << " ";
                vis[fa[i]] = true;
                ans += g[fa[i]].size();
            }
        }

        cout << ans/2 << "\n";

        for (int i = 1; i <= 2*d; i++)
        {
            g[i].clear();
            vis[i] = false;
        }
    }
    return 0;
}