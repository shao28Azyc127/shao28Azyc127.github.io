#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n , m , k , dis[10005] , vis[10005] , maxn[10005];
vector<int> v[10005] , w[10005];

void spfa()
{
    queue<int> q;
    q.push(1);
    for (int i = 2; i <= n; i++)
    {
        dis[i] = 1e9;
        maxn[i] = 0;
        vis[i] = 0;
    }
    dis[1] = 0;
    vis[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i];
            maxn[y] = max(maxn[y] , (maxn[x] , w[x][i]));
            int now = dis[x] - maxn[x] + maxn[y] + 1;
            if (now < dis[y])
            {
                dis[y] = now;
                if (!vis[y])
                {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
    freopen("bus.in" , "r" , stdin);
    freopen("bus.out" , "w" , stdout);
    scanf("%d%d%d" , &n , &m , &k);
    for (int i = 1; i <= m; i++)
    {
        int a , b , c;
        scanf("%d%d%d" , &a , &b , &c);
        v[a].push_back(b);
        w[a].push_back(c);
    }
    spfa();
    printf("%d" , dis[n]);

    return 0;
}
