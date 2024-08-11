#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans = INT_MAX;
struct node{
    int v,t;
};
vector<node> a[20001];
bool vis[20001];

void dfs(int u,int t){
    if(u == n){
        if(t%k == 0){
            ans = min(ans,t);
        }
        return ;
    }
    vis[u] = true;
    for(auto e:a[u]){
        if(vis[e.v] == false && t >= e.t){
            dfs(e.v,t+1);
        }
    }
    vis[u] = false;
    return ;
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,t;
    int maxt = 0;
    for(int i = 0;i < m;i++){
        cin>>u>>v>>t;
        a[u].push_back({v,t});
        maxt = max(maxt,t);
    }
    for(int i = 0;i <= maxt+k;i += k){
        dfs(1,i);
    }
    cout<<ans;
    return 0;
}
