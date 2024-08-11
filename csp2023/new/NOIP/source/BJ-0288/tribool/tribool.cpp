#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repp(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
ll c,t,n,m,val[200005],f[200005],siz[200005];
bool pd[200005],rev[200005],vis[200005];
vector<ll> v0,v1,v2;
ll find(ll x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(ll x,ll y){
    ll fx=find(x),fy=find(y);
    f[fy]=fx;
    return;
}
ll trans(ll x){
    if(x<=1) return x^1;
    return x;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        memset(pd,0,sizeof(pd));
        memset(val,0,sizeof(val));
        memset(rev,0,sizeof(rev));
        memset(f,0,sizeof(f));
        memset(siz,0,sizeof(siz));
        memset(vis,0,sizeof(vis));
        rep(i,1,n) val[i]=i;
        rep(i,1,m){
            char c;
            cin>>c;
            if(c=='T'){
                ll x;
                scanf("%lld",&x);
                pd[x]=1;
                val[x]=1;
                rev[x]=0;
            }
            else if(c=='F'){
                ll x;
                scanf("%lld",&x);
                pd[x]=1;
                val[x]=0;
                rev[x]=0;
            }
            else if(c=='U'){
                ll x;
                scanf("%lld",&x);
                pd[x]=1;
                val[x]=2;
                rev[x]=0;
            }
            else if(c=='+'){
                ll x,y;
                scanf("%lld%lld",&x,&y);
                if(x==y) continue;
                if(pd[y]){
                    pd[x]=1;
                    val[x]=val[y];
                    rev[x]=0;
                }
                else{
                    pd[x]=0;
                    val[x]=val[y];
                    rev[x]=rev[y];
                }
            }
            else{
                ll x,y;
                scanf("%lld%lld",&x,&y);
                if(x==y){
                    if(pd[x]) val[x]=trans(val[x]);
                    else rev[x]^=1;
                    continue;
                }
                if(pd[y]){
                    pd[x]=1;
                    val[x]=trans(val[y]);
                    rev[x]=0;
                }
                else{
                    pd[x]=0;
                    val[x]=val[y];
                    rev[x]=rev[y]^1;
                }
            }
        }
        rep(i,1,2*n) f[i]=i;
        v0.clear();
        v1.clear();
        v2.clear();
        //rep(i,1,n) printf("%lld %lld\n",pd[i],val[i]);
        rep(i,1,n){
            if(pd[i]==1){
                if(!val[i]){
                    v0.pb(i);
                    v1.pb(i+n);
                }
                if(val[i]==1){
                    v0.pb(i+n);
                    v1.pb(i);
                }
                if(val[i]==2){
                    v2.pb(i);
                    v2.pb(i+n);
                }
            }
            else{
                if(!rev[i]){
                    merge(i,val[i]);
                    merge(i+n,val[i]+n);
                }
                else{
                    merge(i,val[i]+n);
                    merge(i+n,val[i]);
                }
            }
        }
        if(v0.size()>1) rep(i,1,v0.size()-1) merge(v0[i],v0[i-1]);
        if(v1.size()>1) rep(i,1,v1.size()-1) merge(v1[i],v1[i-1]);
        if(v2.size()>1) rep(i,1,v2.size()-1) merge(v2[i],v2[i-1]);
        rep(i,1,n) ++siz[find(i)];
        ll ans=0;
        if(!v2.empty()){
            ans=siz[find(v2[0])];
            vis[find(v2[0])]=1;
        }
        rep(i,1,n){
            ll x=find(i),y=find(i+n);
            if(x==y&&!vis[x]){
                vis[x]=1;
                ans+=siz[x];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
