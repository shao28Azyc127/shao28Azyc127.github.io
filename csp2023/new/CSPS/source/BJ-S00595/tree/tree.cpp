#include<bits/stdc++.h>

using namespace std;

#define LL long long
const int NR=1e5+5;

int n;
LL a[NR],b[NR],c[NR];

struct Edge{
    int to,nxt;
}g[NR*2];
int fte[NR],gsz;

void addedge(int x,int y){
    g[++gsz]=(Edge){y,fte[x]};
    fte[x]=gsz;
}

long long ans;
int fa[NR],dis[NR];

void dfs(int x){
    for(int i=fte[x];i;i=g[i].nxt){
        int y=g[i].to;
        if(y==fa[x]) continue;
        fa[y]=x;
        dis[y]=dis[x]+1;
        dfs(y);
    }
}

void dfs2(int x){
    for(int i=fte[x];i;i=g[i].nxt){
        int y=g[i].to;
        if(y==fa[x]) continue;
        dis[y]=dis[x]+1;
        dfs2(y);
    }
}

int getpos(){
    int pos=0;
    for(int i=1;i<=n;i++){
        if(dis[i]&&(!pos||a[i]+dis[i]>a[pos]+dis[pos])) pos=i;
    }
    return pos;
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld%lld",a+i,b+i,c+i);
    for(int i=1;i<=n;i++) a[i]=(a[i]+b[i]-1ll)/b[i];
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    ans=a[1];
    dfs(1);
    for(int i=2;i<=n;i++){
        int x=getpos();
        while(dis[fa[x]]) x=fa[x];
        ans=max(ans,i-1ll+a[x]);
        dis[x]=0;
        dfs2(x);
    }
    printf("%lld\n",ans);
    return 0;
}