#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
};
node c[1000005][205];
int b[1000005],f[20005],n,m,k,ans=1e9;
void dfs(int p,int t){
    if(t>=ans) return;
    if(p==n){
        if(t%k==0) ans=min(ans,t);
        return;
    }
    for(int i=1;i<=b[t];i++){
        if(f[c[t][i].y]==0&&c[t][i].x==p){
            f[c[t][i].y]=1;
            dfs(c[t][i].y,t+1);
            f[c[t][i].y]=0;
        }
    }
}
int main(){
    freopen("bus.in","r","stdin");
    freopen("bus.out","w","stdout");
    cin>>n>>m>>k;
    int cnt=0,ax=0;
    for(int i=1;i<=m;i++){
        int u,v,aa;
        cin>>u>>v>>aa;
        ax=max(ax,aa);
        b[aa]++;
        c[aa][b[aa]].x=u;
        c[aa][b[aa]].y=v;
    }
    for(int j=0;j<=ax;j++){
        dfs(1,j);
    }
    if(ans!=1e9)cout<<ans;
    else cout<<-1;
    return 0;
}