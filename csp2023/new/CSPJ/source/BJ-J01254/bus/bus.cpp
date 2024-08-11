#include <bits/stdc++.h>
using namespace std;

struct Road{
    int v, a;
};

struct Node{
    int v;
    long long cnt;
};

int n, m, k;
vector<Road> g[10005];
long long dis[10005];

long long bfs(){
    memset(dis, -1, sizeof(dis));
    queue <Node> q;
    q.push(Node{1, 0});
    dis[1] = 0;
    long long ans = INT_MAX;
    while(!q.empty()){
        Node fr = q.front(); q.pop();
        if(fr.v == n){
            ans = min(ans, dis[n]);
        }
        for(Road i : g[fr.v]){
            long long d = dis[fr.v]+1+max(0LL, i.a-fr.cnt-1);
            if(dis[i.v] == -1 || d < dis[i.v]){
                dis[i.v] = d;
                q.push(Node{i.v, d});
            }
        }
    }
    return ans;
}

int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int u, v, a;
        cin >> u >> v >> a;
        g[u].push_back(Road{v, a});
    }
    long long ans = bfs();
    ans += ans%k;
    cout << ans;
    return 0;
}