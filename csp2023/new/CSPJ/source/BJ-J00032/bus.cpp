#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 2e4 + 5;

int n, m, k, ans = 1e9;
bool vis[maxn], flag = true;
struct Edge
{
    int v, a;
};

struct Bus
{
    int u, t;
};

vector<Edge> g[maxm];
queue<Bus> q;

void bfs()
{
    while(!q.empty())
    {
        Bus pre = q.front();
        q.pop();
        int t = pre.t, u = pre.u;
        //cout << "t:" << t << " u:" << u << endl;
        if(u == n && t % k == 0)
        {
            cout << t;
            return ;
        }
        else if(u == n)
        {
            continue;
        }
        for(int i = 0;i < g[u].size();i ++)
        {
            if(g[u][i].a <= t && !vis[g[u][i].v])
            {
                q.push((Bus){g[u][i].v, t + 1});
            }

        }
    }
    cout << -1;
    return ;
}

void visbfs()
{
    while(!q.empty())
    {
        Bus pre = q.front();
        q.pop();
        int t = pre.t, u = pre.u;
        //cout << "t:" << t << " u:" << u << endl;
        if(u == n && t % k == 0)
        {
            cout << t;
            return ;
        }
        else if(u == n)
        {
            continue;
        }
        for(int i = 0;i < g[u].size();i ++)
        {
            if(g[u][i].a <= t && !vis[g[u][i].v])
            {
                q.push((Bus){g[u][i].v, t + 1});
                vis[g[u][i].v] = true;
            }

        }
    }
    cout << -1;
    return ;
}

void dfs(int u, int t)
{
    if(u == n && t % n == 0)
    {
        ans = min(ans, t);
        return ;
    }
    else if(u == n)
        return ;
    for(int i = 0;i < g[u].size();i ++)
    {
        if(g[u][i].a <= t && !vis[g[u][i].v])
        {
            vis[g[u][i].v] = true;
            dfs(g[u][i].v, t + 1);
            vis[g[u][i].v] = false;
        }

    }
}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    if(k != 1)
        flag = false;
    int late;
    for(int i = 1;i <= m;i ++)
    {
        int x, y, z;
        if(z != 0)
            flag = false;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back((Edge){y, z});
        late = max(late, z);
    }
    if(flag)
    {
        for(int i = 0;i <= late + k;i += k){
        q.push({1, i});
    }
    visbfs();
    }
    else{
    for(int i = 0;i <= late + k;i += k){
        q.push({1, i});
    }
    bfs();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
