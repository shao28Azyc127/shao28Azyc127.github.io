#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e5+10;
struct Edge{int v,nxt;}e[MAXN<<1];
int tot,h[MAXN],x[MAXN],fa[MAXN],vis[MAXN],siz[MAXN],sum,fl;
int read(){
    int num=0,sign=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
    return num*sign;
}
void addEdge(int u,int v){
    e[++tot].v=v;
    e[tot].nxt=h[u];h[u]=tot;
}
int getfa(int u){
    if(u==fa[u]) return u;
    return fa[u]=getfa(fa[u]);
}
void unio(int u,int v){
    int fu=getfa(u),fv=getfa(v);
    if(fu!=fv) fa[fu]=fv,siz[fv]+=siz[fu];
}
void dfs(int u,int fu){
    sum+=siz[u];
    for(int k=h[u];k;k=e[k].nxt){
        int v=e[k].v;
        if(v==fu) continue;
        if(vis[v]!=0){fl|=(vis[v]==vis[u]);continue;}
        vis[v]=-vis[u];dfs(v,u);
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
int theid=read(),T=read();while(T--){
    int n=read(),m=read();
    memset(h,0,sizeof(h)),tot=0,memset(e,0,sizeof(e));
    for(int i=1;i<=n;i++) x[i]=i,fa[i]=i,vis[i]=0,siz[i]=1;
    while(m--){
        scanf("\n");char op=getchar();int u=read(),v;
        if(op=='+') v=read(),x[u]=x[v];
        if(op=='-') v=read(),x[u]=-x[v];
        if(op=='T') x[u]=n+1;
        if(op=='F') x[u]=-n-1;
        if(op=='U') x[u]=0;
    }
    for(int i=1;i<=n;i++)
        if(x[i]>0&&x[i]<=n) unio(i,x[i]);
    for(int i=1;i<=n;i++) fa[i]=getfa(i);
    for(int i=1;i<=n;i++){
        if(x[i]>0&&x[i]<=n) continue;
        if(x[i]>n||x[i]<-n) addEdge(fa[i],n+1),addEdge(n+1,fa[i]);
        else if(x[i]==0) addEdge(fa[i],0),addEdge(0,fa[i]);
        else addEdge(fa[i],fa[-x[i]]),addEdge(fa[-x[i]],fa[i]);
    }
    int ans=0;
    vis[n+1]=1;dfs(n+1,-1);
    sum=0;vis[0]=1;dfs(0,-1);ans+=sum;
    for(int i=1;i<=n;i++)
        if(fa[i]==i&&vis[i]==0)
            sum=0,fl=0,vis[i]=1,dfs(i,-1),ans+=sum*fl;
    printf("%d\n",ans);
}
    return 0;
}