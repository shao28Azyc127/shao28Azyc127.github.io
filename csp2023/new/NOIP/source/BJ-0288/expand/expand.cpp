#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repp(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
ll c,n,m,q,x[500005],y[500005];
vector<ll> bkx1,bkx2,bky1,bky2;
bool solve(){
    ll l=1,r=1;
    if(x[1]==y[1]) return 0;
    if((x[1]<y[1])^(x[n]<y[m])) return 0;
    if(x[1]<y[1]){
        rep(i,1,m){
            if(x[1]<y[i]) r=i;
            else break;
        }
        rep(i,2,n){
            if(x[i]<x[i-1]){
                rep(j,r+1,m){
                    if(x[i]<y[j]) r=j;
                    else break;
                }
            }
            else{
                ll tmp=r;
                r=0;
                repp(j,tmp,l) if(x[i]<y[j]){
                    r=j;
                    break;
                }
                rep(j,l,m) if(x[i]<y[j]){
                    l=j;
                    break;
                }
                if(!r) return 0;
            }
        }
    }
    else{
        rep(i,1,m){
            if(x[1]>y[i]) r=i;
            else break;
        }
        rep(i,2,n){
            if(x[i]>x[i-1]){
                rep(j,r+1,m){
                    if(x[i]>y[j]) r=j;
                    else break;
                }
            }
            else{
                ll tmp=r;
                r=0;
                repp(j,tmp,l) if(x[i]>y[j]){
                    r=j;
                    break;
                }
                rep(j,l,m) if(x[i]>y[j]){
                    l=j;
                    break;
                }
                if(!r) return 0;
            }
        }
    }
    return r==m;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
    rep(i,1,n) scanf("%lld",x+i);
    rep(i,1,m) scanf("%lld",y+i);
    printf("%lld",(ll)solve());
    while(q--){
        bkx1.clear();
        bkx2.clear();
        bky1.clear();
        bky2.clear();
        ll kx,ky;
        scanf("%lld%lld",&kx,&ky);
        rep(i,1,kx){
            ll p,v;
            scanf("%lld%lld",&p,&v);
            bkx1.pb(p);
            bkx2.pb(x[p]);
            x[p]=v;
        }
        rep(i,1,ky){
            ll p,v;
            scanf("%lld%lld",&p,&v);
            bky1.pb(p);
            bky2.pb(y[p]);
            y[p]=v;
        }
        printf("%lld",(ll)solve());
        rep(i,0,kx-1) x[bkx1[i]]=bkx2[i];
        rep(i,0,ky-1) y[bky1[i]]=bky2[i];
    }
    return 0;
}
