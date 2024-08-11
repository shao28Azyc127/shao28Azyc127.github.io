#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int g[1005][1005];
int n,m,k;
int mn=2e9;
void dfs(int u,int ti){
    if(u==m){
        if(ti%k==0){
            mn=min(mn,ti);
        }
        return;
    }
    for(int i=1;i<=m;i++){
        if(g[u][i]==0xc0) continue;
        dfs(i,ti+1);
    }
}
int main(){
    freopen("bus.in","w",stdin);
    freopen("bus.out","r",stdout);
    cin>>n>>m>>k;
    memset(g,0xc0,sizeof(g));
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        g[u][v]=a;
    }
    dfs(1,0);
    cout<<mn;
    return 0;
}
