#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int dis[10010];
bool book[10010];
struct node { int x,w; };
bool operator < (node s1,node s2) { return s1.w > s2.w; }
vector <node> v[10010];
priority_queue <node> pq;
void Dijkstra()
{
    memset(dis,0x3f,sizeof(dis));
    pq.push({1,0});
    dis[1] = 0;
    while(!pq.empty())
    {
        node st = pq.top();
        pq.pop();
        int x = st.x;
        if(book[x]) continue;
        book[x] = 1;
        for(int i = 0;i < v[x].size();++i)
        {
            int y = v[x][i].x,w = v[x][i].w;
            if(dis[y] > dis[x] + max(1,w - dis[x]))
            {
                dis[y] = dis[x] + max(1,w - dis[x]);
                pq.push({y,dis[y]});
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f) cout << -1;
    else cout << dis[n];
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back({y,w});
    }
    if(k != 1)
    {
        printf("-1");
        return 0;
    }
    Dijkstra();
    return 0;
}
