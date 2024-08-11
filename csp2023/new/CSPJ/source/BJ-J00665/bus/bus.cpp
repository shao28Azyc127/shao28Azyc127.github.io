#include<bits/stdc++.h>
#define maxm 20005
using namespace std;
int n,m,k;
int g[maxm][maxm];
int ans;
void dfs(int p,int t){
    if(p==n){
        ans=max(t+k,ans);
    }
    for(int i=1;i<=n;i++){
        if(g[p][i]==-1||g[p][i]>t){
            continue;
        }
        dfs(i,t+1);
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        g[u][v]=a;
    }
    ans=k;
    dfs(1,0);
    if(ans<=k){
        cout<<-1;
        return 0;
    }
    if(ans%k!=0){
        ans=(ans/k+1)*k;
    }
    printf("%d",ans);
}
