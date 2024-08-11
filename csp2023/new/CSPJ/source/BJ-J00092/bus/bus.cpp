#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 2e4 + 5, inf = 1e10;
int n, m, k, dp[N], head[N], nxt[N], to[N], tot, a[N], d[N], cnt, fst[N];
bool vis[N];
void add(int u, int v){
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
}
queue<int>q;
void bfs(){
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        d[++cnt] = u;
        for(int i = head[u];i;i = nxt[i]){
            int v = to[i];
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}
void solve2(){
    for(int i = 1;i <= n;i++)fst[i] = inf;
    fst[1] = 0;
    for(int i = 1;i <= cnt;i++){
        int u = d[i];
        for(int j = head[u];j;j = nxt[j]){
            int v = to[j];
            fst[v] = min(fst[v], max(fst[u] + 1, a[j] + 1));
        }
    }
    cout << fst[n];
}
signed main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool flag = 0;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v >> a[i];
        if(u > v)flag = 1;
        add(u, v);
    }
//    bfs();
    if(!vis[n]){
        cout << -1;
        return 0;
    }
    if(k == 1){
        solve2();
    }else{
        cout << -1;
    }
    return 0;
}
