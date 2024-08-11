#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001],b[100001],c[100001];
vector<int> adj[100001];
int vis[100001];
int ans = INT_MAX;

void dfs(int t,int d,int maxl){
    int x = 0;
    for(int i = d;;i++){
        x += max(b[t]+i*c[t],1);
        if(x >= a[i]){
            x = i;
            break;
        }
    }
    x = max(x,maxl);
    if(d == n){
        ans = min(ans,x);
        return ;
    }
    for(auto v:adj[t]){
        if(vis[v] != 2){
            vis[v] = 1;
        }
    }
    for(int i = 1;i <= n;i++){
        if(vis[i] == 1){
            vis[i] = 2;
            dfs(i,d+1,x);
            vis[i] = 1;
        }
    }
    return ;
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int u,v;
    for(int i = 1;i < n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[1] = 2;
    dfs(1,1,0);
    cout<<ans;
    return 0;
}
