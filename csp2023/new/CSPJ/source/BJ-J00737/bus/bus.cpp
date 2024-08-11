#include<iostream>
#include<queue>
#include<vector>
#define ll long long
#define pll pair <long long, long long>
const ll inf = 1e18;
const ll maxn = 1e4 + 5;
using namespace std;
ll n, m, k, a, b, c, vis[maxn], d[maxn];
priority_queue <pll, vector <pll>, greater <pll>> q;
vector <pll> v[maxn];
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i = 1; i <= m; ++i){
        scanf("%lld%lld%lld", &a, &b, &c);
        v[a].push_back({b, c});
    }
    for(int i = 1; i <= n; ++i) d[i] = inf;
    q.push({0, 1});
    d[1] = 0;
    while(q.size()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < v[u].size(); ++i){
            int x = v[u][i].first;
            int w = v[u][i].second;
            if(d[x] > d[u] + w){
                d[x] = d[u] + w;
                q.push({d[x], x});
            }
        }
    }
    printf("%lld", d[n]);
    return 0;
}
