#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll N=1e5+10,M=2e5+10;
ll fa[M],dis[M],a[N],tag[M],n,m,cnt;
ll tr[N],fl[N],val[M],nex[M],h[M];
bool vis[M];
ll f(ll x){
    if(x==-2) return -2;
    else if(x==-1) return 0;
    else if(x==0) return -1;
    else if(x<=n) return x+n;
    else return x-n;
}
ll cha(char x){
    if(x=='U') return -2;
    else if(x=='T') return -1;
    else return 0;
}
ll fin(ll x){
    if(x==fa[x]) return x;
    ll tp=fa[x];
    fa[x]=fin(fa[x]);
    dis[x]^=dis[tp];
    return fa[x];
}
void merg(ll x,ll y,ll d){
    ll fx=fin(x),fy=fin(y);
    if(fx==fy){
        if(abs(dis[x]-dis[y])!=d) tag[fin(x)]=1;
    }else{
        dis[fx]=abs(dis[y]+d-dis[x])%2;
        fa[fx]=fy,tag[fy]|=tag[fx],tag[fx]=0;
    }
}
void add_edge(ll u,ll v){
    val[++cnt]=v;
    nex[cnt]=h[u],h[u]=cnt;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ll c,t;
    scanf("%lld%lld",&c,&t);
    for(ll ct=1;ct<=t;ct++){
        scanf("%lld%lld",&n,&m);
        for(ll i=1;i<=n;i++) a[i]=i;
        for(ll i=1;i<=n<<1ll;i++){
        fa[i]=i,dis[i]=0,tag[i]=0,h[i]=0;}
        cnt=0;
        for(ll i=1;i<=m;i++){
            char op; cin>>op;
            ll x,y; scanf("%lld",&x);
            if(op=='+'||op=='-'){
                scanf("%lld",&y);
                a[x]=a[y];
                if(op=='-') a[x]=f(a[x]);
            }else{
                a[x]=cha(op);
            }
        }
        for(ll i=1;i<=n;i++) merg(i,i+n,1);
        ll tc=0,fc=0;
        for(ll i=1;i<=n;i++){
            if(a[i]==0) fl[++fc]=i;
            else if(a[i]==-1) tr[++tc]=i;
            else if(a[i]==-2) tag[fin(i)]=1;
            else merg(i,a[i],0);
        }
        for(ll i=1;i<tc;i++) merg(tr[i],tr[i+1],0);
        for(ll i=1;i<fc;i++) merg(fl[i],fl[i+1],0);
        if(min(tc,fc)>=1){
            for(ll i=1;i<=max(tc,fc);i++){
            merg(tr[min(i,tc)],fl[min(i,fc)],1);}}
        for(ll i=1;i<=n<<1ll;i++) add_edge(fin(i),i);
        ll ans=0;
        for(ll i=1;i<=n<<1ll;i++){
            if(tag[i]==1){
                for(ll j=h[i];j;j=nex[j]){
                    ans++;
                }
            }
        }
        ans>>=1ll;
        printf("%lld\n",ans);
    }
    return 0;
}
