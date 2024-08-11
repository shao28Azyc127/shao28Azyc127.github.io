#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for (auto i=(a);i<=(b);++i)
#define per(i,a,b) for (auto i=(a);i>=(b);--i)

#define N int(1010)

int n,m,k,d;
ll dp[N][N];
vector<int> v[N];
vector<int> v0[N];

struct Node
{
    int x,y,z;
    bool operator<(const Node&o) const 
    {
        return x-y<o.x-o.y;
    }
}ms[N];

void work()
{
    memset(dp,-0x3f,sizeof dp);
    for (auto&v:(::v)) v.clear();
    cin>>n>>m>>k>>d;
    rep (i,1,m)
    {
        cin>>ms[i].x>>ms[i].y>>ms[i].z;
        v[ms[i].x].emplace_back(i);
    }
    rep (i,0,n) dp[i][0]=0;
    rep (i,1,n) 
    {
        ll mx=0;
        // dp[i][0]=dp[i-1][0];
        rep (j,1,k)
        {
            ll res=0;
            for (auto&p:v[i]) if (j>=ms[p].y) res+=ms[p].z;
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]-d+res);
            mx=max(mx,dp[i-1][j]);
            // cerr<<i<<','<<j<<": "<<dp[i-1][j]<<'\n';
        }
        dp[i][0]=max(mx,dp[i-1][0]);
        // cerr<<i<<','<<0<<": "<<dp[i][0]<<'\n';
    }
    ll ans=0;
    rep (i,0,k) ans=max(ans,dp[n][i]);
    cout<<ans<<'\n';
}

void work_10_11()
{
    memset(dp,-0x3f,sizeof dp);
    ll mn=dp[0][0];
    for (auto&v:(::v)) v.clear();
    cin>>n>>m>>k>>d;
    rep (i,1,m)
    {
        cin>>ms[i].x>>ms[i].y>>ms[i].z;
    }
    sort(ms+1,ms+1+m);
    rep (i,1,m) v[ms[i].x].emplace_back(i);
    rep (i,1,m) v0[ms[i].x-ms[i].y+1].emplace_back(i);
    dp[0][0]=0;
    rep (i,1,n)
    {
        ll mx=0;
        rep (j,0,m)
        {
            if (i-(ms[j].x-ms[j].y)>k) break;
            if (dp[i-1][j]!=mn)
            {
                dp[i][j]=dp[i-1][j]-d;
                if (i==ms[j].x) dp[i][j]+=ms[j].z;
                mx=max(mx,dp[i-1][j]);
            }
        }
        dp[i][0]=mx;
    }
    ll ans=0;
    rep (i,0,k) ans=max(ans,dp[n][i]);
    cout<<ans<<'\n';
}
void work_17_18()
{
    cin>>n>>m>>k>>d;
    int lst0=-1,lst1=-1;
    ll ans0=0,ans1=0;
    rep (i,1,m)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int l=x-y;
        if (l<=lst1)
        {
            if (x-lst0+1<=k) 
            {
                ans1=ans0=max(ans0,ans1);
                ans1=max(ans1,ans1-d*(x-lst1)+z);        
                lst1=x;
            }
            else
            {
                ll tmp=ans1;
                ans1=max(ans1,ans0-d*y+z);
                ans0=ans1;
                lst0=l+1;
                lst1=x;
            }
        }
        else
        {
            ans1=ans0=max(ans0,ans1);
            ans1=max(ans1,ans1-d*y+z);
            lst0=l+1;
            lst1=x;
        }
    }
    cout<<max(ans0,ans1)<<'\n';
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,t;
    cin>>c>>t;
    if (c==17||c==18) while (t--) work_17_18();
    else while (t--) work();
    return 0;
}
