#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
struct Node{
    int id,w;
};
vector<Node> ve[MAXN];
int n,m,k,dis[MAXN],vis[MAXN],ans=0x3f3f3f3f;
void dfs(int x,int len,int Max){
    if(x==n){
        if(len%k==0){
            ans=min(ans,(int)ceil(1.0*Max/k)*k+len);
        }
        return;
    }
    vis[x]=1;
    for(int i=0;i<ve[x].size();i++){
        int y=ve[x][i].id,a=ve[x][i].w;
        if(!vis[y])
            dfs(y,len+1,max(Max,a-len));
    }
    vis[x]=0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        ve[u].push_back((Node){v,a});
        ve[v].push_back((Node){u,a});
    }
    dfs(1,0,0);
    printf("%d",ans);
    return 0;
}
