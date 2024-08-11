#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,x,y) for(LL i=(x);i<=(y);i++)
#define per(i,x,y) for(LL i=(x);i>=(y);i--)
#define all(x) x.begin(),x.end()
#define vi vector<LL>
#define pb push_back
#define pii pair<LL,LL>
#define fi first
#define se second
#define mp make_pair
LL c,T,N,M,K,D,dp[114514];
vector<pii >clg[114514];//fi:y se:v
void solve0(){
    dp[0]=0;
    cin>>N>>M>>K>>D;rep(i,1,N)clg[i].clear(),dp[i]=-0x3f3f3f3f3f3f3f3f;
    rep(i,1,M){
        LL x,y,v;cin>>x>>y>>v;
        clg[x].pb(mp(y,v));
    }
    rep(i,1,N)sort(all(clg[i]));
    rep(i,1,N){
        LL g=0;
        per(j,min(i,K),1)g=max(g,dp[j]),dp[j]=dp[j-1]-D;dp[0]=max(dp[0],g);
        LL k=0,sn=0;
        rep(j,1,min(i,K)){
            while(k<clg[i].size()&&j>=clg[i][k].fi)sn+=clg[i][k++].se;
            dp[j]+=sn;
        }
    }
    LL ans=0;rep(i,0,K)ans=max(ans,dp[i]);cout<<ans<<'\n';
    return ;
}
struct node{
    LL l,r,v;
}clgs[114514];
bool cmp(node x,node y){return x.l<y.l;}
void solveB(){
    cin>>N>>M>>K>>D;
    rep(i,1,M){
        cin>>clgs[i].r>>clgs[i].l>>clgs[i].v;clgs[i].l=clgs[i].r-clgs[i].l+1;
    }
    LL ans=0;
    rep(i,1,M){
        if(D*(clgs[i].r-clgs[i].l+1)<clgs[i].v)ans+=clgs[i].v-D*(clgs[i].r-clgs[i].l+1);
    }
    cout<<ans<<'\n';
    return ;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("run.in","r",stdin);freopen("run.out","w",stdout);
    cin>>c>>T;
    while(T--){
        if(c<=9)solve0();
        if(17<=c&&c<=18)solveB();
    }
    return 0;
}
//Remember me.
