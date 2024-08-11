#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
int n,dt,a[N],b[N],c[N],x[N],dep[N],siz[N],son[N],dfn[N],top[N],fa[N],tag[N];
vector<int> v[N],vv[N];
void dfs(int p,int f){
    dep[p]=dep[f]+1,siz[p]=1,fa[p]=f;
    for(int u:v[p]){
        if(u==f) continue;
        dfs(u,p);
        siz[p]+=siz[u];
        if(siz[u]>siz[son[p]]) son[p]=u;
    }
}
void dfs2(int p,int tp){
    top[p]=tp,dfn[p]=++dt;
    if(son[p]) dfs2(son[p],tp);
    for(int u:v[p]) if(u!=fa[p]&&u!=son[p]) dfs2(u,u);
}
int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    } return dep[x]<dep[y]?x:y;
}
__int128 calc(int b,int c,int x){
    __int128 d,t,s;
    if(c<0){
        d=b/(-c);
        if(b%c==0) d--;
    }else d=x;
    t=min((__int128)x,d);
    s=t*b+c*(1+t)*t/2;
    return s+x-t;
}
int cng(int x){
    int s=0,tg;
    while(x){
        tg=tag[top[x]];
        if(!tg) s+=dep[x]-dep[top[x]]+1,tag[top[x]]=x;
        else{
            if(dep[tg]<=dep[x]) s+=dep[x]-dep[tg],tag[top[x]]=x;
            break;
        } x=fa[top[x]];
    } return s;
}
bool chk(int mid){
    for(int i=1;i<=n;++i) vv[i].clear(),tag[i]=0;
    __int128 s;
    for(int i=1,l,r,md;i<=n;++i){
        s=calc(b[i],c[i],mid);
        if(s<a[i]) return 0;
        x[i]=l=1,r=mid;
        while(l<=r){
            md=(l+r)>>1;
            if(s-calc(b[i],c[i],md)>=a[i]) l=md+1,x[i]=md+1;
            else r=md-1;
        }
        if(x[i]<=n) vv[x[i]].push_back(i);
    }
    for(int i=1,s=0;i<=n;++i){
        for(int u:vv[i]) s+=cng(u);
        if(s>i) return 0;
    } return 1;
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i]>>b[i]>>c[i];
    for(int i=1,x,y;i<n;++i) cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
    dfs(1,0);
    dfs2(1,1);
    int l=0,r=1e9,mid,ans=1e9;
    while(l<=r){
        mid=(l+r)>>1;
        if(chk(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    } cout<<ans;
}
