#include<cstdio>
using namespace std;
int n,m,k,ans=2e9;
int g[int(1e4+5)][int(1e4+5)];
bool vis[int(1e4+5)];
int min(int a,int b){return a<b?a:b;}
void dfs(int x,int t){
    if(x==n){
        ans=min(ans,(t/k+(t%k==0?0:1))*k);
        return;
    }
    for(int i=1;i<=n;++i){
        if(g[x][i]==-1)continue;
        if(vis[i])continue;
        vis[i]=true;
        dfs(i,t+1);
        vis[i]=false;
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int u,v,l;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)g[i][j]=-1;
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&u,&v,&l);
        g[u][v]=l;
    }
    vis[1]=true;
    dfs(1,0);
    printf("%d",(ans==2e9?-1:ans));
    return 0;
}
