#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100002;

struct Edge
{
    int v,w;
    bool operator< (const Edge &t) const
    {
        if(w != t.w)
            return w < t.w;
        return v < t.v;
    }
};

int n,m,k;
set <Edge> s;
int dis[MAXN];
bool vis[MAXN];
vector <Edge> links[MAXN];

void Dijkstra(int src)
{
    memset(dis,0x3f,sizeof(dis));
    s.insert({src,0});
    dis[src] = 0;

    while(!s.empty())
    {
        auto top = *s.begin();
        s.erase(top);

        int u = top.v;
        if(vis[u])
            continue;
        vis[u] = true;

        auto &link = links[u];
        for(auto &cur : link)
        {
            int v = cur.v;
            int w = dis[u] + cur.w;
            if(dis[v] > w)
            {
                dis[v] = w;
                s.insert({v,dis[v]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    cin >> n >> m >> k;
    if(k != 1)
    {
        cout << -1 << endl;
        return 0;
    }

    for(register int i = 1;i <= m;i++)
    {
        int u,v,x;
        cin >> u >> v >> x;
        if(x != 0)
        {
            cout << -1 << endl;
            return 0;
        }
        
        links[u].push_back({v,1});
    }

    Dijkstra(1);
    cout << dis[n] + 1 << endl;
    
    return 0;
}