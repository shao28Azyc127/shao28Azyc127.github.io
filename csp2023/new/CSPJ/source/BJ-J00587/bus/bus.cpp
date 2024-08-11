#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans=0x3f;
int dt[10002][10002];
int a[10002];
int vis[10002];
void dfs(int x,int sum){
    if(x==n){
        if(sum%k==0){
            ans=min(ans,sum);
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(dt[x][i]==0 || vis[i]==1 || sum<a[i]){
            continue;
        }
        else{
            vis[i]=1;
            dfs(i,sum+1);
            vis[i]=0;
        }

    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=1;
        cin>>a[i];
    }
    dfs(1,0);
    if(ans==0x3f){
        cout<<-1;
    }else{
        cout<<ans;
    }
    return 0;
}
