#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int N,tot,h[100001];
long long ans,a[100001],b[100001],c[100001];
bool vis[100001];
struct Node
{
    int id;
    long long step;
    bool operator<(const Node &t)const
    {
        return step<t.step;
    }
}t,nt;
struct Edge
{
    int v,nxt;
}e[200001];
priority_queue<Node>q;
long long cal(long long x,long long y)
{
    if(!(x%y)) return x/y;
    return x/y+1;
}
void addedge(int u,int v)
{
    e[++tot].v=v;
    e[tot].nxt=h[u];
    h[u]=tot;
}
void bfs()
{
    t.id=1; t.step=cal(a[1],b[1]);
    vis[1]=1; q.push(t);
    int day=0;
    while(!q.empty())
    {
        day++;
        t=q.top(); q.pop();
        ans=max(ans,day+t.step-1);
        int u=t.id;
        cout<<u<<endl;
        for(int i=h[u];i;i=e[i].nxt)
            if(!vis[e[i].v])
            {
                nt.id=e[i].v;
                nt.step=cal(a[e[i].v],b[e[i].v]);
                q.push(nt);
                vis[e[i].v]=1;
            }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(int i=1;i<N;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v); addedge(v,u);
    }
    bool flag=0;
    for(int i=1;i<=N;i++)
        if(c[i]!=0) flag=1;
    if(!flag)
    {
        bfs();
        printf("%lld",ans);
    }
    return 0;
}