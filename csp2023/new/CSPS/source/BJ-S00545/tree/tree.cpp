#include<bits/stdc++.h>
using namespace std;

int n,ans;
int a[200010],b[200010],c[200010],sum[200010];
int head[200010],nxt[200010],to[200010],cnt;
int vis[200010];

struct node
{
    int v,val;
    bool operator < (const node &nt){return val>nt.val;};
};

void add(int u,int v)
{
    nxt[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}

priority_queue <node> q;

void go()
{
    memset(sum,-1,sizeof(sum));
    q.push((node){1,b[1]});
    vis[1]=1;
    sum[1]=b[1];
    while(!q.empty())
    {
        for(int i=1;i<=n;i++)
            if(sum[i]!=-1)
                sum[i]+=b[i];
        int u=q.top().v;
        if(vis[u])
            continue;
        vis[u]=1;
        sum[u]=b[u];
        for(int i=head[u];i!=0;i=nxt[i])
        {
            int v=to[i];
            if(!vis[v])
                q.push((node){v,b[v]});
        }
    }
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n ;
    for(int i=1;i<=n;i++)
        cin >> a[i] >> b[i] >> c[i] ;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v ;
        add(u,v);
        add(v,u);
    }
    go();
    ans=n;
    bool flag=1;
    for(int i=1;i<=n;i++)
        if(sum[i]<a[i])
            flag=0;
    while(!flag)
    {
        ans++;
        for(int i=1;i<=n;i++)
            sum[i]+=b[i];
        flag=1;
        for(int i=1;i<=n;i++)
            if(sum[i]<a[i])
                flag=0;
    }
    cout << ans << endl ;
    return 0 ;
}
