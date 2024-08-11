#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#define rep(i,n) for(int i=1;i<=n;++i)
#define int long long
#define pb push_back
using namespace std;
const int N=2e5+7;
int dp[N],n,m,r[N],v[N],k,p;
vector<int>ps[N];
void solve(){
    cin>>n>>m>>k>>p;int l;
    rep(i,m)scanf("%lld%lld%lld",&l,&r[i],&v[i]),ps[l-r[i]+1].pb(i),r[i]=l;
    int mx=0;
    for(int i=1;i<=n+1;++i){
        int jp=0;dp[i]=mx;
        for(int j=i-2;j>=max(i-k-1,0ll);--j){
            jp-=p;
            for(auto V:ps[j+1])
                if(r[V]<i)jp+=v[V];
            dp[i]=max(dp[i],dp[j]+jp);
//            if(i==3)cout<<j<<' '<<jp<<'\n';
        }
        mx=max(dp[i],mx);
    }
    cout<<mx<<'\n';mx=0;
    for(int i=1;i<=n+1;++i)dp[i]=0;
    rep(i,n)ps[i].clear();
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}

