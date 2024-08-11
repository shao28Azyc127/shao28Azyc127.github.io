#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=2e4+10;
ll n,m,k;
struct node{
    ll v,w;
};
vector<node> g[N];
ll a[N];
ll maxn=-1;
ll ans=1e18;
void dfs(ll x,ll y)
{
    if(x==n and y%k==0)
    {
        ans=min(ans,y);
        return;
    }
    if(y>=ans) return;
    for(ll i=0;i<g[x].size();i++)
    {
        ll u=x,v=g[x][i].v,w=a[g[x][i].w];
        if(w>y) continue;
        dfs(v,y+1);
    }
    return;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v>>a[i];
        g[u].push_back({v,i});
        maxn=max(maxn,a[i]);
    }
    for(ll i=0;i<=maxn+5;i+=3)
    {
        dfs(1,i);
    }
    if(ans==1e18) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
