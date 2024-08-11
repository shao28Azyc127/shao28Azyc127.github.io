#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=100005;
int dp[1005][1005],dif[MAXN];
vector<pair<int,int> > vec[MAXN];

void solve1(){
    int n,m,k,d; cin>>n>>m>>k>>d;
    for(int i=1;i<=n;i++) vec[i].clear();
    for(int i=1;i<=m;i++){
        int x,y,z; cin>>x>>y>>z;
        vec[x].push_back(make_pair(y,z));
    }
    for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=-1e18;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0];
        for(int j=1;j<=min(i,k);j++){
            dp[i][j]=dp[i-1][j-1]-d;
            dp[i][0]=max(dp[i][0],dp[i-1][j]);
        }
        for(int j=0;j<=min(i,k);j++) dif[j]=0;
        for(pair<int,int> t:vec[i]){
            int x=t.first,w=t.second;
            dif[x]+=w;
        }
        int cur=0;
        for(int j=0;j<=min(i,k);j++) cur+=dif[j],dp[i][j]+=cur;
    }
    int res=0;
    for(int i=0;i<=k;i++) res=max(res,dp[n][i]);
    cout<<res<<'\n';
}

void solve3(){
    int n,m,k,d,res=0; cin>>n>>m>>k>>d;
    for(int i=1;i<=m;i++){
        int x,y,z; cin>>x>>y>>z;
        res+=max(0ll,z-y*d);
    }
    cout<<res<<'\n';
}

signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T; cin>>c>>T;
    if(c<=14) while(T--) solve1();
    else if(c==17 || c==18) while(T--) solve3();
    return 0;
}
