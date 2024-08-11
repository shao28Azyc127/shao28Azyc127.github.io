#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repp(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
ll c,t,n,m,k,d,x[100005],y[100005],v[100005],qz[1005],dp[1005][1005];
vector<pair<ll,ll> > V[100005];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    ll tmp=t;
    while(t--){
        memset(qz,0,sizeof(qz));
        memset(dp,0,sizeof(dp));
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        rep(i,1,m){
            scanf("%lld%lld%lld",x+i,y+i,v+i);
            V[x[i]].pb(mp(y[i],v[i]));
        }
        rep(i,1,n){
            rep(j,0,min(i-1ll,k)) dp[i][0]=max(dp[i][0],dp[i-1][j]);
            memset(qz,0,sizeof(qz));
            if(!V[i].empty()) rep(j,0,V[i].size()-1) qz[V[i][j].first]+=V[i][j].second;
            rep(j,1,k) qz[j]+=qz[j-1];
            rep(j,1,min(1ll*i,k)) dp[i][j]=dp[i-1][j-1]+qz[j]-d;
        }
        ll mx=0;
        rep(i,0,k) mx=max(mx,dp[n][i]);
        printf("%lld\n",mx);
        rep(i,1,m) V[x[i]].clear();
    }
    return 0;
}
