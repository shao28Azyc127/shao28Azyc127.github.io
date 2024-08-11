#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=40010;
int n,m,k,ans=1e18;
struct Edge{
    int v,w,nx;
}edge[MAXN];
int h[MAXN],CNT;
void init(){
    memset(h,-1,sizeof(h));
    CNT=0;
}
void add_side(int u,int v,int w){
    edge[++CNT].v=v;
    edge[CNT].w=w;
    edge[CNT].nx=h[u];
    h[u]=CNT;
}
bool vis[MAXN];
void dfs(int now,int tiim,int sum){
    if(now==n){
        if(sum%k!=0)return;
        ans=min(ans,((tiim-1)/k+1)*k+sum);
        return;
    }
    for(int i=h[now];i!=-1;i=edge[i].nx){
        int v=edge[i].v,w=edge[i].w;
        if(!vis[v]){
            if(tiim+sum>=w){
                vis[v]=1;
                dfs(v,tiim,sum+1);
                vis[v]=0;
            }
            else{
                vis[v]=1;
                dfs(v,w-sum,sum+1);
                vis[v]=0;
            }
        }
    }
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    init();
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add_side(u,v,w);
    }
    dfs(1,0,0);
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//zycakioi