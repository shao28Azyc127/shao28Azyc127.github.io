#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int c,t,n,m,ans,fa[maxn],sz[maxn];
bool mark[maxn];
struct equal
{
    int x,y,z;
}a[maxn];
inline int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
    // cout<<x<<' '<<y<<endl;
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    if(sz[fx]>sz[fy]) swap(fx,fy);
    fa[fx]=fy;
    sz[fy]+=sz[fx];
}
void init()
{
    cin>>n>>m;
    ans=0;
    for(int i=1;i<=2*n;i++) 
    {
        fa[i]=i;
        sz[i]=1;
        mark[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        char v;
        int x,y;
        cin>>v>>x;
        if(v=='+')
        {
            mark[x]=0;
            cin>>y;
            merge(x,y);
            merge(x+n,y+n);
        }
        else if(v=='-')
        {
            mark[x]=0;
            cin>>y;
            merge(x,y+n);
            merge(x+n,y);
        }
        else
        {
            if(v=='U') mark[x]=1;
            else mark[x]=0;
        }
    } 
}
void work()
{
    for(int i=1;i<=n;i++)
    {
        if(mark[i]) mark[find(i)]=1;
    }
    // cout<<sz[find(1)]<<endl;
    for(int i=1;i<=n;i++)
    {
        int fi=find(i);
        if(fi==find(i+n)) 
        {
            sz[fi]--;
            mark[fi]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int fi=find(i);
        if(!mark[fi]) continue;
        // cout<<"test: "<<fi<<" "<<sz[fi]<<endl;
        ans+=sz[fi];
        sz[fi]=0;
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        init();
        work();
    }
    return 0;
}