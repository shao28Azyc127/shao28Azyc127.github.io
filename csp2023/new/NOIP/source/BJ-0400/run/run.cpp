#include<iostream>
using namespace std;
typedef long long ll;
const ll MAXN=30;
ll ans;
ll c,t;
ll n,m,k,d;
ll x[MAXN],y[MAXN],v[MAXN];
ll r[MAXN],f[MAXN];
void dfs(ll u){
    if(u==n+1){
        ll use=0;
        f[0]=0;
        ll na=0,tot=0;
        for(int i=1;i<=n;++i){
            f[i]=f[i-1]+r[i];
            if(r[i]==0){
                use=0;
            }else{
                tot++;
                use++;
                if(use>k){
                    return;
                }
            }
        }
        na=-tot*d;
        for(int i=1;i<=m;++i){
            ll R=x[i],l=x[i]-y[i]+1;
            if(f[x[i]]-f[l-1]==x[i]-l+1){
                na+=v[i];
            }
        }
        ans=max(ans,na);
        return;
    }
    r[u]=0;
    dfs(u+1);
    r[u]=1;
    dfs(u+1);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;++i){
            scanf("%lld%lld%lld",&x[i],&y[i],&v[i]);
        }
        ans=0;
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
