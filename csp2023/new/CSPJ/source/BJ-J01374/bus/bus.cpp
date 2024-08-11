/*
即使我变弱了，可不代表你变强了吧。
不好意思，这里前方可是一方通行啊！
*/

#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e4+10;
const int Maxm=2e4+10;
int n,m,k;
struct Edge{
    int to;
    int w;
    int nxt;
}E[Maxm<<1];
int head[Maxn],tot;
struct Path{
    int u,v,w;
};
vector<Path> vc;
void addedge(int u,int v,int w)
{
    tot++;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].nxt=head[u];
    head[u]=tot;
}
struct Nds{
    int u,now;
};
int dis[Maxn];
bool inque[Maxn];
void bfs(int u,int All,int nowtime)
{
    queue<Nds> q;
    for(int i=1;i<=All;i++)
    {
        dis[i]=0x3f3f3f3f;
        inque[i]=0;
    }
    dis[1]=nowtime;
    inque[1]=1;
    q.push((Nds){1,nowtime});
    while(!q.empty())
    {
        Nds fr=q.front();
        q.pop();
        int u=fr.u;
        inque[u]=0;
        int nowtime=fr.now;
        for(int i=head[u];i;i=E[i].nxt)
        {
            int v=E[i].to;
            int w=E[i].w;
            if(nowtime<w || dis[v]<dis[u]+1)
            {
                continue;
            }
            if(dis[u]+1<dis[v])
            {
                dis[v]=dis[u]+1;
                if(!inque[v])
                {
                    q.push((Nds){v,dis[v]});
                    inque[v]=1;
                }
            }
        }
    }
}/*
struct Node{
    int u,dist;
    bool operator<(const Node &rhs)const{
        return rhs.dist<dist;
    }
};
bool vis[Maxn];
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf,
    }
    priority_queue<Node> q;
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
    }
}*/
int makepoint(int N,int K)
{
    return n*K+N;
}
int check(int now)
{
    bfs(makepoint(1,0),makepoint(n,k-1),now);
    return dis[makepoint(n,0)];
}
vector<int> A;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        vc.push_back((Path){u,v,w});
        A.push_back(w);
    }

    if(n<=10)
    {
        for(auto i:vc)
        {
            int u=i.u,v=i.v,w=i.w;
            for(int p=0;p<k;p++)
            {
                addedge(makepoint(u,p),makepoint(v,(p+1)%k),w);
            }
        }

        int ans=0x3f3f3f3f;
        for(int i=0;i<A.size();i++)
        {
            int now=A[i];
            ans=min(ans,check(now));
        }
        if(ans==0x3f3f3f3f)
        {
            ans=-1;
        }
        printf("%d\n",ans);
    }else{
        puts("-1");
    }

    return 0;
}

