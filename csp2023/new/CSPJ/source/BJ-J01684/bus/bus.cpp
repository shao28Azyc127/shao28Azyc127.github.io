#include<bits/stdc++.h>
using namespace std;
struct edge{
    int v,a;
};
vector<edge>adj[20005];
struct node{
    int pos,dis;
};
struct cmp{
    bool operator()(node a,node b){
        return a.dis>b.dis;
    }
};
bool vis[20005];
int dis[20005],u,v,c,n,m,k,ans=0x3f3f3f3f;
int dijkstra(int x){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<node,vector<node>,cmp>pq;
    dis[1]=x;
    pq.push(node{1,x});
    while(!pq.empty()){
        node t=pq.top();
        pq.pop();
        if(vis[t.pos]) continue;
        vis[t.pos]=1;
        for(int i=0;i<adj[t.pos].size();i++){
            if(dis[t.pos]-1<adj[t.pos][i].a) continue;
            if(dis[t.pos]+1<dis[adj[t.pos][i].v]){
                dis[adj[t.pos][i].v]=dis[t.pos]+1;
                pq.push(node{adj[t.pos][i].v,dis[adj[t.pos][i].v]});
            }
        }
    }
    return dis[n];
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>c;
        adj[u].push_back(edge{v,c});
    }
    int i=k;
    while(i<ans){
        ans=min(ans,dijkstra(i));
        //cout<<i<<" "<<ans<<" "<<dijkstra(i)<<endl;
        i+=k;
    }
    while(ans%k!=0) ans++;
    cout<<ans;
    return 0;
}