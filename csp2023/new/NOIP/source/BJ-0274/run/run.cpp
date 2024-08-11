// Power the hose !!!!
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll MXN=1010,MXM=1010;
typedef pair<ll,ll> pant;
ll x[MXM],y[MXM],v[MXM];
ll f[MXN][MXM];
vector<pant> pr[MXN];

void Solve()
{
    ll n,m,k,d;cin>>n>>m>>k>>d;
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=k;j++) f[i][j]=-1e18;
    for(ll i=1;i<=m;i++) cin>>x[i]>>y[i]>>v[i];
    for(ll i=1;i<=m;i++) pr[x[i]].push_back({y[i],v[i]});
    for(ll i=1;i<=n;i++) sort(pr[i].begin(),pr[i].end());
    f[0][0]=0;
    for(ll i=1;i<=n;i++)
    {
        ll pt=0,bns=0;
        for(ll j=1;j<=k;j++)
        {
            while(pt<pr[i].size()&&pr[i][pt].first<=j)
                bns+=pr[i][pt].second,pt++;
            f[i][j]=max(f[i][j],f[i-1][j-1]+bns-d);
            f[i][0]=max(f[i][0],f[i-1][j]);
        }f[i][0]=max(f[i][0],f[i-1][0]);
    }ll ret=-1e18;
    // for(ll i=1;i<=n;i++)
    // {
    //     for(ll j=0;j<=k;j++) cout<<f[i][j]<<' ';
    //     cout<<endl;
    // }
    for(ll i=0;i<=k;i++) ret=max(ret,f[n][i]);
    cout<<ret<<endl;
    for(ll i=1;i<=n;i++) pr[i].clear();return ;
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ll c,T;cin>>c>>T;
    while(T--) Solve();
    return 0;
}