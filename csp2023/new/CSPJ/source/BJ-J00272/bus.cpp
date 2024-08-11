#include<bits/stdc++.h>
using namespace std;
vector<int> bc[10005];
bool vis[10005];
long long ans1=1e18;
int n,m,k;
void dfs(int x,long long ans){
    if(vis[x])return;
    if(x==n){
        if(ans%k==0)
            ans1=min(ans1,ans);
        return;
    }
    vis[x]=1;
    for(int i=bc[x].size()-1;i>=0;i--)
        dfs(bc[x][i],ans+1);
    vis[x]=0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        bc[a].push_back(b);
        bc[b].push_back(a);
    }
    dfs(1,0);
    cout<<ans1;
    return 0;
}
