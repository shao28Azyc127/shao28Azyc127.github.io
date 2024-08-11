#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 5;

int n;
vector<int> g[MAXN];
LL a[MAXN], b[MAXN], c[MAXN];
LL ans;
int vis[MAXN];
int flag[MAXN];

LL cal(int x, int d)
{
    LL t = 0, i;
    for (i = d; t < a[x]; i++)
    {
        t += max(b[x] + c[x] * i, 1ll*1);
        // cout << t << " ";
    }
    // cout << "\n";

    return i-1;
}


void dfs(int u, LL tim, int stp)
{
    if (tim > ans)
    {
        return;
    }

    bool chk = true;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != 1)
        {
            chk = false;
            break;
        }
    }

    if (chk)
    {
        ans = min(ans, tim);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 2)
        {
            int sz = g[i].size();
            for (int j = 0; j < sz; j++)
            {
                if (vis[g[i][j]] == 0)
                {
                    vis[g[i][j]] = 2;
                    flag[g[i][j]] = 1;
                }
            }

            vis[i] = 1;
            dfs(i, max(tim, cal(i, stp)), stp+1);

            for (int j = 0; j < sz; j++)
            {
                if (flag[g[i][j]] == 1)
                {
                    vis[g[i][j]] = 0;
                    flag[g[i][j]] = 0;
                }
            }

            vis[i] = 2;
        }
    }

    return;
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        int ui, vi;
        cin >> ui >> vi;

        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }

    ans = 2e9;

    vis[1] = 1;

    int sz = g[1].size();
    for (int i = 0; i < sz; i++)
    {
        vis[g[1][i]] = 2;
    }

    // cout << cal(1, 1) << endl;

    dfs(1, cal(1, 1), 2);

    cout << ans << "\n";
    return 0;
}