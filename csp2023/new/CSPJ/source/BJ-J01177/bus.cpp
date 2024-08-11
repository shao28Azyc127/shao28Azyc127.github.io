#include<bits/stdc++.h>
using namespace std;
int n,m,k,d[10010];
vector<int> g[10010];
queue<int> q;
void bfs(int x){
    q.push(x);
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<g[i].size();i++){
            int v=g[u][i];
            if(d[v]==-1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(b);
    }
    memset(d,-1,sizeof d);
    d[1]=0;
    bfs(1);
    cout<<d[n];
    return 0;
}
