#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n,m,k;
vector< pair<int,int> > G[10010];
bool vis[100010];
int one = 2e9;
int two = 2e9;
int ans = 2e9;
void dfs(int x, int l, int maxx){
    if(x == n){
        int tmp = min(ans, (int)(ceil(maxx / (double)(k)) * k + l));
        ans = tmp + (k - (tmp % k));
        one = min(one, l);
        two = min(two, maxx);
        return;
    }
    if(l > one && maxx > two){
        return;
    }
    vis[x] = true;
    for(int i = 0; i < G[x].size(); i ++){
        int to = G[x][i].first;
        int w = G[x][i].second;
        if(!vis[to]){
            dfs(to, l + 1, max(maxx, w - l));
            vis[to] = false;
        }
    }
}
int main (){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    int u,v,a;
    for(int i = 1; i <= m; i ++){
        cin >> u >> v >> a;
        G[u].push_back(make_pair(v, a));
    }
    dfs(1, 0, 0);
    if(ans == 2e9){
        cout << "-1";
    }
    else{
        cout << ans;
    }
    return 0;
}