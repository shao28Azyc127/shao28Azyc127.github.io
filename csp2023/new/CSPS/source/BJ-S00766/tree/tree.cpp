#include <algorithm>
#include <iostream>
#include <vector>

#define int long long

constexpr int N = 1e5 + 5;
using namespace std;

int a[N], b[N], c[N];
vector<int> g[N];
int n;

/*
void solve_chain() {
    for (int i = 1; i <= n; i++) {
        int temp = c[i] * (n + k) / 2 + b[i];
        int res = n -
        if (c[i] < 0) {

        }
    }
}
*/

int d[N];

int dfs(int x, int fa) {
    static vector<int> temp;
    temp.clear();
    int ret = d[x];
    for (auto i : g[x]) {
        if (i == fa)
            continue;
        temp.push_back(dfs(i, x));
    }
    sort(temp.begin(), temp.end(), greater<int>());
    for (int i = 0; i < temp.size(); i++)
        ret = max(ret, temp[i] + i + 1);
    return ret;
}

void solve_a() {
    for (int i = 1; i <= n; i++)
        if (a[i] % b[i] == 0)
            d[i] = a[i] / b[i];
        else
            d[i] = a[i] / b[i] + 1;
    cout << dfs(1, 0);
}

signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve_a();
    return 0;
}
