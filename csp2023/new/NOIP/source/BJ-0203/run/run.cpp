#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int N=1005,M=1e5+5;
ll c,t;
ll n,m,k,d;
ll sum[N][N];
ll dp[N][2];
ll l[M],r[M],v[M];
ll ask(int x,int y,int xx,int yy) {
    return sum[xx][yy]-sum[xx][y-1]-sum[x-1][yy]+sum[x-1][y-1];
}
ll calc(int l,int r) {
    if(r-l+1<=k)
    return ask(l,l,r,r)-(r-l+1)*d;
    else return 0;
}
int main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--) {
        cin>>n>>m>>k>>d;
        rep(i,1,n) rep(j,1,n) sum[i][j]=0;
        //ll now=0;
        rep(i,1,m) {
            ll x,y,w;
            cin>>x>>y>>w;
            //l[i]=x-y+1,r[i]=x,v[i]=w;
            sum[x-y+1][x]+=w;
            //if(x-(x-y+1)+1<=k)
            //now+=w;
        }
        //cout<<now<<endl;
        rep(i,1,n) rep(j,1,n) sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        //rep(j,1,n) rep(i,1,n) sum[i][j]+=sum[i-1][j];
        //rep(i,1,n) {
        //    rep(j,1,n) cout<<sum[i][j]<<' ';
        //    cout<<endl;
        //}
        //cout<<endl;
        rep(i,1,n) rep(j,0,1) dp[i][j]=0;
        rep(i,1,n) {
            per(j,i,1) dp[i][1]=max(dp[i][1],dp[j-1][0]+calc(j,i)),dp[i][0]=max(dp[i][0],max(dp[j-1][1],dp[j-1][0]));
        }

        //print();
        ll ans=0;
        rep(i,1,n) rep(j,0,1) ans=max(ans,dp[i][j]);
        cout<<ans<<endl;
    }
    return 0;
}
