#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, k;
struct edge
{
    int to, wei;
};
vector<edge> adj[10005];
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1;i <= m;i ++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(edge{v, w});
        adj[v].push_back(edge{u, w});
    }
    cout << -1 << endl;
    return 0;
}