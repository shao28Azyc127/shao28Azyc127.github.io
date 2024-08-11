#include<bits/stdc++.h>
using namespace std;
bool vis[10010][110];
vector<pair<int, int> > g[10010];
struct node
{
    int pos;
    long long dis;
};
int n, m, k;
queue<node> q, emp;
bool Check(long long x)
{
    memset(vis, false, sizeof vis);
    q = emp;
    q.push({n, x});
    vis[n][0] = true;
    while(!q.empty())
    {
        node f = q.front();
        q.pop();
        for(auto i : g[f.pos])
        {
            int tp = i.first;
            int td = f.dis - 1;
            if(td < i.second) continue;
            if(!vis[tp][td % k])
            {
                vis[tp][td % k] = true;
                q.push({tp, td});
            }
        }
    }
    return vis[1][0];
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    int mx = 0;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[v].push_back({u, w});
        mx = max(mx, w);
    }
    int l = 0, r = mx;
    long long best = -1;
    while(l <= r)
    {
        int mid = l + (r - l >> 1);
        if(Check(mid * 1ll * k))
        {
            best = mid * 1ll * k;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    printf("%lld", best);
    return 0;
}
/*

*/
