#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
vector<pair<int,int> > es[10005],ies[10005];
bool vis[10005][105];
void dfs1(int x,int d){
    if(vis[x][d%k]) return;
    vis[x][d%k]=1;
    for(auto p:ies[x]){
        dfs1(p.first,d+1);
    }
}
ll Ceil(ll a,int b){
    if(a%b==0) return a/b;
    return a/b+1;
}
ll dis2[10005][105];
bool vis2[10005][105];
void dijkstra(){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({0,1});
    dis2[1][0]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(vis2[u][d%k]) continue;
        vis2[u][d%k]=1;
        for(auto p:es[u]){
            ll nd=d+1;
            if(d<p.second) nd+=max(Ceil(p.second-d,k),0ll)*k;
            if(nd<dis2[p.first][nd%k]){
                dis2[p.first][nd%k]=nd;
                pq.push({nd,p.first});
            }
        }
    }
}
int main(){
    #ifndef JZQ
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    #endif
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        es[u].push_back({v,a});
        ies[v].push_back({u,a});
    }
    dfs1(n,0);
    memset(dis2,0x3f,sizeof(dis2));
    dijkstra();
    if(dis2[n][0]==0x3f3f3f3f3f3f3f3f) printf("-1");
    else printf("%lld",dis2[n][0]);
    return 0;
}