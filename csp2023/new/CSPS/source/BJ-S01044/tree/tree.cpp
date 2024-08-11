#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct Node
{
    long long a,b,c;
    int id;
    inline bool operator < (const Node &a)const
    {
        return c>a.c;
    }
}p[N];
struct Edge
{
    int v,nex;
}e[N<<1];
int head[N],ecnt;
inline void addedge(int u,int v)
{
    e[++ecnt]={v,head[u]};
    head[u]=ecnt;
}

priority_queue<Node>q;
int x=0;
inline long long calc(int id)
{
    int sum=0,t;
    long long a=p[id].a,b=p[id].b,c=p[id].c;
    for(t=x;;t++)
    {
        sum+=max(b+x*c,1ll);
        if(sum>=a)break;
    }
    return t;
}
bool flag[N];
long long ans=0;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&p[i].a,&p[i].b,&p[i].c);
        p[i].id=i;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    q.push(p[1]);
    flag[1]=1;
    while(!q.empty())
    {
        int u=q.top().id;
        q.pop();
        x++;
        ans=max(ans,calc(u));
        for(int it=head[u];it;it=e[it].nex)
        {
            int v=e[it].v;
            if(flag[v])continue;
            flag[v]=1;
            q.push(p[v]);
        }
    }
    printf("%lld",ans);
    return 0;
}
