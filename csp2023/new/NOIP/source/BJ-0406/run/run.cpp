#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const ll N=1e3+10;
struct Node{
    ll y,v;
    bool operator<(const Node &o)const{
        return y<o.y;
    }
};
vector<Node> adj[N];
ll dp[N][N];
void recieve(ll x){
    vector<Node> b;
    adj[x]=b;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ll c,t;
    scanf("%lld%lld",&c,&t);
    if(c==17||c==18){
        for(ll ct=1;ct<=t;ct++){
            ll n,m,k,d,tp=0;
            scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
            for(ll i=1;i<=m;i++){
                ll a,b,cc;
                scanf("%lld%lld%lld",&a,&b,&cc);
                tp+=max(cc-b*d,0ll);
            }
            printf("%lld\n",tp);
        }
    }else{
        for(ll ct=1;ct<=t;ct++){
            ll n,m,k,d,tp=0;
            scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
            for(ll i=1;i<=n;i++){
                recieve(i);
            }
            for(ll i=1;i<=m;i++){
                ll a,b,cc;
                scanf("%lld%lld%lld",&a,&b,&cc);
                adj[a].push_back({b,cc});
            }
            for(ll i=1;i<=n;i++){
                sort(adj[i].begin(),adj[i].end());
            }
            for(ll i=1;i<=n;i++){
                dp[i][0]=tp;
                ll p=0,siz=adj[i].size(),tp2=0;
                for(ll j=1;j<=k;j++){
                    while(p<siz&&adj[i][p].y<=j){
                        tp2+=adj[i][p++].v;
                    }
                    dp[i][j]=dp[i-1][j-1]-d+tp2;
                    tp=max(tp,dp[i][j]);
                }
            }
            printf("%lld\n",tp);
        }
    }
    return 0;
}
