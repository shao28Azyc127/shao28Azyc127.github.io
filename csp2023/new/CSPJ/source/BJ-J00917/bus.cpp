#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e4+5,K=120,inf=2147483647;
struct node
{
    int v,next,tt;
}edge[M*2],edge2[M*2];
int cnt,head[N],n,m,k,dist[N],head2[N];
bool fl[N];
void add1(int x,int y,int tt)
{
    edge[++cnt]=(node){y,head[x],tt};
    head[x]=cnt;
}
void add2(int x,int y,int tt)
{
    edge2[++cnt]=(node){y,head2[x],tt};
    head2[x]=cnt;
}
priority_queue<pair<int,int> > p;
void dijkstra()
{
    for(int i=1;i<=n;i++) dist[i]=inf;
    dist[1]=0;
    p.push(make_pair(0,1));
    while(!p.empty())
    {
        int tmp=p.top().second;
        p.pop();
        fl[tmp]=1;
        for(int i=head2[tmp];i!=-1;i=edge2[i].next)
            if(dist[tmp]+1<dist[edge2[i].v])
            {
                dist[edge2[i].v]=dist[tmp]+1;
                if(!fl[edge2[i].v]) p.push(make_pair(-dist[edge2[i].v],edge2[i].v));
            }
    }
}
bool dfs(int x,int t)
{
    if(dist[x]>t) return false;
    if(x==1&&t%k==0) return true;
    if(t==0) return false;
    for(int i=head[x];i!=-1;i=edge[i].next)
        if(edge[i].tt<=t-1)
            if(dfs(edge[i].v,t-1))
                return true;
    return false;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(0);
    memset(head,-1,sizeof(head));
    memset(head2,-1,sizeof(head2));
    cin>>n>>m>>k;
    int maxx=-1;
    for(int i=1;i<=m;i++)
    {
        int x,y,a;
        cin>>x>>y>>a;
        add1(y,x,a);
        add2(x,y,a);
        maxx=max(maxx,a);
    }
    dijkstra();
    if(dist[n]==inf)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i*k<=n+maxx+5;i++)
        if(dfs(n,i*k))
        {
            cout<<i*k;
            return 0;
        }
    cout<<-1;
    return 0;
}

