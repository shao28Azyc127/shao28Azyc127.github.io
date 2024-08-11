#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 9;
int n, a[N], b[N], c[N], u, v, allans = 0x3f3f3f3f;
vector<int> G[N];
bool vis[N];
void dfs(int x, int ans, int day) {
    int tmph = 0, tmpd = 0;
    while (tmph < a[x]) {
        tmph += max(b[x] + (day + tmpd) * c[x], 1);
        tmpd++;
    }
    tmpd--;
//    cout << "from day " << day << ", " << x << ", total = " << day + tmpd << endl;
    ans = max(ans, day + tmpd);
    if (day == n) {
        allans = min(allans, ans);
        return;
    }
    for (int i = 0; i < G[x].size(); ++i) {
        if (!vis[G[x][i]]) {
            vis[G[x][i]] = true;
            dfs(G[x][i], ans, day + 1);
            vis[G[x][i]] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0, 1);
    cout << allans;
//    if (n > 500) {
//        ans = n;
//        int tmp = 0;
//        for (int i = 1; i <= n; ++i) {
//            if (c[i]) {
//                int l = 0, r = 1e9;
//                while (l < r) {
//                    ll mid = (l + r) / 2;
//                    if (max((mid * (mid + 1) / 2 - i * (i - 1) / 2) * c[i] + mid * b[i], 1 * ) >= a[i]) {
//                        r = mid;
//                    } else {
//                        l = mid + 1;
//                    }
//                }
//                cout << i << ": " << l + i - 1 << endl;
//                ans = max(ans, l + i - 1);
//            } else if (c[i] == 0) {
//                ans = max(ans, (a[i] + b[i] - 1) / b[i] + i - 1);
//                cout << i << ": " << (a[i] + b[i] - 1) / b[i] + i - 1 << endl;
//            }
//        }
//        cout << ans;
//    }
    return 0;
}
