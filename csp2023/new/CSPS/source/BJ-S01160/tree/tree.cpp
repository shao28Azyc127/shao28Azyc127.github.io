#include<bits/stdc++.h>
using namespace std;
#define int long long
struct point{
    int id,a,b,c,t;
}dat[100005];
struct cmp{
    bool operator()(point a,point b){
        return a.t<b.t;
    }
};
vector<point>adj[100005];
int x,ans,n,u,v;
bool vis[100005];
void bfs(){
    priority_queue<point,vector<point>,cmp>pq;
    pq.push(dat[1]);
    vis[1]=1;
    while(!pq.empty()){
        point t=pq.top();
        pq.pop();
        x++;
        ans=max(ans,x+t.t);
        for(int i=0;i<adj[t.id].size();i++)
            if(!vis[adj[t.id][i].id]) pq.push(adj[t.id][i]),vis[adj[t.id][i].id]=1;
    }
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dat[i].a>>dat[i].b>>dat[i].c;
        dat[i].id=i;
        dat[i].t=ceil(dat[i].a/(dat[i].b*1.0));
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(dat[v]);
        adj[v].push_back(dat[u]);
    }
    bfs();
    cout<<ans;
    return 0;
}