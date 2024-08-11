#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> ed[100010];
bool f[100010];
int ans = INT_MAX;
void dfs(int u, int step){
    f[u] = true;
    for(auto v : ed[u]){
        //cout << v  << ' ' << u << ' ' << step << endl;
        if(v == n){
                //cout << step << endl;
            if((step+1) % k == 0){
                ans = min(step+1, ans);
            }
            return;
        }
        if(!f[v])
            dfs(v, step+1);
    }
    f[u] = false;
}
int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        ed[u].push_back(v);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}
