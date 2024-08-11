#include <bits/stdc++.h>
#define lowbit(x) (x&-x)
#define ll long long
using namespace std;
const int maxn=1e5+5;
const ll inf=1e18;
struct segment{
    int l,r,cov,tag;
}c[maxn<<2];
struct block{
    ll a,b,c;
    int id;
}a[maxn];
struct edge{
    int from,to,next;
}e[maxn<<1];
int n,now=1,tot,h[maxn],st[maxn];
int tim,dep[maxn],siz[maxn],son[maxn],fa[maxn],top[maxn],id[maxn];
inline void addEdge(int x,int y){
    e[++tot]=(edge){x,y,h[x]};
    h[x]=tot;
}
inline void dfs1(int x,int f,int d){
    fa[x]=f,dep[x]=d,siz[x]=1;
    int maxx=-1;
    for (int i=h[x];i;i=e[i].next){
        int v=e[i].to;
        if (v==f) continue;
        dfs1(v,x,d+1);
        siz[x]+=siz[v];
        if (siz[v]>maxx){
            maxx=siz[v];
            son[x]=v;
        }
    }
}
inline void dfs2(int x,int topf){
    id[x]=++tim,top[x]=topf;
    if (son[x]) dfs2(son[x],topf);
    for (int i=h[x];i;i=e[i].next){
        int v=e[i].to;
        if (v==son[x] || v==fa[x]) continue;
        dfs2(v,v);
    }
}
inline bool checkB(){
    for (int i=1;i<=tot;i++) if (abs(e[i].from-e[i].to)>1) return false;
    return true;
}
inline void solveB(){
    for (int i=1;i<=n;i++) st[i]=i;
    ll ans=0;
    for (int i=1;i<=n;i++){
        ll now=max(1ll,a[i].b+st[i]*a[i].c),p=st[i];
        while (now<a[i].a){
            p++;
            now+=max(1ll,a[i].b+p*a[i].c);
        }
        // printf("%d\n",p);
        ans=max(ans,p);
    }
    /*
    for (int i=1;i<=n;i++){
        ll lim=-a[i].b/a[i].c-st[i]+1;
        ll l=0,r=1e18;
        while (l<=r){
            ll sum=0,mid=(l+r)>>1;
            sum=a[i].b*min(mid,lim)+(st[i]*2ll+mid-1)/2*a[i].c+max(0ll,mid-lim);
            if (sum>=a[i].a) r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",l);
        ans=min(ans,l+st[i]-1);
    }
    */
    printf("%lld\n",ans);
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c),a[i].id=1;
    for (int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        addEdge(x,y);
        addEdge(y,x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    if (checkB()) solveB();
    printf("0\n");

    return 0;
}
