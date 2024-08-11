#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n, m, k, t[maxn], mxa, ans = 2e8;
vector<pair<int, int>> pass[maxn];
bool isvisited[maxn];
void dfs(int x, int deep) {
    if (t[x] < deep && t[x] != -1) return;
    t[x] = deep;
    if (x == n) return;
    for (auto u : pass[x]) {
        int next = u.first, time = u.second;
        if (!isvisited[next] && deep >= time){
            isvisited[x] = true;
            dfs(next, deep + 1);
            isvisited[x] = false;
        }
    }
}
int main() {
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        pass[u].push_back({v, a});
        mxa = max(a, mxa);
    }
    for (int i = 1; i <= max((mxa + k - 1) / k, 1); i++){
        memset(t, -1, sizeof(t));
        dfs(1, i * k);
        ans = min(ans, (t[n] + k - 1) / k * k);
    } 

    //for (int i = 1; i <= n; i++) cout << t[i] << " ";
    //cout << endl;
    cout << ans << endl;
    return 0;
}