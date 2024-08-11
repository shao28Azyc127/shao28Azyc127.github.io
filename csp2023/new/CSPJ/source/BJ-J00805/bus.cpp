#include<iostream>
#include<vector>
#include<cstdint>
using namespace std;

int n,m,k;
struct Edge{
    int next;
    int val;
};
vector<vector<Edge>>graph;

int ans=INT32_MAX;
void dfs(int x,int t){
    if(x==n){
        if(t%k==0){
            ans=min(ans,t);
        }
    }
    for(int i=0;i<graph[x].size();i++){
        if(graph[x][i].val<=t)dfs(graph[x][i].next,t+1);
        else dfs(graph[x][i].next,(graph[x][i].val-t+k-1)/k*k+t+1);
    }
}

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        graph[u].push_back(Edge{v,a});
    }

    // for(int i=0;i<100;i+=k){
        dfs(1,0);
    // }
    if(ans==INT32_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}