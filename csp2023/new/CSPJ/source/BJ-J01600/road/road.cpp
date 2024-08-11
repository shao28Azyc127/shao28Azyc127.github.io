#include <bits/stdc++.h>
using namespace std;
int v[100005],w[100005],s[100005];
int ans;
int n , k;
int rmb[100005];
int solve (int x) {
    //if (x == 1) return ans;
    for (int i = 1; i < x; i ++) {
       if (rmb[i]==0) rmb[i] = solve (i);
       ans = max(ans*1.0, rmb[i] + ceil((s[n] - s[i - 1]) * 1.0/ k) * w[i]);
    }
    return ans;
}
int main () {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> k;
    for (int i = 2; i <= n; i ++) cin >> v[i];
    for (int i = 1; i <= n; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + v[i];

    cout << solve (n + 1);
}
