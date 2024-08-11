#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0x3f3f3f3f,maxn;
struct node{
    int v,w;
}a;
vector<node>v[1005];
void dfs(int step,int x,int fa){
    if(step>=k&&step%k==0&&x==n){
        ans=min(ans,step);
        return;
    }
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i].v;
        if(y==fa && step<v[x][i].w) continue;
        dfs(step+1,y,x);
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u;
        cin>>u>>a.v>>a.w;
        v[u].push_back(a);
        maxn=max(maxn,a.w);
    }
    for(int i=0;i<=maxn;i++){
        dfs(i,1,0);
    }
    if(ans==0x3f3f3f3f) cout<<-1;
    else cout<<ans;
    return 0;
}
