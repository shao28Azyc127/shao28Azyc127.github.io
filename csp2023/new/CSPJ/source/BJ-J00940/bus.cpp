#include <bits/stdc++.h>
#define MAXN 10000
#define ll long long


using namespace std;

int n,m,k;
vector<int> e[MAXN+5];
ll ans=LONG_MAX;
int ok=0;
int vis[MAXN+5];

void dfs(int p,ll len){
    if(p==n&&len%k==0){
        ans=len;
        ok=1;
        return;
    }
    if(p==n){return;}
    if(len>ans) return;
    for(int i=0;i<e[p].size();i++){
        if(vis[e[p][i]]==1)continue;
        vis[p]=1;
        dfs(e[p][i],len+1);
        vis[p]=0;
    }
}

int main(){

    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back(v);
    }
    dfs(1,0);
    if(ok==0) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
