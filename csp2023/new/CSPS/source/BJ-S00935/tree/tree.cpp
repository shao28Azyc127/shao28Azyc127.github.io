#include<bits/stdc++.h>
#define ll long long
using namespace std;

const __int128 eps=1;

struct Node{int v,nt;};

struct node
{
    int u,d;
    node(int u,int d):u(u),d(d){}
    bool operator<(const node &tp)const{return d<tp.d;}
};

Node pl[200005];
int hd[100005],cnt;
int n,ans,l=1,r=1000000000;
ll a[100005];
int b[100005],c[100005],d[100005],e[100005],f[100005];
int g[100005],h[100005];
priority_queue<node> q;

inline void add(int u,int v)
{
    pl[++cnt].nt=hd[u];
    pl[cnt].v=v;
    hd[u]=cnt;
}

inline void dfs(int u,int fa)
{
    f[u]=fa;
    g[fa]++;

    for(int i=hd[u];i;i=pl[i].nt)
    {
        int v=pl[i].v;

        if(v==fa)
            continue;

        dfs(v,u);
    }
}

inline __int128 getsum(int i,int v)
{
    if(v<=d[i])
        return eps*((b[i]+c[i])+(b[i]+1LL*v*c[i]))*v/2;
    return v-d[i]+getsum(i,d[i]);
}

inline void getp(int i,int v)
{
    h[i]=g[i];

    e[i]=0;
    int ql=1,qr=v;

    while(ql<=qr)
    {
        int mid=(ql+qr)>>1;

        if(getsum(i,v)-getsum(i,mid-1)>=a[i])
            e[i]=mid,ql=mid+1;
        else
            qr=mid-1;
    }
}

inline bool check(int v)
{
    for(int i=1;i<=n;i++)
    {
        getp(i,v);
        if(e[i]<1)
            return 0;
    }

    for(int i=1;i<=n;i++)
    {
        if(h[i]==0)
            q.push(node(i,e[i]));
    }

    while(1)
    {
        int u=q.top().u;
        q.pop();

        v=min(v,e[u]);
        v--;

        if(u==1)
            return v>=0;

        h[f[u]]--;
        if(h[f[u]]==0)
            q.push(node(f[u],e[f[u]]));
    }
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        d[i]=1000000000;

        if(c[i]<0)
            d[i]=(b[i]-c[i]-2)/(-c[i])-1;
        d[i]=max(0,d[i]);
    }

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        add(u,v);
        add(v,u);
    }

    dfs(1,0);

    while(l<=r)
    {
        int mid=(l+r)>>1;

        if(check(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }

    cout<<ans<<'\n';

    return 0;
}
