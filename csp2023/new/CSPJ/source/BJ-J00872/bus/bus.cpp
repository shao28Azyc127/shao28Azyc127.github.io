#include<bits/stdc++.h>
//ru guo gai shi jian he yuan lai shi jian dui k qumo de jie guo xiang otng zhi jie kacha
// vis[]biao shi di ci lai zhe ge dian de shijian
using namespace std;
int n, m, k, ans = 2e9;
vector<int> g[10005], a[10005];
int vis[10005];
struct node
{
    int u, x;
};
queue<node> q;/*
void dfs(int u, int x)
{
//    printf("u=%d   x=%d\n", u, x);
    if(x >= ans) return ;
    if(u == n)
    {
        if(x % k == 0) ans = max(ans, x);
        return ;
    }
    for(int i = 0; i < g[u].size(); i++)
        if(a[u][i] >= x && vis[g[u][i]] == -1)
        {
            printf("u=%d   v=%d\n", u, g[u][i]);
            vis[g[u][i]] = 1;
            dfs(g[u][i], x + 1);
            vis[g[u][i]] = -1;
        }
//    for(int i = 0; i < g[u].size(); i++)
//        if(a[u][i] >= x && vis[g[u][i]] == 1)
//        {
//            vis[g[u][i]] = 1;
//            dfs(g[u][i], x + 1);
//            vis[g[u][i]] = -1;
//        }
    return ;
}*/
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    bool kai = true, wu = true;
    int mp = 0;
    for(int i = 1; i <= m; i++)
    {
        int u, v, ai;
        scanf("%d %d %d", &u, &v, &ai);
        if(u >= v) wu = false;
        g[u].push_back(v);
        a[u].push_back(ai);
        mp = max(mp, ai);
        if(ai != 0) kai = false;
    }
    if(k == 1 && kai == true)
    {
        q.push(node{1, 0});
        vis[1] = 1;
        while(!q.empty())
        {
            int u = q.front().u, x = q.front().x;
            q.pop();
            if(u == n)
            {
                printf("%d\n", x);
                return 0;
            }
            for(int i = 0; i < g[u].size(); i++)
            {
                int v = g[u][i];
                if(vis[v] == 1) continue;
                vis[v] = 1;
                q.push(node{v, x + 1});
            }
        }
        printf("-1\n");
        return 0;
    }
    if(wu == true)
    {
        for(int i = 0; i <= mp; i += k)
        {
            q.push(node{1, i});
    //        memset(vis, 0, sizeof(vis));
      //      vis[1] = 1;
            while(!q.empty())
            {
                int u = q.front().u, x = q.front().x;
                q.pop();
                if(u == n)
                {
                    if(x % k == 0)
                    {

                        printf("%d\n", x);
                        return 0;
                    }
                }
                for(int i = 0; i < g[u].size(); i++)
                {
                    int v = g[u][i];
 //                   if(vis[v] == 1) continue;
                    if(x < a[u][i]) continue;
 //                   vis[v] = 1;
                    q.push(node{v, x + 1});
                }
            }
        }
        printf("-1\n");
        return 0;
    }
/*    memset(vis, -1, sizeof(vis));
    for(int i = 0; max(k - 1, mp); i++)
        vis[1] = 1, dfs(1, i);
    printf("%d\n", ans);*/
    return 0;
}
