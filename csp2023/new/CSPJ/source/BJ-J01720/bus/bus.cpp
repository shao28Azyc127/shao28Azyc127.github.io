#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, k, maxa = -1e9;
ll vis[10005][105];
struct edge
{
    ll to, a;
} e[20005];
vector<ll> o[10005];//存编号为i的点所有出边的下标
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
    {
        ll u;
        cin >> u >> e[i].to >> e[i].a;
        o[u].emplace_back(i);
    }
    ll ans = -1;
    memset(vis, 0x3f, sizeof(vis));
    queue<ll> q, qd;
    q.push(1);
    qd.push(0);
    vis[1][0] = 0;
    while(!q.empty())
    {
        int now = q.front(), nk = qd.front() % k, d = qd.front();
        if(now == n && nk == 0)
        {
            ans = d;
            break;
        }
        q.pop(), qd.pop();
        for(ll i : o[now])
        {
            if(vis[e[i].to][(nk + 1) % k] > max((e[i].a - d + k - 1) / k * k, vis[now][nk]))
            {
                q.push(e[i].to);
                qd.push(d + 1);
                vis[e[i].to][(nk + 1) % k] = max((e[i].a - d + k - 1) / k * k, vis[now][nk]);
            }
        }
    }
    cout << ans + vis[n][0] << endl;
    return 0;
}
