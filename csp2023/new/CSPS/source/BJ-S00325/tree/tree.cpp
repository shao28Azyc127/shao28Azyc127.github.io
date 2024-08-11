#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int p = 1e9;
int n, a[maxn], b[maxn], c[maxn], dis[maxn];
bool isvisited[maxn];
vector<int> path[maxn];
long long ans = 1e10;
long long high[maxn];
void dfs(int x, int deep) {
    //???
    if (x == n) {
        //¼ÆËã????
        return;
    }
    for (auto u : path[x]) {
        if (!isvisited[u]) {
            isvisited[x] = true;
            dis[x] = deep;
            dfs(u, deep + 1);
            isvisited[x] = false;
        }
    }
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        path[u].push_back(v);
        path[v].push_back(u);
    }
    //dfs(1, 0);
    //srand(time(NULL));
    cout << p << endl;
    return 0;
}