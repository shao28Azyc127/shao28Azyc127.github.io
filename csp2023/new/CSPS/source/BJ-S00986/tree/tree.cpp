#include <bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
il ll get(ll x,ll y){return x/y+(x%y==0);}
const int N=1e5+5;const ll inf=1e9;
int n,ck1=1,ck2=1,vis[N];ll a[N],b[N],c[N],t[N],ans=inf;
vector<int> e[N],f[N];
il void add(int x,int y){e[x].push_back(y);}
/*il int ck(ll v){
    for(int i=1;i<=n;++i) t[i]=v-get(a[i],b[i]),vis[i]=0,f[i].clear();
    for(int i=1;i<=n;++i) if(t[i]<=0ll) return 0;
    vis[1]=1;ll cur=0;
    for(int i=1;i<=n;++i){
        if(t[i]<n) f[t[i]].push_back(i);
        else f[n].push_back(i);
    }
    sort(f[n].begin(),f[n].end(),[](int x,int y){return t[x]<t[y];});
    for(int i=1;i<=n;++i){
        for(int x:f[i]){

        }
    }
}*/
il ll calc(ll s,ll t,ll b,ll c){
    if(c==0) return b*(t-s+1ll);
    else if(c>0){
        return (s+t)*(t-s+1ll)/2ll*c+(t-s+1ll)*b;
    }
    else{
        ll p=(1-b)/c;
        if(p<s) return (t-s+1ll);
        else if(p>t) return (s+t)*(t-s+1ll)/2ll*c+(t-s+1ll)*b;
        else return (s+p-1ll)*(p-s)/2ll*c+(p-s)*b+(t-p+1ll);
    }
}
int d[N],m;
il ll get(){
    ll cur,l,r,mid,ret=0;
    //for(int i=1;i<=n;++i) printf("%d ",d[i]);puts("");
    for(int i=1;i<=n;++i){
        cur=0ll,l=0,r=inf;
        while(l<=r){
            mid=(l+r)>>1;
            if(calc(i,mid,b[d[i]],c[d[i]])>=a[d[i]]) cur=mid,r=mid-1;
            else l=mid+1;
        }
        ret=max(ret,cur);
        //printf("%lld ",cur);
    }
    //puts("");
    return ret;
}
void dfs(int x,int fath){
    if(clock()>950000){printf("%lld",ans);exit(0);}
    int f[200],id[200],z=0,u;d[++m]=x;
    if(m==n) ans=min(ans,get());
    for(int y:e[x]) if(y!=fath) f[++z]=y,id[z]=z;
    do{
        u=m;
        for(int i=1;i<=z;++i) d[++m]=f[id[i]],dfs(f[id[i]],x);
        m=u;
    }while(next_permutation(id+1,id+1+z));
    --m;
}
int x,y;
ll l,r,mid,cur;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]),ck1&=(c[i]==1);
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y),add(x,y),add(y,x);
        ck2&=(x==i && y==i+1);
    }
    if(ck2){
        ans=0ll;
        for(int i=1;i<=n;++i){
            cur=0ll,l=0,r=inf;
            while(l<=r){
                mid=(l+r)>>1;
                if(calc(i,mid,b[i],c[i])>=a[i]) cur=mid,r=mid-1;
                else l=mid+1;
            }
            ans=max(ans,cur);
        }
        printf("%lld",ans);
        return 0;
    }
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}
