#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const long long inf=1e18+100000000;
int n;
vector <int> g[N];
long long a[N],b[N],c[N];
long long d[N];
__int128 calc(int x,long long t)
{
    if(c[x]>=0) return (__int128)t*b[x]+min((__int128)t*(t+1)/2,(__int128)a[x])*c[x];
    else
    {
        long long sep=(b[x]-1)/(-c[x]);
        if(t<=sep) return (__int128)t*b[x]+(__int128)t*(t+1)/2*c[x];
        __int128 now=(__int128)sep*b[x]+(__int128)sep*(sep+1)/2*c[x];
        return now+(t-sep);
    }
}
struct nd
{
    long long x;int id;
    bool operator <(const nd &b) const
    {
        return x<b.x;
    }
}hav[N];
int fa[N],vis[N];
void dfs(int x,int f)
{
    fa[x]=f;
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(v==f) continue;
        dfs(v,x);
    }
}
bool check(long long x)
{
    for(int i=1;i<=n;i++)
    {
        __int128 now=calc(i,x);
        if(now<a[i]) return false;
        long long l=1,r=x;
        while(l<r)
        {
            long long mid=(l+r+1)/2;
            //if(x<10) printf("%d:%lld:%lld %lld\n",i,mid,(long long)calc(i,x),(long long)calc(i,mid-1));
            if(now-calc(i,mid-1)<a[i]) r=mid-1;
            else l=mid;
        }
        d[i]=l;
        hav[i]=(nd){d[i],i};
    }
    /*
    if(x>10) return true;
    printf("%d:",x);
    for(int i=1;i<=n;i++) printf("%lld ",d[i]);
    printf("\n");
    */
    sort(hav+1,hav+n+1);
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    int now=0;
    for(int i=1;i<=n;i++)
    {
        int x=hav[i].id;
        int t=x;
        while(vis[t]==0) vis[t]=1,t=fa[t],now++;
        if(now>d[x]) return false;
    }
    return true;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    long long l=1,r=1000000000;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}
