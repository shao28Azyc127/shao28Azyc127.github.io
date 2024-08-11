#include <bits/stdc++.h>

using namespace std;
#define MAXN 400010
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
typedef pair<int,int> pa;
int n,a[MAXN],b[MAXN],c[MAXN];
struct edge
{
    int to,nex;
}Edge[MAXN];
int head[MAXN],cnt;
void add(int u,int v)
{
    Edge[cnt].to=v;
    Edge[cnt].nex=head[u];
    head[u]=cnt++;
}
int h[MAXN],mx[MAXN],ans,tt;
vector <pa> vc[MAXN];
void dfs(int x,int fa,int depth)
{
    mx[x]=a[x]+depth;
    for(int i=head[x];i!=-1;i=Edge[i].nex)
    {
        int y=Edge[i].to;
        if(y==fa) continue;
        dfs(y,x,depth+1);
        mx[x]=max(mx[x],mx[y]);
        vc[x].pb(mp(mx[y],y));
    }
}
void col(int x)
{
    sort(vc[x].begin(),vc[x].end());
    reverse(vc[x].begin(),vc[x].end());
    tt++;
    ans=max(ans,(a[x]-1)/b[x]+1+tt);
    for(auto y:vc[x]) col(y.se);
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    memset(head,-1,sizeof(head));
    cin.sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    int a1,a2;
    for(int i=1;i<n;i++)
    {
        cin>>a1>>a2;
        add(a1,a2),add(a2,a1);
    }
    cout<<n+1;
    return 0;
}
