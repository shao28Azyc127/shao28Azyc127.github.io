#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
const int maxm=2010;
int head[maxn],tot,dis[maxn],vis[maxn],n,m,k;
struct node
{
    int u,v,val,next;
}e[maxn<<2];
void add(int u,int v,int val)
{
    tot++;
    e[tot].u=u;
    e[tot].v=v;
    e[tot].val=val;
    e[tot].next=head[u];
    head[u]=tot;
}
void finddis(int id)
{
    if(vis[id]==1) return ;
    vis[id]=1;
    for(int i=head[id];i;i=e[i].next)
    {
        int v=e[i].v;
        if(vis[v]==0) finddis(v);
        if(dis[id]>max(dis[v]+1,e[i].val)) dis[id]=max(dis[v]+1,e[i].val);
    }
    return ;
}
int main()
{
    freopen(stdin,"w",bus.in);
    freopen(stdout,"r",bus.out);
    cin>>n>>m>>k;
    for(int i=2;i<=n;i++) dis[i]=999999;
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        add(u,v,val);
    }
    finddis(1);
    int ans;
    if(dis[n]%k==0) ans=dis[n];
    else ans=(dis[n]/k+1)*k;
    cout<<k+ans<<endl;
    return 0;
}