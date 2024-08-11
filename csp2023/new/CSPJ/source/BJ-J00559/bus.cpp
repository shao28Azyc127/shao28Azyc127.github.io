#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e4+5,maxk=1e2+5;
typedef long long ll;
struct edge
{
    int to,a;
};
struct node
{
    int x,y;
    ll dis;
    friend bool operator<(node a,node b)
    {
        return a.dis>b.dis;
    }
};
vector<edge> G[maxn];
ll dis[maxn][maxk];
bool vis[maxn][maxk];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    int in,im,ik;
    cin>>in>>im>>ik;
    for(int v1=1;v1<=im;v1++)
    {
        int iu,iv,ia;
        scanf("%d %d %d",&iu,&iv,&ia);
        G[iu].push_back({iv,ia});
    }
    dis[1][0]=0;
    priority_queue<node> pq;
    pq.push({1,0,0});
    while(!pq.empty())
    {
        int curx=pq.top().x,cury=pq.top().y;
        pq.pop();
        if(vis[curx][cury])continue;
        vis[curx][cury]=true;
        for(int v1=0;v1<G[curx].size();v1++)
        {
            int curson=G[curx][v1].to,cura=G[curx][v1].a;
            ll ndis=dis[curx][cury]+1;
            if(dis[curx][cury]<cura)ndis+=cura-dis[curx][cury]+(ik-(cura-dis[curx][cury])%ik)%ik;
            int ny=ndis%ik;
            if(dis[curson][ny]>ndis)
            {
                dis[curson][ny]=ndis;
                pq.push({curson,ny,ndis});
            }
        }
    }
    if(vis[in][0])printf("%lld\n",dis[in][0]);
    else printf("-1\n");
    return 0;
}
