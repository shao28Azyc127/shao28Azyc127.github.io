#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#define int long long
#define ull unsigned long long
using namespace std;
int n,m,k;
struct nodev{
    int to;
    int a;
};
vector<nodev>vec[10005];
struct nodeq{
    int to;
    int dis;
    bool operator < (const nodeq &a)const{
        return dis>a.dis;
    }
};
int dis[10005];
bool vis[10005];
void dijkstra(){
    for(int i=2;i<=n;i++)dis[i]=1e18;
    dis[1]=0;
    priority_queue<nodeq>q;
    q.push((nodeq){1,0});
    while(!q.empty()){
        int u=q.top().to;
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<vec[u].size();i++){
            int v=vec[u][i].to,w=1;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push((nodeq){v,dis[v]});
            }
        }
    }
}
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        vec[x].push_back((nodev){y,z});
    }
    dijkstra();
    if(dis[n]==1e18)puts("-1");
    else printf("%lld\n",ceil(dis[n]*1.0/k)*k);
    return 0;
}
