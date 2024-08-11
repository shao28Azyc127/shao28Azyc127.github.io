#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 9;
const int M = 1e5 + 9;
long long c, t, n, m, k, d, ans = 0;
struct Node {long long x, y, v;} a[M];
int run[N];  // just for test point <= 14
long long check() {
//    for(int i=1;i<=n;++i)cout<<run[i]<<" ";cout<<endl;
    long long ret = 0;
    for (int i = 1; i <= m; ++i) {
        if (run[a[i].x] - run[a[i].x-a[i].y] == a[i].y) {
            ret += a[i].v;
        }
    }
//    cout << ret << endl;
    return ret;
}
void dfs(int x, int combo, long long eng) {
    if (x > n) {
        ans = max(ans, eng + check());
        return;
    }
    if (combo < k) {
        run[x] = run[x - 1] + 1;
        dfs(x + 1, combo + 1, eng - d);
    }
    run[x] = run[x - 1];
    dfs(x + 1, 0, eng);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        ans = 0;
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= m; ++i) {
            cin >> a[i].x >> a[i].y >> a[i].v;
        }
        if (c == 1 || c == 2) {
            dfs(1, 0, 0);
            cout << ans << endl;
        } else if (c == 17 || c == 18) {
            for (int i = 1; i <= m; ++i) {
                if (a[i].y <= k) {
                    ans += max(0LL, a[i].v - d * a[i].y);
                }
            }
            cout << ans << endl;
        } else {
            dfs(1, 0, 0);
            cout << ans << endl;
        }
    }
    return 0;
}
