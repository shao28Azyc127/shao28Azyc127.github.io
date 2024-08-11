#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k,u,v,a,ma[2005][2005],ans=-1,xn=-1;
bool b[2005][2005],vis[2005][2005];
void dfs(int t,int p){
    if(p==n){
        if(t%k==0){
            if(ans==-1)ans=t;
            else ans=min(ans,t);
        }
        return;
    }
    for(int i=1;i<=n;++i){
        if(b[p][i]&&ma[p][i]<=t&&!vis[p][i]){
            vis[p][i]=vis[i][p]=true;
            dfs(t+1,i);
            vis[p][i]=vis[i][p]=false;
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&u,&v,&a);
        ma[u][v]=ma[v][u]=a;
        b[u][v]=b[v][u]=true;
        xn=max(xn,a);
    }
    for(int i=0;i<=xn;++i){
        dfs(i,1);
    }
    printf("%d",ans);
    return 0;
}
