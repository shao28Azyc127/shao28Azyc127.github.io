#include<bits/stdc++.h>

using namespace std;

const int NR=1e5+5;
#define LL long long

int n,m,K,D;

struct Que{
    int len,v;
}a[NR];
vector<int> q[NR];
int sz[NR],maxx[NR];

struct Node{
    LL d,tag;
}t[NR*2*4];

void build(int p,int l,int r){
    t[p].d=t[p].tag=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushdown(int p){
    if(!t[p].tag) return;
    t[p<<1].d+=t[p].tag;
    t[p<<1].tag+=t[p].tag;
    t[p<<1|1].d+=t[p].tag;
    t[p<<1|1].tag+=t[p].tag;
    t[p].tag=0;
}

void modify(int p,int l,int r,int ql,int qr,LL k){
    if(l==ql&&r==qr){
        t[p].d+=k;
        t[p].tag+=k;
        return;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if(qr<=mid) modify(p<<1,l,mid,ql,qr,k);
    else if(ql>mid) modify(p<<1|1,mid+1,r,ql,qr,k);
    else{
        modify(p<<1,l,mid,ql,mid,k);
        modify(p<<1|1,mid+1,r,mid+1,qr,k);
    }
    t[p].d=max(t[p<<1].d,t[p<<1|1].d);
}

LL query(int p,int l,int r,int ql,int qr){
    if(l==ql&&r==qr) return t[p].d;
    pushdown(p);
    int mid=(l+r)>>1;
    if(qr<=mid) return query(p<<1,l,mid,ql,qr);
    if(ql>mid) return query(p<<1|1,mid+1,r,ql,qr);
    return max(query(p<<1,l,mid,ql,mid),query(p<<1|1,mid+1,r,mid+1,qr));
}

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int C,T; scanf("%d%d",&C,&T);
    if(C==17||C==18){
        while(T--){
            scanf("%d%d%d%d",&n,&m,&K,&D);
            LL ans=0;
            for(int i=1;i<=m;i++){
                int x,y; LL v;
                scanf("%d%d%lld",&x,&y,&v);
                if(y<=K) ans+=max(0ll,v-1ll*D*y);
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
    while(T--){
        scanf("%d%d%d%d",&n,&m,&K,&D);
        for(int i=1;i<=n;i++) sz[i]=0;
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d%d%d",&x,&a[i].len,&a[i].v);
            if(a[i].len<=K){
                if(sz[x]>=maxx[x]){
                    q[x].push_back(i);
                    maxx[x]++;
                }
                else q[x][sz[x]]=i;
                sz[x]++;
            }
        }
        build(1,0,n+K);
        for(int i=1;i<=n;i++){
            modify(1,0,n+K,n-i,n-i,query(1,0,n+K,n-i+1,n-i+1+K));
            modify(1,0,n+K,n-i+1,n-i+K,-D);
            for(int j=0;j<sz[i];j++){
                int x=a[q[i][j]].len,v=a[q[i][j]].v;
                modify(1,0,n+K,n-i+x,n-i+K,v);
            }
        }
        printf("%lld\n",query(1,0,n+K,0,K));
    }
    return 0;
}