#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,m,k;
struct Node{
    int v,a;
};
struct E{
    int val,u;
    bool operator<(const E &__) const {
        return val>__.val;
    }
};
vector<Node> G[10010];
int dis[10010];
priority_queue<E> que;
int main(void) {
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1,u,v,a;i<=m;i++) {
        cin >> u >> v >> a;
        G[u].push_back(Node{v,a});
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1]=k;
    que.push(E{0,1});
    while (!que.empty()) {
        E d=que.top();
        que.pop();
        int u=d.u;
        for (int i=0;i<G[u].size();i++) {
            int v=G[u][i].v;
            if (dis[v]>max(dis[u],G[u][i].a)+1) {
                dis[v]=max(dis[u],G[u][i].a)+1;
                que.push(E{dis[v],v});
            }
        }
    }
    if (dis[n]==0x3f3f3f3f) {cout << "-1";return 0;}
    if (dis[n]%k==0) cout << dis[n];
    else cout << (dis[n]/k+1)*k;
    return 0;
}