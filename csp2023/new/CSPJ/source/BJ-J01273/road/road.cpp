#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int n;
typedef long long ll;
ll d, dis[maxn], cost[maxn], ans;
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> dis[i];
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 1; i < n; i++) {
        int j = i;
        ll dissum = 0;
        for (; j < n; j++) {
            if (cost[j] >= cost[i]) {
                dissum += dis[j];
            }
            else break;
        }
        ans += ((dissum - 1) / d + 1) * cost[i];
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}
