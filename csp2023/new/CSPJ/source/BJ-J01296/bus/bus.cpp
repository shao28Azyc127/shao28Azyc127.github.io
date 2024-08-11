#include<bits/stdc++.h>

using namespace std;

long long n, m, k, ans = LLONG_MAX, vis[10005];

struct edge
{
    long long end, a;
};

vector<edge> graph[10005];

void dfs(long long id, long long time)
{
    if(id == n)
    {
        if(time % k == 0)
        {
            ans = min(ans, time);
        }
        return;
    }
    for(long long i = 0; i < graph[id].size(); i++)
    {
        if(!vis[graph[id][i].end] && time >= graph[id][i].a)
        {
            vis[graph[id][i].end] = 1;
            dfs(graph[id][i].end, time + 1);
            vis[graph[id][i].end] = 0;
        }
    }

}

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for(long long i = 1; i <= n; i++)
    {
        long long u, v, a;
        scanf("%lld%lld%lld", &u, &v, &a);
        graph[u].push_back({v, a});
    }
    dfs(1, k);
    printf("%lld", ans);

    return 0;
}