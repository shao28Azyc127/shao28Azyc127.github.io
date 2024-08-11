#include <bits/stdc++.h>
#define il inline
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=3e5+5;
int sid,T,n,m,k,d,ck1,ck2=1,b[N],cnt;ll dp[N][2],ans;
struct node{
    int l,r,v;
    il node(){l=r=v=0;}
}a[N];
ll tree[N<<2],tag[N<<2];
il void pushup(int x){tree[x]=max(tree[x<<1],tree[x<<1|1]);}
il void maketag(int x,ll w){tree[x]+=w,tag[x]+=w;}
il void pushdown(int x){
    if(tag[x]) maketag(x<<1,tag[x]),maketag(x<<1|1,tag[x]),tag[x]=0ll;
}
void build(int x,int l,int r){
    tree[x]=tag[x]=0ll;
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(x<<1,l,mid),build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int L,int R,ll w){
    if(l>=L && r<=R){maketag(x,w);return ;}
    int mid=(l+r)>>1;
    pushdown(x);
    if(L<=mid) update(x<<1,l,mid,L,R,w);
    if(R>mid) update(x<<1|1,mid+1,r,L,R,w);
    pushup(x);
}
ll query(int x,int l,int r,int L,int R){
    if(l>=L && r<=R) return tree[x];
    int mid=(l+r)>>1;
    pushdown(x);
    if(L>mid) return query(x<<1|1,mid+1,r,L,R);
    else if(R<=mid) return query(x<<1,l,mid,L,R);
    else return max(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
}
vector<pii> e[N];
int x,y,z;ll w;
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&sid,&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&k,&d);ck1=(k<=100),ck2=1,ans=0ll;
        for(int i=1;i<=m;++i) a[i].r=read(),x=read(),a[i].v=read(),a[i].l=a[i].r-x+1;
        for(int i=1;i<m;++i) ck2&=(a[i].r<a[i+1].l);
        if(ck2){
            for(int i=1;i<=m;++i){
                if(a[i].r-a[i].l+1>k) continue;
                w=1ll*a[i].v-1ll*d*(a[i].r-a[i].l+1ll);
                if(w>0) ans+=1ll*w;
            }
            printf("%lld\n",ans);continue;
        }
        cnt=0;b[++cnt]=0;
        for(int i=1;i<=m;++i){
            if(a[i].r-a[i].l+1>k) continue;
            b[++cnt]=a[i].r;
            if(a[i].r>=k) b[++cnt]=a[i].r-k;
            b[++cnt]=a[i].l-1;
        }
        sort(b+1,b+1+cnt);cnt=unique(b+1,b+1+cnt)-b-1;
        for(int i=1;i<=m;++i) a[i].l=lower_bound(b+1,b+1+cnt,a[i].l)-b,a[i].r=lower_bound(b+1,b+1+cnt,a[i].r)-b;
        for(int i=1;i<=cnt;++i) e[i].clear();
        for(int i=1;i<=m;++i) if(b[a[i].r]-b[a[i].l]+1<=k) e[a[i].r].push_back({a[i].l,a[i].v});
        build(1,0,cnt);
        for(int i=1;i<=cnt;++i){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]),dp[i][1]=-1ll*d;
            update(1,0,cnt,0,i-1,1ll*(b[i-1]-b[i])*d);
            for(auto it:e[i]) update(1,0,cnt,0,it.fi-1,1ll*it.se);
            x=lower_bound(b+1,b+1+cnt,b[i]-k)-b;
            if(x<i) dp[i][1]=query(1,0,cnt,max(0,x),i-1);
            update(1,0,cnt,i,i,dp[i][0]);
        }
        printf("%lld\n",max(dp[cnt][0],dp[cnt][1]));
    }
    return 0;
}
