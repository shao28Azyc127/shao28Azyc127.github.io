#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int n;

bool vis[100010];
int h[100010];

long long a[100010];
int b[100010], c[100010];

vector <int> g[100010];
long long ans = 1000000000;

void dfs(int x, int tm, int cnt)
{
    if(tm >= ans) return;
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i]) continue;
        h[i]+=max(b[i] + tm*c[i], 1);
    }
    if(cnt >= n)
    {
        long long tep = 0;
        for(int i = 1;i <= n;i++)
        {
            tep = max(tep, (a[i]-h[i] + b[i]+c[i]-1) / (b[i]+c[i]));
        }
        ans = min(tm + tep, ans);
        return;
    }
    for(int xx = 1;xx <= n;xx++)
    {
        if(!vis[xx]) continue;
        for(int i = 0;i < g[xx].size();i++)
        {
            int y = g[xx][i];
            if(vis[y]) continue;
            vis[y] = 1;
            dfs(y, tm+1, cnt+1);
            vis[y] = 0;
        }
    }

}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld%d%d", &a[i], &b[i], &c[i]);
    }
    for(int i = 1;i < n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vis[1] = 1;
    dfs(1, 1, 1);
    cout << ans;
    return 0;
}
