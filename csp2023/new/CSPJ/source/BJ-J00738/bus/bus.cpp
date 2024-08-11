#include<bits/stdc++.h>
using namespace std;
vector<int> g[100005],a[100005];
int n,m,k,dis[100005];
bool arr[100005];
void bfs(){
    queue<int> q;
    q.push(1);
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(dis[v]!=-1||dis[u]+1<a[u][i])continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,x;
        cin>>u>>v>>x;
        g[u].push_back(v);
        a[u].push_back(x);
    }
    bfs();
    if(k==1)cout<<dis[n];
    else cout<<-1;
    return 0;
}
