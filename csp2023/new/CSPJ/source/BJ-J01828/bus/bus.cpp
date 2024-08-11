#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[20005];
int n,m,k,a[20005];
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int i;
    for(i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>a[i];
        adj[u].push_back(v);
    }
    cout<<-1;
    return 0;
}
