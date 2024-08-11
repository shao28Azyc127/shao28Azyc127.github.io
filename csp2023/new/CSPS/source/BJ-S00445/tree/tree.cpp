#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n;
ll a[N],b[N],c[N];
vector<ll> g[N];
ll ans=1e18;
ll sum[N];
bool op[N];
void dfs(ll x)
{
//    cout<<x<<endl;
    if(x>=ans) return;
    bool en=true;
    for(int i=1;i<=n;i++)
    {
        if(op[i])
        {
            sum[i]+=max(ll(1),b[i]+c[i]*x);
//            cout<<i<<" "<<sum[i]<<endl;
        }
        if(sum[i]<a[i])
        {
            en=false;
        }
    }
    if(en)
    {
        ans=min(ans,x);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(op[i]) continue;
        bool flag=0;
        for(int j=0;j<g[i].size();j++)
        {
            if(op[g[i][j]])
            {
//                cout<<1<<endl;
                flag=1;
                break;
            }
        }
        if(flag)
        {
            op[i]=1;
            dfs(x+1);
            op[i]=0;
        }
    }
    dfs(x+1);
    for(int i=1;i<=n;i++)
    {
        if(op[i])
        {
            sum[i]-=max(ll(1),b[i]+c[i]*x);
//            cout<<i<<" "<<sum[i]<<endl;
        }
    }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    memset(sum,0,sizeof(sum));
    memset(op,0,sizeof(op));
    for(int i=1;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    op[1]=1;
    dfs(2);
    cout<<ans-1<<endl;
    return 0;
}
