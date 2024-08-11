#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, d;

int x[100010];
int y[100010];
int v[100010];

int w[19];
int ds[19];

int maxn;

void dfs(int st, int la)
{
    if(la > k) return ;
    if(st > n)
    {
        for(int i=1; i<=n; i++)
        {
            ds[i] = ds[i - 1] + w[i];
        }
        int rew = 0;
        for(int i=1; i<=m; i++)
        {
            if(ds[x[i]] - ds[x[i]-y[i]] == y[i])
            {
                rew += v[i];
            }
        }
        rew -= ds[n] * d;
        maxn = max(maxn, rew);
        return ;
    }
    w[st] = 0;
    dfs(st + 1, 0);
    w[st] = 1;
    dfs(st + 1, la + 1);
}

signed main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    if(c <= 2)
    {
        while(t--)
        {
            memset(w, 0, sizeof(w));
            memset(ds, 0, sizeof(ds));
            cin >> n >> m >> k >> d;
            for(int i=1; i<=m; i++)
            {
                cin >> x[i] >> y[i] >> v[i];
            }
            dfs(1, 0);
            cout << maxn << endl;
        }
        return 0;
    }
    while(t--)
    {
        cin >> n >> m >> k >> d;
        int total = 0;
        for(int i=1; i<=m; i++)
        {
            cin >> x[i] >> y[i] >> v[i];
            int cost = y[i] * d;
            if(v[i] > cost && y[i] <= k) total += v[i] - cost;
        }
        cout << total << endl;
    }
}
// 216
