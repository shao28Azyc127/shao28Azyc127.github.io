

#include <iostream>
#include <vector>
#include <queue>

#define int long long
#define endl '\n'

using namespace std;

const int MAXI = 1e5 + 9;
int n, a[MAXI], b[MAXI], c[MAXI];
int u, v;
vector<int> G[MAXI];

int day, ans;

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i], sum += a[i];
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }

    cout << sum << endl;

    return 0;
}
