# include <bits/stdc++.h>
using namespace std;
long long t;
long long n,m,k,d;
struct node{
    long long x,y;
};
string jsjs(node ls){
    string lsls = to_string(ls.x)+" "+to_string(ls.y);
    return lsls;
}
map <string,long long> tt;
long long js = 1;
long long dp[100005];
long long jl[100005];
void init(){
    memset(dp,sizeof(dp),0);
    tt.clear();
    js = 1;
    memset(jl,sizeof(jl),0);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    long long c;
    cin>>c>>t;
    while(t--){
        init();
        cin>>n>>m>>k>>d;
        dp[0] = 0;
        dp[1] = 0-d;
        for(long long i=0;i<m;i++){
            node ls;
            long long vv;
            cin>>ls.x>>ls.y>>vv;
            if(tt[jsjs(ls)]>0) jl[tt[jsjs(ls)]] = max(vv,jl[tt[jsjs(ls)]]);
            else{
                tt[jsjs(ls)] = js;
                jl[js] = vv;
                js++;
            }
        }
        for(long long i=2;i<=n;i++){
            long long maxn = dp[0];
            for(long long j=0;j<=k&&j<=i-1;j++){
                maxn = max(maxn,dp[j]);
            }
            for(long long j=min(k,i);j>=1;j--){
                dp[j] = dp[j-1] - d;
                node ls = {i,j};
                long long bh = tt[jsjs(ls)];
                if(bh>0) dp[j] += jl[bh];
            }
            dp[0] = maxn;
        }
        long long maxn = dp[0];
        for(long long j=0;j<=k&&j<=n;j++){
            maxn = max(maxn,dp[j]);
        }
        cout<<maxn<<"\n";
    }
    return 0;
}
